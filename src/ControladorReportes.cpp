#include "ControladorReportes.h"
#include <fstream>
#include <sstream>

ControladorReportes::ControladorReportes(Inventario* inventario) 
    : inventario(inventario) {}

string ControladorReportes::generarReporteInventario() {
    vector<Ingrediente*> ingredientes = inventario->getIngredientes();
    stringstream reporte;
    
    reporte << "=== REPORTE DE INVENTARIO ===\n";
    for (auto ingrediente : ingredientes) {
        reporte << ingrediente->getNombre() << ": " 
               << ingrediente->getCantidad() << " " 
               << ingrediente->getUnidad();
        if (ingrediente->verificarAlerta()) {
            reporte << " [NIVEL BAJO]";
        }
        reporte << "\n";
    }
    
    return reporte.str();
}

string ControladorReportes::generarReporteStock() {
    vector<Pan*> panes = inventario->getPanes();
    stringstream reporte;
    
    reporte << "=== REPORTE DE STOCK ===\n";
    for (auto pan : panes) {
        reporte << pan->getTipo() << ": " << pan->getCantidad() << " unidades\n";
    }
    
    return reporte.str();
}

bool ControladorReportes::exportarReporte(string nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        return false;
    }
    
    archivo << generarReporteInventario() << "\n";
    archivo << generarReporteStock();
    
    archivo.close();
    return true;
}