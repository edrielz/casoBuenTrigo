#include "Ingrediente.h"

Ingrediente::Ingrediente(string nombre, double cantidad, string unidad, double nivelMinimo)
    : nombre(nombre), cantidad(cantidad), unidad(unidad), nivelMinimo(nivelMinimo) {}

string Ingrediente::getNombre() { return nombre; }
double Ingrediente::getCantidad() { return cantidad; }
void Ingrediente::setCantidad(double nuevaCantidad) { cantidad = nuevaCantidad; }
string Ingrediente::getUnidad() { return unidad; }
double Ingrediente::getNivelMinimo() { return nivelMinimo; }

bool Ingrediente::verificarAlerta() {
    return cantidad <= nivelMinimo;
}