#ifndef CONTROLADORINVENTARIO_H
#define CONTROLADORINVENTARIO_H

#include "Ingrediente.h"
#include "Inventario.h"
#include <vector>
#include <string>
using namespace std;


/*=========================================================================================================
                                      Documentacion CRC - ControladorInventario
===========================================================================================================
Clase: 
    ControladorInventario
Responsabilidades:
    - Gestionar las operaciones relacionadas con el inventario de ingredientes y panes.
    - Proveer una interfaz para agregar, actualizar, eliminar ingredientes y consultar el inventario.
    - Generar alertas basadas en los niveles de stock de los ingredientes.
Colaboradores:
    - Inventario
    - VistaEncargadoInventario
----------------------------------------------------------------------------------------------------------
*/ 

class ControladorInventario {
private:
    Inventario* inventario;

public:
    ControladorInventario(Inventario* inventario);
    ~ControladorInventario();
    
    bool agregarIngrediente(string nombre, double cantidad, string unidad, double nivelMinimo);
    bool actualizarIngrediente(string nombre, double nuevaCantidad);
    bool eliminarIngrediente(string nombre);
    vector<string> consultarInventario();
    vector<string> obtenerAlertas();
};

#endif