#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Usuario.h"
#include "ControladorReportes.h"

class Administrador : public Usuario {
private:
    ControladorReportes* controladorReportes;

public:
    Administrador(string nombre, string password, 
                 ControladorReportes* cr);
    void mostrarMenu() override;
    void generarReporte();
    void exportarReporte();
};

#endif