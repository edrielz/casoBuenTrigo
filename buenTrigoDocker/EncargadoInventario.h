#ifndef ENCARGADOINVENTARIO_H
#define ENCARGADOINVENTARIO_H

#include "Usuario.h"
#include "ControladorInventario.h"

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