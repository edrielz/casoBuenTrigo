#ifndef CONTROLADORPRODUCCION_H
#define CONTROLADORPRODUCCION_H

#include "Receta.h"
#include "Inventario.h"
#include "Pan.h"

class ControladorProduccion {
private:
    Inventario* inventario;

public:
    ControladorProduccion(Inventario* inventario);
    
    bool producirPan(Receta* receta, int cantidadPanes);
    bool verificarStock(Receta* receta, int cantidadPanes);
    vector<Pan*> getStockPanes();
};

#endif