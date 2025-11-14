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
/*


El archivo main contine una funcion que crea los usuarios correspondientes con sus respectivas propiedades, Estos usuarios se crean en la memoria dinamica del programa y se realcionan entre si por el inventario, clase central del programal.

despues va la funcion principal
ahi se crea una instancia del objeto vistaLogin, este se encarga de pedir el usuario .

Despues se crea el usuario con la funcion crear usuario y los datos que pasa el usuario, em realidad cualquier contraseña sirve siempre y cuando se respete el rol, ( dado que no hay base de datos aun ), y como todos comparten el mismo inventario no importa qeu panadero incia seccion.


Hay funciones de librerias que son dificiles de intepretar, pero explciare a continuacion:

1. make_unique crea una instancia real del objeto y la guarda en memoria dinámica. pero sin los peligros de liberar y todo eso , es como hacer un objeto de puntero y luego se lo pasaras a unique_ptr para crear el puntero inteligente

2. unique_ptr es un puntero inteligente de la libreria std talque permite crear punteros sin peligros de memoria, muy util

Apartir de aqui la vista se distribuye entre la vista del Panadero, la vista del encargado, y la vista del administrador

REPOSITORIO DE GITHUB: https://github.com/edrielz/casoBuenTrigo.git

*/

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

    // Datos de prueba predeterminados para el inventario mientras se arregla el usuario "encargado" y sus funcionalidades
    
    if(!inventario->cargarDatosJson()){
       std::cout<<"No Se pudo cargar el archivo "<< std::endl ;
    }
    

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