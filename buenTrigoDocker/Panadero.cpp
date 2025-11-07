#include "Panadero.h"
#include "VistaPanadero.h"
#include "ControladorRecetas.h"
#include "ControladorProduccion.h"
#include <iostream>
#include <memory>

using namespace std;

Panadero::Panadero(string nombre, string password, 
                   ControladorRecetas* cr, ControladorProduccion* cp)
    : Usuario(nombre, "panadero", password), 
      controladorRecetas(cr), controladorProduccion(cp) {
      }

void Panadero::mostrarMenu() {
    VistaPanadero vista;
    int opcion;
    
    do {
        vista.mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                registrarReceta();
                break;
            case 2:
                modificarReceta();
                break;
            case 3:
                eliminarReceta();
                break;
            case 4:
                registrarProduccion();
                break;
            case 5:
                consultarStockPanes();
                break;
            case 6:
                vista.mostrarRecetas(controladorRecetas->getRecetas());
                break;
            case 7:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                vista.mostrarMensaje("Opción inválida. Intente nuevamente.");
        }
        
        // Limpiar buffer de entrada
        if (opcion != 7) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 7);
}

void Panadero::registrarReceta() {
    VistaPanadero vista;
    auto datos = vista.solicitarDatosReceta();
    string nombrePan = get<0>(datos);
    map<string, double> ingredientesMap = get<1>(datos); // separa los datos 
    
    Receta* nuevaReceta = controladorRecetas->crearReceta(nombrePan);
    if (nuevaReceta != nullptr) {
        vista.mostrarMensaje("Receta '" + nombrePan + "' registrada exitosamente.");
    } else {
        vista.mostrarMensaje("Error: Ya existe una receta con ese nombre.");
    }
}

void Panadero::modificarReceta() {
    VistaPanadero vista;
    auto recetas = controladorRecetas->getRecetas();
    
    if (recetas.empty()) {
        vista.mostrarMensaje("No hay recetas para modificar.");
        return;
    }
    
    vista.mostrarRecetasParaSeleccion(recetas);
    int seleccion = vista.solicitarSeleccionReceta(recetas.size());
    
    // Solicitar nuevo nombre para la receta
    string nuevoNombre;
    cout << "Nuevo nombre para la receta (actual: " << recetas[seleccion]->getNombrePan() << "): ";
    cin.ignore();
    getline(cin, nuevoNombre);
    
    if (controladorRecetas->modificarReceta(recetas[seleccion], nuevoNombre)) {
        vista.mostrarMensaje("Receta modificada exitosamente.");
    } else {
        vista.mostrarMensaje("Error al modificar la receta.");
    }
}

void Panadero::eliminarReceta() {
    VistaPanadero vista;
    auto recetas = controladorRecetas->getRecetas();
    
    if (recetas.empty()) {
        vista.mostrarMensaje("No hay recetas para eliminar.");
        return;
    }
    
    vista.mostrarRecetasParaSeleccion(recetas);
    int seleccion = vista.solicitarSeleccionReceta(recetas.size());
    
    vista.mostrarConfirmacionEliminacion(recetas[seleccion]->getNombrePan());
    char confirmacion;
    cin >> confirmacion;
    
    if (confirmacion == 's' || confirmacion == 'S') {
        if (controladorRecetas->eliminarReceta(recetas[seleccion])) {
            vista.mostrarMensaje("Receta eliminada exitosamente.");
        } else {
            vista.mostrarMensaje("Error al eliminar la receta.");
        }
    } else {
        vista.mostrarMensaje("Eliminación cancelada.");
    }
}

void Panadero::registrarProduccion() {
    VistaPanadero vista;
    
    // Mostrar recetas disponibles primero
    auto recetas = controladorRecetas->getRecetas();
    if (recetas.empty()) {
        vista.mostrarMensaje("No hay recetas registradas. Registre una receta primero.");
        return;
    }
    
    vista.mostrarRecetasParaSeleccion(recetas);
    int seleccion = vista.solicitarSeleccionReceta(recetas.size());
    Receta* receta = recetas[seleccion];
    
    int cantidad;
    cout << "Cantidad de panes a producir: ";
    cin >> cantidad;
    
    if (cantidad <= 0) {
        vista.mostrarMensaje("Error: La cantidad debe ser mayor a 0.");
        return;
    }
    
    bool exito = controladorProduccion->producirPan(receta, cantidad);
    vista.mostrarResultadoProduccion(exito);
}

void Panadero::consultarStockPanes() {
    VistaPanadero vista;
    auto panes = controladorProduccion->getStockPanes();
    
    vector<tuple<string, int>> stock;
    for (auto pan : panes) {
        stock.push_back(make_tuple(pan->getTipo(), pan->getCantidad()));
    }
    
    vista.mostrarStockPanes(stock);
}