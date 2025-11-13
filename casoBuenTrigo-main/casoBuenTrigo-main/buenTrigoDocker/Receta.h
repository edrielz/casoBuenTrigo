#ifndef RECETA_H
#define RECETA_H

#include "Ingrediente.h"
#include <map>
#include <string>
#include <vector>
#include <utility>
using namespace std;

/*=========================================================================================================
                                      Documentacion CRC - Receta
===========================================================================================================
Clase: 
    Receta
Responsabilidades:
    - Permitir agregar, modificar y eliminar ingredientes de la receta.
    - Calcular las cantidades necesarias de cada ingrediente para una cantidad dada de panes.
Colaboradores:
    -Ingrediente
    -Inventario
----------------------------------------------------------------------------------------------------------
*/

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