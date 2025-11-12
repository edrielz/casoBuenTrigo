#include "Inventario.h"
#include <algorithm>

Inventario::~Inventario() {
    for (auto ingrediente : ingredientes) {
        delete ingrediente;
    }
    for (auto pan : panes) {
        delete pan;
    }
}

void Inventario::agregarIngrediente(Ingrediente* ingrediente) {
    ingredientes.push_back(ingrediente);
}

void Inventario::eliminarIngrediente(string nombre) {
    for (auto it = ingredientes.begin(); it != ingredientes.end(); ++it) {
        if ((*it)->getNombre() == nombre) {
            delete *it;
            ingredientes.erase(it);
            return;
        }
    }
}

Ingrediente* Inventario::buscarIngrediente(string nombre) {
    for (auto ingrediente : ingredientes) {
        if (ingrediente->getNombre() == nombre) {
            return ingrediente;
        }
    }
    return nullptr;
}

void Inventario::actualizarStockPan(string tipoPan, int cantidad) {
    for (auto pan : panes) {
        if (pan->getTipo() == tipoPan) {
            pan->aumentarCantidad(cantidad);
            return;
        }
    }
    // Si no existe, crear nuevo pan
    panes.push_back(new Pan(tipoPan, cantidad));
}

bool Inventario::verificarDisponibilidad(Receta* receta, int cantidadPanes) {
    auto ingredientesNecesarios = receta->calcularIngredientesNecesarios(cantidadPanes);
    
    for (auto& [ingrediente, cantidadNecesaria] : ingredientesNecesarios) {
        if (ingrediente->getCantidad() < cantidadNecesaria) {
            return false;
        }
    }
    return true;
}

bool Inventario::consumirIngredientes(Receta* receta, int cantidadPanes) {
    if (!verificarDisponibilidad(receta, cantidadPanes)) {
        return false;
    }
    
    auto ingredientesNecesarios = receta->calcularIngredientesNecesarios(cantidadPanes);
    for (auto& [ingrediente, cantidadNecesaria] : ingredientesNecesarios) {
        double nuevaCantidad = ingrediente->getCantidad() - cantidadNecesaria;
        ingrediente->setCantidad(nuevaCantidad);
    }
    return true;
}

vector<string> Inventario::generarAlertas() {
    vector<string> alertas;
    for (auto ingrediente : ingredientes) {
        if (ingrediente->verificarAlerta()) {
            alertas.push_back(ingrediente->getNombre() + " está por debajo del nivel mínimo");
        }
    }
    return alertas;
}

vector<Ingrediente*> Inventario::getIngredientes() { return ingredientes; }
vector<Pan*> Inventario::getPanes() { return panes; }