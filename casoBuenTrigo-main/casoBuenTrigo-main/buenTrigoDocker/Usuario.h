#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;
/*=========================================================================================================
                                      Documentacion CRC - Usuario
===========================================================================================================
Clase: 
    Usuario
Responsabilidades:
    - Proveer una interfaz base para diferentes tipos de usuarios en el sistema.
    - Implementar la funcionalidad login y obtención de información del usuario.
Colaboradores:
    -Panadero
    -EncargadoInventario
    -Administrador
----------------------------------------------------------------------------------------------------------
*/

class Usuario {
protected:
    string nombre;
    string tipo;
    string password;

public:
    Usuario(string nombre, string tipo, string password);
    virtual ~Usuario() {}
    
    bool login(string password);
    string getNombre();
    string getTipo();
    virtual void mostrarMenu() = 0;
};

#endif