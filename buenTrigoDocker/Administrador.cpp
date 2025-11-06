#include "Administrador.h"
#include "VistaAdministrador.h"
#include <iostream>

Administrador::Administrador(string nombre, string password, 
                           ControladorReportes* cr)
    : Usuario(nombre, "administrador", password), controladorReportes(cr) {}

void Administrador::mostrarMenu() {
    VistaAdministrador vista;
    vista.mostrarMenu();
}

void Administrador::generarReporte() {
    VistaAdministrador vista;
    string reporteInventario = controladorReportes->generarReporteInventario();
    string reporteStock = controladorReportes->generarReporteStock();
    vista.mostrarReporteCompleto(reporteInventario, reporteStock);
}

// Implementación de otros métodos...