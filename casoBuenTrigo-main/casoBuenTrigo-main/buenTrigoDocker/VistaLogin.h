#ifndef VISTALOGIN_H
#define VISTALOGIN_H

#include <string>
#include <tuple>
using namespace std;
/*=========================================================================================================
                                      Documentacion CRC - VistaLogin
===========================================================================================================
Clase: 
    VistaLogin
Responsabilidades:
    - Solicitar credenciales de inicio de sesión al usuario.
Colaboradores:
    -Ninguno
----------------------------------------------------------------------------------------------------------
*/

class VistaLogin {
public:
    tuple<string, string> solicitarCredenciales();
    void mostrarError(string mensaje);
};

#endif