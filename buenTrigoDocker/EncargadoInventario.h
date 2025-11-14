#ifndef ENCARGADOINVENTARIO_H
#define ENCARGADOINVENTARIO_H

#include "Usuario.h"
#include "ControladorInventario.h"

/*=========================================================================================================
                                      Documentacion CRC - EncargadoInventario
===========================================================================================================
Clase: 
    EncargadoInventario
Responsabilidades:
    - Permitir al encargado de inventario gestionar los ingredientes del inventario.
    - Proveer un menú para realizar operaciones como agregar, editar, eliminar y consultar ingredientes.
    - Mostrar alertas sobre niveles bajos de ingredientes en el inventario.
Colaboradores:
    -Usuario
----------------------------------------------------------------------------------------------------------
*/

class EncargadoInventario : public Usuario {
private:
    ControladorInventario* controladorInventario;

public:
    EncargadoInventario(string nombre, string password, 
                       ControladorInventario* ci);
    void mostrarMenu() override;
    void registrarIngrediente();
    void editarIngrediente();
    void eliminarIngrediente();
    void consultarInventario();
    void verAlertas();
};

#endif