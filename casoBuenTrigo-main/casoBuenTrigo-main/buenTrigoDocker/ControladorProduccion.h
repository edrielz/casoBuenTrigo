#ifndef CONTROLADORPRODUCCION_H
#define CONTROLADORPRODUCCION_H

#include "Receta.h"
#include "Inventario.h"
#include "Pan.h"
/*=========================================================================================================
                                      Documentacion CRC - ControladorProduccion
===========================================================================================================
Clase: 
    ControladorProduccion
Responsabilidades:
    - Gestionar las operaciones relacionadas con la producción de panes.
    - Verfiicar el stock de ingredientes antes de la producción.
Colaboradores:
    - Inventario
    - VistaPanadero
----------------------------------------------------------------------------------------------------------
*/
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