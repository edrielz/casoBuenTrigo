#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <string>
using namespace std;

/*=========================================================================================================
                                      Documentacion CRC - Ingrediente
===========================================================================================================
Clase: 
    Ingrediente
Responsabilidades:
    - Representar un ingrediente en el inventario con sus propiedades como nombre, cantidad, unidad de medida y nivel mínimo.
    - Proveer métodos para acceder y modificar las propiedades del ingrediente.
Colaboradores:
    -Inventario
    -Receta
----------------------------------------------------------------------------------------------------------
*/

class Ingrediente {
private:
    string nombre;
    double cantidad;
    string unidad;
    double nivelMinimo;

public:
    Ingrediente(string nombre, double cantidad, string unidad, double nivelMinimo);
    
    string getNombre();
    double getCantidad();
    void setCantidad(double nuevaCantidad);
    bool verificarAlerta();
    string getUnidad();
    double getNivelMinimo();
};

#endif