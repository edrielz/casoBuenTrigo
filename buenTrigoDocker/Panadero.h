#ifndef PANADERO_H
#define PANADERO_H

#include "Usuario.h"
#include "ControladorRecetas.h"
#include "ControladorProduccion.h"

class Panadero : public Usuario {
private:
    ControladorRecetas* controladorRecetas;
    ControladorProduccion* controladorProduccion;

public:
    /**
     *cr es el puntero al Controlador de recetas para gestionar recetas
     *cp es el puntero al Controlador de producción para gestionar la producción y stock
     */
    Panadero(string nombre, string password, 
             ControladorRecetas* cr, ControladorProduccion* cp);
    void mostrarMenu() override;
    
    void registrarReceta();
    void modificarReceta();
    void eliminarReceta();
    void registrarProduccion();
    void consultarStockPanes();
};

#endif