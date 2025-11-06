#include "Pan.h"

Pan::Pan(string tipo, int cantidad) 
    : tipo(tipo), cantidad(cantidad) {}

string Pan::getTipo() { return tipo; }
int Pan::getCantidad() { return cantidad; }
void Pan::setCantidad(int nuevaCantidad) { cantidad = nuevaCantidad; }

void Pan::aumentarCantidad(int cantidad) {
    this->cantidad += cantidad;
}

void Pan::disminuirCantidad(int cantidad) {
    if (this->cantidad >= cantidad) {
        this->cantidad -= cantidad;
    }
}