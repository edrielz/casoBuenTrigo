#ifndef PAN_H
#define PAN_H

#include <string>
using namespace std;

/*=========================================================================================================
                                      Documentacion CRC - Pan
===========================================================================================================
Clase: 
    Pan
Responsabilidades:
    - Representar un tipo de pan en el inventario con sus propiedades tipo y cantidad disponible.
    - Proveer métodos para acceder y modificar las propiedades del pan mencionadas.anteriormente.
Colaboradores:
    -Inventario
----------------------------------------------------------------------------------------------------------
*/

class Pan {
private:
    string tipo;
    int cantidad;

public:
    Pan(string tipo, int cantidad);
    
    string getTipo();
    int getCantidad();
    void setCantidad(int nuevaCantidad);
    void aumentarCantidad(int cantidad);
    void disminuirCantidad(int cantidad);
};

#endif