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

unique_ptr<Usuario> crearUsuario(
    string tipo, string nombre, string password,
    Inventario* inventario,
    ControladorRecetas* controladorRecetas = nullptr,
    ControladorProduccion* controladorProduccion = nullptr
) {
    if (tipo == "panadero") {
        
        return make_unique<Panadero>(nombre, password, controladorRecetas, controladorProduccion);
    }
    else if (tipo == "encargado") {
    auto controladorInventario = new ControladorInventario(inventario);
    return make_unique<EncargadoInventario>(nombre, password, controladorInventario);
    }
    else if (tipo == "administrador") {
        auto controladorReportes = new ControladorReportes(inventario);
        return make_unique<Administrador>(nombre, password, controladorReportes);
    }


    return nullptr;
}

int main() {
    cout << "=== SISTEMA PANADERIA EL BUEN TRIGO ===" << endl;

    
    auto inventario = make_unique<Inventario>();

    
    auto controladorRecetas = make_unique<ControladorRecetas>(inventario.get());
    auto controladorProduccion = make_unique<ControladorProduccion>(inventario.get());

    // (Opcional) Datos de prueba del inventario
    
    inventario->agregarIngrediente(new Ingrediente("Harina", 100.0, "gr", 10000.0));
    inventario->agregarIngrediente(new Ingrediente("Levadura", 5.0, "gr", 1000.0));
    inventario->agregarIngrediente(new Ingrediente("Azucar", 20.0, "gr", 5000.0));
    

    VistaLogin vistaLogin;

    while (true) {
        
        auto [usuarioInput, password] = vistaLogin.solicitarCredenciales();

        string tipoUsuario = "";
        if (usuarioInput == "panadero") tipoUsuario = "panadero";
        else if (usuarioInput == "encargado") tipoUsuario = "encargado";
        else if (usuarioInput == "admin") tipoUsuario = "administrador";

        
        auto usuario = crearUsuario(
            tipoUsuario, usuarioInput, password,
            inventario.get(),
            controladorRecetas.get(),
            controladorProduccion.get()
        );

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