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
                break;
            case 3:
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
}

void EncargadoInventario::consultarInventario() {
    VistaEncargadoInventario vista;
    vector<string> inventario = controladorInventario->consultarInventario();
    vista.mostrarInventario(inventario);
}

void EncargadoInventario::verAlertas() {
    VistaEncargadoInventario vista;
    vector<string> alertas = controladorInventario->obtenerAlertas();
    vista.mostrarAlertas(alertas);
}