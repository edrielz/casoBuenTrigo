#include "EncargadoInventario.h"
#include "VistaEncargadoInventario.h"
#include <iostream>

EncargadoInventario::EncargadoInventario(string nombre, string password, 
                                       ControladorInventario* ci)
    : Usuario(nombre, "encargado", password), controladorInventario(ci) {}

void EncargadoInventario::mostrarMenu() {
    VistaEncargadoInventario vista;
    vista.mostrarMenu();
}

void EncargadoInventario::registrarIngrediente() {
    VistaEncargadoInventario vista;
    auto datos = vista.solicitarDatosIngrediente();
    // Implementación para registrar ingrediente
}

// Implementación de otros métodos...