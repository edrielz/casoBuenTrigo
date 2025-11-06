#ifndef CONTROLADORREPORTES_H
#define CONTROLADORREPORTES_H

#include "Inventario.h"
#include <string>
using namespace std;

class ControladorReportes {
private:
    Inventario* inventario;

public:
    ControladorReportes(Inventario* inventario);
    
    string generarReporteInventario();
    string generarReporteStock();
    bool exportarReporte(string nombreArchivo);
};

#endif