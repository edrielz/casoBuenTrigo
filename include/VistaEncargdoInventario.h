#ifndef VISTAENCARGADOINVENTARIO_H
#define VISTAENCARGADOINVENTARIO_H

#include <vector>
#include <string>
#include <tuple>
using namespace std;

class VistaEncargadoInventario {
public:
    void mostrarMenu();
    tuple<string, double, string, double> solicitarDatosIngrediente();
    void mostrarInventario(vector<string> inventario);
    void mostrarAlertas(vector<string> alertas);
};

#endif