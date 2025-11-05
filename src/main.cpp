#include <iostream>
#include <memory>
#include "Panadero.h"
#include "EncargadoInventario.h"
#include "Administrador.h"
#include "Inventario.h"
#include "ControladorRecetas.h"
#include "ControladorProduccion.h"
#include "ControladorInventario.h"
#include "ControladorReportes.h"
#include "VistaLogin.h"
#include "Receta.h"

using namespace std;

unique_ptr<Usuario> crearUsuario(string tipo, string nombre, string password, 
                                Inventario* inventario) {
    if (tipo == "panadero") {
        auto controladorRecetas = make_unique<ControladorRecetas>(inventario);
        auto controladorProduccion = make_unique<ControladorProduccion>(inventario);
        return make_unique<Panadero>(nombre, password, 
                                   controladorRecetas.get(), 
                                   controladorProduccion.get());
    }
    else if (tipo == "encargado") {
        auto controladorInventario = make_unique<ControladorInventario>(inventario);
        return make_unique<EncargadoInventario>(nombre, password, 
                                              controladorInventario.get());
    }
    else if (tipo == "administrador") {
        auto controladorReportes = make_unique<ControladorReportes>(inventario);
        return make_unique<Administrador>(nombre, password, 
                                        controladorReportes.get());
    }
    return nullptr;
}

int main() {
    cout << "=== SISTEMA PANADERIA EL BUEN TRIGO ===" << endl;
    
    // Inicializar inventario con datos de prueba
    auto inventario = make_unique<Inventario>();
    inventario->agregarIngrediente(new Ingrediente("Harina", 100.0, "kg", 10.0));
    inventario->agregarIngrediente(new Ingrediente("Levadura", 5.0, "kg", 1.0));
    inventario->agregarIngrediente(new Ingrediente("Azucar", 20.0, "kg", 5.0));
    
    VistaLogin vistaLogin;
    
    while (true) {
        auto [usuarioInput, password] = vistaLogin.solicitarCredenciales();
        
        // En un sistema real, esto vendría de una base de datos
        string tipoUsuario = "";
        if (usuarioInput == "panadero") tipoUsuario = "panadero";
        else if (usuarioInput == "encargado") tipoUsuario = "encargado";
        else if (usuarioInput == "admin") tipoUsuario = "administrador";
        
        auto usuario = crearUsuario(tipoUsuario, usuarioInput, password, inventario.get());
        
        if (usuario && usuario->login(password)) {
            cout << "Bienvenido, " << usuario->getNombre() << "!" << endl;
            usuario->mostrarMenu();
        } else {
            vistaLogin.mostrarError("Credenciales incorrectas");
        }
        
        cout << "¿Desea cambiar de usuario? (s/n): ";
        char opcion;
        cin >> opcion;
        if (opcion != 's' && opcion != 'S') break;
    }
    
    cout << "Gracias por usar el sistema!" << endl;
    return 0;
}