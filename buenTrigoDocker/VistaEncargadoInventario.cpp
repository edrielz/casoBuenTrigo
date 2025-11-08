#include "VistaEncargadoInventario.h"
#include <iostream>

void VistaEncargadoInventario::mostrarMenu() {
    cout << "\n=== MENU ENCARGADO DE INVENTARIO ===" << endl;
    cout << "1. Registrar ingrediente" << endl;
    cout << "2. Editar ingrediente" << endl;
    cout << "3. Eliminar ingrediente" << endl;
    cout << "4. Consultar inventario" << endl;
    cout << "5. Ver alertas" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: ";
}

tuple<string, double, string, double> VistaEncargadoInventario::solicitarDatosIngrediente() {
    string nombre, unidad;
    double cantidad, nivelMinimo;
    
    cout << "Nombre del ingrediente: ";
    cin >> nombre;
    cout << "Cantidad: ";
    cin >> cantidad;
    cout << "Unidad de medida: ";
    cin >> unidad;
    cout << "Nivel mínimo para alerta: ";
    cin >> nivelMinimo;
    
    return make_tuple(nombre, cantidad, unidad, nivelMinimo);
}

void VistaEncargadoInventario::mostrarInventario(vector<string> inventario) {
    cout << "\n=== INVENTARIO ACTUAL ===" << endl;
    for (const auto& item : inventario) {
        cout << item << endl;
    }
}

void VistaEncargadoInventario::mostrarAlertas(vector<string> alertas) {
    if (alertas.empty()) {
        cout << "\nNo hay alertas en este momento." << endl;
    } else {
        cout << "\n=== ALERTAS DE INVENTARIO ===" << endl;
        for (const auto& alerta : alertas) {
            cout << "⚠ " << alerta << endl;
        }
    }
}

void VistaEncargadoInventario::mostrarMensaje(string mensaje) {
    cout << "\n" << mensaje << endl;
}

void VistaEncargadoInventario::mostrarConfirmacionEliminacion(string nombreIngrediente) {
    cout << "\n¿Está seguro que desea eliminar el ingrediente: '" << nombreIngrediente << "'?" << endl;
    cout << "Esta acción no se puede deshacer. (s/n): ";
}