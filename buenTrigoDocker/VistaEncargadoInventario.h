#ifndef VISTAENCARGADOINVENTARIO_H
#define VISTAENCARGADOINVENTARIO_H

#include <vector>
#include <string>
#include <tuple>
using namespace std;
/*=========================================================================================================
                                      Documentacion CRC - VistaEncargadoInventario
===========================================================================================================
Clase: 
    VistaEncargadoInventario
Responsabilidades:
    - Mostrar menús, inventario, alertas y mensajes al Encargado de Inventario.
Colaboradores:
    -ControladorInventario
----------------------------------------------------------------------------------------------------------
*/

class VistaEncargadoInventario {
public:
    void mostrarMenu();
    tuple<string, double, string, double> solicitarDatosIngrediente();
    void mostrarInventario(vector<string> inventario);
    void mostrarAlertas(vector<string> alertas);
    void mostrarMensaje(string mensaje);
    void mostrarConfirmacionEliminacion(string nombreIngrediente);

};

#endif