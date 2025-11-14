#ifndef CONTROLADORREPORTES_H
#define CONTROLADORREPORTES_H

#include "Inventario.h"
#include <string>
using namespace std;
/*=========================================================================================================
                                      Documentacion CRC - ControladorReportes
===========================================================================================================
Clase: 
    ControladorReportes
Responsabilidades:
    - Generar reportes relacionados con el inventario y el stock de panes.
Colaboradores:
    - Inventario
----------------------------------------------------------------------------------------------------------
*/

class ControladorReportes {
private:
    Inventario* inventario;

public:
    ControladorReportes(Inventario* inventario);
    
    string generarReporteInventario();
    string generarReporteStock();
};

#endif