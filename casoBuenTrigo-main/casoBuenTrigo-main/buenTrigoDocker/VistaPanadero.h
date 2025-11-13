#ifndef VISTAPANADERO_H
#define VISTAPANADERO_H

#include "Receta.h"
#include <vector>
#include <string>
#include <map>
#include <tuple>
using namespace std;
/*=========================================================================================================
                                      Documentacion CRC - VistaPanadero
===========================================================================================================
Clase: 
    VistaPanadero
Responsabilidades:
    - Mostrar menús, recetas, resultados de producción y stock al Panadero.
    - Proveer métodos para solicitar datos de recetas y producción al usuario.
Colaboradores:
    -ControladorRecetas
    -ControladorProduccion
----------------------------------------------------------------------------------------------------------

*/

class VistaPanadero {
public:
    void mostrarMenu();
    tuple<string, map<string, double>> solicitarDatosReceta();
    void mostrarRecetas(vector<Receta*> recetas);
    void mostrarResultadoProduccion(bool exito);
    void mostrarStockPanes(vector<tuple<string, int>> stock);
    
    // Métodos adicionales para mejor flujo de trabajo
    void solicitarDatosProduccion(string& nombreReceta, int& cantidad);
    void mostrarRecetasParaSeleccion(vector<Receta*> recetas);
    int solicitarSeleccionReceta(int maxOpción);
    void mostrarConfirmacionEliminacion(string nombreReceta);
    void mostrarMensaje(string mensaje);
    void mostrarIngredientesFaltantes(map<string, double> ingredientesFaltantes);
};

#endif