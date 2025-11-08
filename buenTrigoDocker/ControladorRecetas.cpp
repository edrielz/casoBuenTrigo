#include "ControladorRecetas.h"
#include <algorithm>

using namespace std;

ControladorRecetas::ControladorRecetas(Inventario* inventario) 
    : inventario(inventario) {}

ControladorRecetas::~ControladorRecetas() {
    for (auto receta : recetas) {
        delete receta;
    }
}

Receta* ControladorRecetas::crearReceta(string nombrePan ,map<string, double> ingredientesSinComparar) {
    // Verificar si ya existe una receta con ese nombre
    for (auto receta : recetas) {
        if (receta->getNombrePan() == nombrePan) {
            return nullptr; // Ya existe una receta con ese nombre
        }
    }
    map<Ingrediente*, double> ingredientes;
    for (auto& [nombre, cantidad] : ingredientesSinComparar) {
        Ingrediente* ingrediente = inventario->buscarIngrediente(nombre);
        if (ingrediente != nullptr) {
            ingredientes[ingrediente] = cantidad;
        } else {
            return nullptr;
        }
    }
    Receta* nuevaReceta = new Receta(nombrePan);
    for (auto& [ingrediente, cantidad] : ingredientes) {
        nuevaReceta->agregarIngrediente(ingrediente, cantidad);
    }
    
    recetas.push_back(nuevaReceta);
    return nuevaReceta;
}
bool ControladorRecetas::modificarReceta(Receta* receta, string nuevoNombre, map<string, double> nuevosIngredientes) {
    if (!receta) return false;

    
    map<string, double> ingredientesFinales;

    if (nuevosIngredientes.empty()) {
        
        auto actuales = receta->getIngredientes(); 
        for (auto& par : actuales) {
            Ingrediente* iptr = par.first;
            double cant = par.second;
            if (iptr) {
                ingredientesFinales[iptr->getNombre()] = cant;
            }
        }
    } else {
        
        ingredientesFinales = nuevosIngredientes;
    }

    
    

    
    Receta* nueva = crearReceta(nuevoNombre+" ", ingredientesFinales); // las comillas es para que no sea el mismo nombre 
    if (nueva==nullptr) {
        
        return false;
    }

    if (!eliminarReceta(receta) ) {
        // No se pudo eliminar → abortar
        return false;
    }

    
    return true;
}

bool ControladorRecetas::eliminarReceta(Receta* receta) {
    if (receta == nullptr) return false;
    
    // Buscar la receta en el vector
    for (auto it = recetas.begin(); it != recetas.end(); ++it) {
        if (*it == receta) {
            delete *it; // Liberar memoria
            recetas.erase(it); // Eliminar del vector
            return true;
        }
    }
    return false; // No se encontró la receta
}

bool ControladorRecetas::eliminarReceta(string nombreReceta) {
    for (auto it = recetas.begin(); it != recetas.end(); ++it) {
        if ((*it)->getNombrePan() == nombreReceta) {
            delete *it; // Liberar memoria
            recetas.erase(it); // Eliminar del vector
            return true;
        }
    }
    return false; // No se encontró la receta
}

Receta* ControladorRecetas::buscarReceta(string nombreReceta) {
    for (auto receta : recetas) {
        if (receta->getNombrePan() == nombreReceta) {
            return receta;
        }
    }
    return nullptr;
}

vector<Receta*> ControladorRecetas::getRecetas() { 
    return recetas; 
}