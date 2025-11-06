#ifndef CONTROLADORRECETAS_H
#define CONTROLADORRECETAS_H

#include "Receta.h"
#include "Inventario.h"
#include <vector>
#include <string>
using namespace std;

class ControladorRecetas {
private:
    Inventario* inventario;
    vector<Receta*> recetas;

public:
    ControladorRecetas(Inventario* inventario);
    ~ControladorRecetas();
    
    Receta* crearReceta(string nombrePan);
    bool modificarReceta(Receta* receta, string nuevoNombre);
    bool eliminarReceta(Receta* receta);
    bool eliminarReceta(string nombreReceta); // Sobrecarga para buscar por nombre
    Receta* buscarReceta(string nombreReceta);
    vector<Receta*> getRecetas();
};

#endif