#include "VistaAdministrador.h"
#include <iostream>

void VistaAdministrador::mostrarMenu() {
    cout << "\n=== MENU ADMINISTRADOR ===" << endl;
    cout << "1. Generar reporte completo" << endl;
    cout << "2. Exportar reporte a archivo" << endl;
    cout << "3. Control global" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void VistaAdministrador::mostrarReporteCompleto(string reporteInventario, string reporteStock) {
    cout << "\n" << reporteInventario << endl;
    cout << reporteStock << endl;
}

bool VistaAdministrador::solicitarExportacion() {
    char respuesta;
    cout << "¿Desea exportar el reporte a un archivo? (s/n): ";
    cin >> respuesta;
    return (respuesta == 's' || respuesta == 'S');
}