#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Usuario.h"
#include "ControladorReportes.h"
/*=========================================================================================================
                                      Documentacion CRC - Administrador
===========================================================================================================
Clase: 
    Administrador
Responsabilidades:
    - Gestionar la vista y las operaciones del administrador en el sistema.
    - Generar y exportar reportes relacionados con el inventario y el stock.
Colaboradores:
    - ControladorReportes
----------------------------------------------------------------------------------------------------------
*/

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