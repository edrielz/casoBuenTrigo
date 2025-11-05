#include "ControladorInventario.h"

ControladorInventario::ControladorInventario(Inventario* inventario) 
    : inventario(inventario) {}

bool ControladorInventario::agregarIngrediente(string nombre, double cantidad, 
                                             string unidad, double nivelMinimo) {
    Ingrediente* ingrediente = inventario->buscarIngrediente(nombre);
    if (ingrediente != nullptr) {
        return false; // Ya existe
    }
    
    ingrediente = new Ingrediente(nombre, cantidad, unidad, nivelMinimo);
    inventario->agregarIngrediente(ingrediente);
    return true;
}

bool ControladorInventario::actualizarIngrediente(string nombre, double nuevaCantidad) {
    Ingrediente* ingrediente = inventario->buscarIngrediente(nombre);
    if (ingrediente == nullptr) {
        return false;
    }
    
    ingrediente->setCantidad(nuevaCantidad);
    return true;
}

vector<string> ControladorInventario::consultarInventario() {
    vector<string> resultado;
    vector<Ingrediente*> ingredientes = inventario->getIngredientes();
    
    for (auto ingrediente : ingredientes) {
        string info = ingrediente->getNombre() + ": " + 
                     to_string(ingrediente->getCantidad()) + " " + 
                     ingrediente->getUnidad();
        if (ingrediente->verificarAlerta()) {
            info += " [ALERTA: Stock bajo]";
        }
        resultado.push_back(info);
    }
    
    return resultado;
}

vector<string> ControladorInventario::obtenerAlertas() {
    return inventario->generarAlertas();
}