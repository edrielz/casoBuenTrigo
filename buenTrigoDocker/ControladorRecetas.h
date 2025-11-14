#ifndef CONTROLADORRECETAS_H
#define CONTROLADORRECETAS_H

#include "Receta.h"
#include "Inventario.h"
#include <vector>
#include <string>
using namespace std;
/*=========================================================================================================
                                      Documentacion CRC - ControladorRecetas
===========================================================================================================
Clase: 
    ControladorRecetas
Responsabilidades:
    - Proveer una interfaz para crear, modificar, eliminar y buscar recetas.
Colaboradores:
    - Inventario
    - VistaPanadero
----------------------------------------------------------------------------------------------------------
*/

class ControladorRecetas {
private:
    Inventario* inventario;
    vector<Receta*> recetas = {};

public:
    ControladorRecetas(Inventario* inventario);
    ~ControladorRecetas();
    
    Receta* crearReceta(string nombrePan, map<string, double> ingredientes);
    bool modificarReceta(Receta* receta, string nuevoNombre, map<string, double> nuevosIngredientes);
    bool eliminarReceta(Receta* receta);
    bool eliminarReceta(string nombreReceta); // Sobrecarga para buscar por nombre
    Receta* buscarReceta(string nombreReceta);
    vector<Receta*> getRecetas();
};

#endif