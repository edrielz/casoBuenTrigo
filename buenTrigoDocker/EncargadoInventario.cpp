#include "EncargadoInventario.h"
#include "VistaEncargadoInventario.h"
#include <iostream>

using namespace std;

EncargadoInventario::EncargadoInventario(string nombre, string password, 
                                       ControladorInventario* ci)
    : Usuario(nombre, "encargado", password), controladorInventario(ci) {}

void EncargadoInventario::mostrarMenu() {
    VistaEncargadoInventario vista;
    int opcion;
    
    do {
        vista.mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarIngrediente();
                break;
            case 2:
                editarIngrediente();
                break;
            case 3:
                eliminarIngrediente();
                break;
            case 4:
                consultarInventario();
                break;
            case 5:
                verAlertas();
                break;
            case 6:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                vista.mostrarMensaje("Opción inválida. Intente nuevamente.");              
        }

        // Limpiar buffer de entrada        
        if (opcion != 6) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 6);
}

void EncargadoInventario::registrarIngrediente() {
    VistaEncargadoInventario vista;
    auto datos = vista.solicitarDatosIngrediente();

    // Desempaquetar los datos y llamar al controlador para agregar el ingrediente
    string nombre = get<0>(datos);
    double cantidad = get<1>(datos);
    string unidad = get<2>(datos);
    double nivelMinimo = get<3>(datos);

    // Intenta agregar el ingrediente mediante el controlador.
    bool ok = controladorInventario->agregarIngrediente(nombre, cantidad, unidad, nivelMinimo);
    if (ok) {
        vista.mostrarMensaje("Ingrediente registrado correctamente.");
    } else {
        vista.mostrarMensaje("No se pudo registrar el ingrediente: ya existe uno con ese nombre.");
    }
}

void EncargadoInventario::consultarInventario() {
    VistaEncargadoInventario vista;
    vector<string> inventario = controladorInventario->consultarInventario();
    vista.mostrarInventario(inventario);
}

/**
 * Edita la cantidad de un ingrediente existente.
 * Pide al usuario el nombre y la nueva cantidad, y delega la actualización
 * al controlador de inventario.
 */
void EncargadoInventario::editarIngrediente() {
    VistaEncargadoInventario vista;
    string nombre;
    double nuevaCantidad;

    cout << "Nombre del ingrediente a editar: ";
    cin >> nombre;
    cout << "Nueva cantidad: ";
    cin >> nuevaCantidad;

    bool ok = controladorInventario->actualizarIngrediente(nombre, nuevaCantidad);
    if (ok) {
        vista.mostrarMensaje("Ingrediente actualizado correctamente.");
    } else {
        vista.mostrarMensaje("No se pudo actualizar: ingrediente no encontrado.");
    }
}

/**
 * El siguiente metodo elimina un ingrediente del inventario.
 * Solicita confirmación antes de delegar la eliminación al controlador
 * tal como en editarIngrediente
 */
void EncargadoInventario::eliminarIngrediente() {
    VistaEncargadoInventario vista;
    string nombre;

    cout << "Nombre del ingrediente a eliminar: ";
    cin >> nombre;
    vista.mostrarConfirmacionEliminacion(nombre);
    char resp;
    cin >> resp;
    if (resp == 's' || resp == 'S') {
        bool ok = controladorInventario->eliminarIngrediente(nombre);
        if (ok) vista.mostrarMensaje("Ingrediente eliminado correctamente.");
        else vista.mostrarMensaje("No se pudo eliminar: ingrediente no encontrado.");
    } else {
        vista.mostrarMensaje("Eliminación cancelada.");
    }
}

void EncargadoInventario::verAlertas() {
    VistaEncargadoInventario vista;
    vector<string> alertas = controladorInventario->obtenerAlertas();
    vista.mostrarAlertas(alertas);
}