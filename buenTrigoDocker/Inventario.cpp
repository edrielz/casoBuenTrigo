#include "Inventario.h"
#include <algorithm>

#include <nlohmann/json.hpp>

#include <fstream> // guardar y modificar archivos

using json = nlohmann::json;  // se guarda el acceso a la libreria con el nombre json 

Inventario::~Inventario() {
    for (auto ingrediente : ingredientes) {
        delete ingrediente;
    }
    for (auto pan : panes) {
        delete pan;
    }
}

void Inventario::agregarIngrediente(Ingrediente* ingrediente) {
    ingredientes.push_back(ingrediente);
    guardarDatosJson();
}

void Inventario::eliminarIngrediente(string nombre) {
    for (auto it = ingredientes.begin(); it != ingredientes.end(); ++it) {
        if ((*it)->getNombre() == nombre) {
            delete *it;
            ingredientes.erase(it);
            return;
        }
    }
    guardarDatosJson();
}

Ingrediente* Inventario::buscarIngrediente(string nombre) {
    for (auto ingrediente : ingredientes) {
        if (ingrediente->getNombre() == nombre) {
            return ingrediente;
        }
    }
    return nullptr;
}

void Inventario::actualizarStockPan(string tipoPan, int cantidad) {
    for (auto pan : panes) {
        if (pan->getTipo() == tipoPan) {
            pan->aumentarCantidad(cantidad);
            return;
        }
    }
    // Si no existe, crear nuevo pan
    panes.push_back(new Pan(tipoPan, cantidad));
    guardarDatosJson();
}

bool Inventario::verificarDisponibilidad(Receta* receta, int cantidadPanes) {
    auto ingredientesNecesarios = receta->calcularIngredientesNecesarios(cantidadPanes);
    
    for (auto& [ingrediente, cantidadNecesaria] : ingredientesNecesarios) {
        if (ingrediente->getCantidad() < cantidadNecesaria) {
            return false;
        }
    }
    return true;
}

bool Inventario::consumirIngredientes(Receta* receta, int cantidadPanes) {
    if (!verificarDisponibilidad(receta, cantidadPanes)) {
        return false;
    }
    
    auto ingredientesNecesarios = receta->calcularIngredientesNecesarios(cantidadPanes);
    for (auto& [ingrediente, cantidadNecesaria] : ingredientesNecesarios) {
        double nuevaCantidad = ingrediente->getCantidad() - cantidadNecesaria;
        ingrediente->setCantidad(nuevaCantidad);
    }
    guardarDatosJson();
       
    
    return true;
}

vector<string> Inventario::generarAlertas() {
    vector<string> alertas;
    for (auto ingrediente : ingredientes) {
        if (ingrediente->verificarAlerta()) {
            alertas.push_back(ingrediente->getNombre() + " está por debajo del nivel mínimo");
        }
    }
    return alertas;
}

vector<Ingrediente*> Inventario::getIngredientes() { return ingredientes; }
vector<Pan*> Inventario::getPanes() { return panes; }


//Funciones de carga 

bool Inventario::guardarDatosJson(){
    try{
         json ingredientesGuardar; // creamos el json donde se almacenara todos los ingredientes

    // necesitamos separar las propiedades de ingredientes para poder guardalo 
    int i = 0;
    for( const auto& ingrediente : ingredientes){
        json ingredienteInfo {
            {"nombre" , ingrediente->getNombre()},
            {"cantidad", ingrediente->getCantidad()},
            {"unidad", ingrediente->getUnidad()},
            {"nivelMinimo", ingrediente->getNivelMinimo()}
        }; // se crea un objeto json de la informacion del ingrediente 
        ingredientesGuardar[i]= ingredienteInfo; // se añade al vector de ingredientres
        i++;
    }
    json panesGuardar;

    i = 0;

    for( auto pan : panes){
        json panInfo{
            {"tipo", pan->getTipo()},
            {"cantidad", pan->getCantidad()}
        };
        panesGuardar[i] = panInfo;
        i++;
    } // lo mismo para los panes 

    json datos; // concatenar los datos 
    datos["ingredientes"] = ingredientesGuardar;
    datos["panes"] = panesGuardar;

    std::ofstream archivo("datos.json");
    archivo << datos.dump(4); // dump(4) para que sea un formato legible con sangría
    archivo.close();}
    
    catch(const std::exception& e)
    {
        return false;
    }
    
   
    
    return true;
}

bool Inventario::cargarDatosJson(){
    try{
    std::ifstream archivoEntrada("datos.json");
    json datosLeidos;
    archivoEntrada >> datosLeidos; // leemos el archivo y lo guardamos en datosLeidos
    json ingredientes = datosLeidos["ingredientes"];
    json panes = datosLeidos["panes"]; 

    
    for(auto&  datos : ingredientes){ // iteramos los items que contiene el json con un auto
        int cantidad = datos["cantidad"];
        int nivelMinimo = datos["nivelMinimo"];
        std::string unidad = datos["unidad"]; 
        std::string nombre = datos["nombre"]; // estas variables nos van a servir para rellenar el construcutor

        agregarIngrediente(new Ingrediente(nombre, nivelMinimo, unidad, cantidad));

    }
    for(auto& datos : panes){ 
        string tipo = datos["tipo"];
        int cantidad = datos["cantidad"];
        actualizarStockPan(tipo , cantidad);
    }
     // lo mismo con los panes 
    }catch(const std::exception& e)
    {
        
        return false;
    }
    return true;
    
    
    
     

}