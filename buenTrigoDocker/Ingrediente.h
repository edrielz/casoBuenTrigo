#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <string>
using namespace std;

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