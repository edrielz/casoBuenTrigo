#ifndef RECETA_H
#define RECETA_H

#include "Ingrediente.h"
#include <map>
#include <string>
#include <vector>
#include <utility>
using namespace std;

class Receta {
private:
    string nombrePan;
    map<Ingrediente*, double> ingredientes; // Ingrediente y cantidad necesaria

public:
    Receta(string nombrePan);
    
    void agregarIngrediente(Ingrediente* ingrediente, double cantidad);
    void modificarIngrediente(Ingrediente* ingrediente, double nuevaCantidad);
    void eliminarIngrediente(Ingrediente* ingrediente);
    map<Ingrediente*, double> calcularIngredientesNecesarios(int cantidadPanes);
    vector<pair<string, double>> getIngredientesConNombre(); // Nuevo método
    string getNombrePan();
    map<Ingrediente*, double> getIngredientes();
};

#endif