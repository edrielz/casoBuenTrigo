#ifndef CONTROLADORINVENTARIO_H
#define CONTROLADORINVENTARIO_H

#include "Ingrediente.h"
#include "Inventario.h"
#include <vector>
#include <string>
using namespace std;

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