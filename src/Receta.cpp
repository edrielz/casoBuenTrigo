#include "Receta.h"
#include <iostream>
#include <vector>

using namespace std;

Receta::Receta(string nombrePan) : nombrePan(nombrePan) {}

void Receta::agregarIngrediente(Ingrediente* ingrediente, double cantidad) {
    if (ingrediente == nullptr) {
        cout << "Error: Intento de agregar ingrediente nulo a la receta." << endl;
        return;
    }
    ingredientes[ingrediente] = cantidad;
}

void Receta::modificarIngrediente(Ingrediente* ingrediente, double nuevaCantidad) {
    if (ingrediente == nullptr) {
        cout << "Error: Intento de modificar ingrediente nulo." << endl;
        return;
    }
    
    if (ingredientes.find(ingrediente) != ingredientes.end()) {
        ingredientes[ingrediente] = nuevaCantidad;
    } else {
        cout << "Error: El ingrediente no está en la receta." << endl;
    }
}

void Receta::eliminarIngrediente(Ingrediente* ingrediente) {
    if (ingrediente == nullptr) {
        cout << "Error: Intento de eliminar ingrediente nulo." << endl;
        return;
    }
    
    auto it = ingredientes.find(ingrediente);
    if (it != ingredientes.end()) {
        ingredientes.erase(it);
    } else {
        cout << "Error: El ingrediente no está en la receta." << endl;
    }
}

map<Ingrediente*, double> Receta::calcularIngredientesNecesarios(int cantidadPanes) {
    map<Ingrediente*, double> resultado;
    
    if (cantidadPanes <= 0) {
        cout << "Error: Cantidad de panes debe ser mayor a 0." << endl;
        return resultado;
    }
    
    for (auto& [ingrediente, cantidad] : ingredientes) {
        if (ingrediente != nullptr) {
            resultado[ingrediente] = cantidad * cantidadPanes;
        }
    }
    return resultado;
}

string Receta::getNombrePan() { 
    return nombrePan; 
}

map<Ingrediente*, double> Receta::getIngredientes() { 
    return ingredientes; 
}

// Método adicional para facilitar la visualización
vector<pair<string, double>> Receta::getIngredientesConNombre() {
    vector<pair<string, double>> resultado;
    for (auto& [ingrediente, cantidad] : ingredientes) {
        if (ingrediente != nullptr) {
            resultado.push_back(make_pair(ingrediente->getNombre(), cantidad));
        }
    }
    return resultado;
}