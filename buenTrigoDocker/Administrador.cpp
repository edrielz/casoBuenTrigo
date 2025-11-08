#include "Administrador.h"
#include "VistaAdministrador.h"
#include <fstream>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

Administrador::Administrador(string nombre, string password, 
                           ControladorReportes* cr)
    : Usuario(nombre, "administrador", password), controladorReportes(cr) {}

void Administrador::mostrarMenu() {
    VistaAdministrador vista;
    int opcion;
    
    do {
        vista.mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                generarReporte();
                break;
            case 2:
                exportarReporte();
                break;
            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                vista.mostrarMensaje("Opción inválida. Intente nuevamente.");              
        }

        // Limpiar buffer de entrada        
        if (opcion != 3) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 3);
}

void Administrador::generarReporte() {
    VistaAdministrador vista;
    string reporteInventario = controladorReportes->generarReporteInventario();
    string reporteStock = controladorReportes->generarReporteStock();
    vista.mostrarReporteCompleto(reporteInventario, reporteStock);
}

void Administrador::exportarReporte() {
    VistaAdministrador vista;
    vista.solicitarExportacion();
    string reporteInventario = controladorReportes->generarReporteInventario();
    string reporteStock = controladorReportes->generarReporteStock();
    ofstream archivo("reporte_inventario.txt");

        if (archivo.is_open()) {
        archivo << "REPORTE DE INVENTARIO:\n";
        archivo << reporteInventario << "\n\n";
        archivo << "REPORTE DE STOCK:\n";
        archivo << reporteStock;
        archivo.close();
        
        vista.mostrarMensaje("Reporte exportado a: reporte_inventario.txt");
    } else {
        vista.mostrarError("No se pudo crear el archivo de reporte");
    }
}