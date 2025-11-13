#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Ingrediente.h"
#include "Pan.h"
#include "Receta.h"
#include <vector>
#include <string>
using namespace std;

class Inventario {
private:
    vector<Ingrediente*> ingredientes;
    vector<Pan*> panes;

public:
    ~Inventario();
    
    void agregarIngrediente(Ingrediente* ingrediente);
    void eliminarIngrediente(string nombre);
    Ingrediente* buscarIngrediente(string nombre);
    void actualizarStockPan(string tipoPan, int cantidad);
    bool verificarDisponibilidad(Receta* receta, int cantidadPanes);
    bool consumirIngredientes(Receta* receta, int cantidadPanes);
    vector<string> generarAlertas();
    vector<Ingrediente*> getIngredientes();
    vector<Pan*> getPanes();

    //Inventario opciones de guardado 

    bool guardarDatosJson(); // recibe lo que va a guardar de parametro 

    bool cargarDatosJson();// carga los datos en el objeto
    
};

#endif