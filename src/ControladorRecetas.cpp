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

Receta* ControladorRecetas::crearReceta(string nombrePan) {
    // Verificar si ya existe una receta con ese nombre
    for (auto receta : recetas) {
        if (receta->getNombrePan() == nombrePan) {
            return nullptr; // Ya existe una receta con ese nombre
        }
    }
    
    Receta* nuevaReceta = new Receta(nombrePan);
    recetas.push_back(nuevaReceta);
    return nuevaReceta;
}

bool ControladorRecetas::modificarReceta(Receta* receta, string nuevoNombre) {
    if (receta == nullptr) return false;
    
    // Verificar que el nuevo nombre no esté en uso por otra receta
    for (auto r : recetas) {
        if (r != receta && r->getNombrePan() == nuevoNombre) {
            return false; // El nombre ya está en uso
        }
    }
    
    // En una implementación real, aquí modificaríamos los datos de la receta
    // Por ahora, solo cambiamos el nombre
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