#include "ControladorProduccion.h"

ControladorProduccion::ControladorProduccion(Inventario* inventario) 
    : inventario(inventario) {}

bool ControladorProduccion::verificarStock(Receta* receta, int cantidadPanes) {
    return inventario->verificarDisponibilidad(receta, cantidadPanes);
}

bool ControladorProduccion::producirPan(Receta* receta, int cantidadPanes) {
    if (!verificarStock(receta, cantidadPanes)) {
        return false;
    }
    
    if (inventario->consumirIngredientes(receta, cantidadPanes)) {
        inventario->actualizarStockPan(receta->getNombrePan(), cantidadPanes);
        return true;
    }
    return false;
}

vector<Pan*> ControladorProduccion::getStockPanes() {
    return inventario->getPanes();
}