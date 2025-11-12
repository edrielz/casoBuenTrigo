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
    
    Receta* nuevaReceta = controladorRecetas->crearReceta(nombrePan, ingredientesMap);
    if (nuevaReceta != nullptr) {
        vista.mostrarMensaje("Receta '" + nombrePan + "' registrada exitosamente.");
    } else {
        vista.mostrarMensaje("Error: Ya existe una receta con ese nombre o los ingredientes no existen.");
    }
}

void Panadero::modificarReceta() {
    // Permite seleccionar una receta y modificar su nombre e ingredientes.
    VistaPanadero vista;
    auto recetas = controladorRecetas->getRecetas();
    
    if (recetas.empty()) {
        vista.mostrarMensaje("No hay recetas para modificar.");
        return;
    }
    
    
    vista.mostrarRecetasParaSeleccion(recetas);
    int seleccion = vista.solicitarSeleccionReceta(recetas.size());
    Receta* recetaSeleccionada = recetas[seleccion];

    cout << "\n¿Desea modificar el nombre, los ingredientes o ambos? (n/i/a): ";
    char opcion;
    cin >> opcion;
    cin.ignore();

    string nuevoNombre = recetaSeleccionada->getNombrePan();  // valor actual
    map<string, double> nuevosIngredientes;

    if (opcion == 'n' || opcion == 'a') {
        cout << "Nuevo nombre del pan: ";
        getline(cin, nuevoNombre);
    }

    if (opcion == 'i' || opcion == 'a') {
        char agregarMas;
        do {
            string nombreIngrediente;
            double cantidad;

            cout << "Nombre del ingrediente: ";
            getline(cin, nombreIngrediente);
            cout << "Cantidad necesaria (en gramos): ";
            cin >> cantidad;
            cin.ignore();

            nuevosIngredientes[nombreIngrediente] = cantidad;

            cout << "¿Desea agregar otro ingrediente? (s/n): ";
            cin >> agregarMas;
            cin.ignore();
        } while (agregarMas == 's' || agregarMas == 'S');
    }

    if (controladorRecetas->modificarReceta(recetaSeleccionada, nuevoNombre, nuevosIngredientes)) {
        vista.mostrarMensaje("Receta modificada exitosamente.");
    } else {
        vista.mostrarMensaje("Error al modificar la receta.");
    }
}

void Panadero::eliminarReceta() {
    // Selecciona una receta y solicita confirmación antes de eliminarla.
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