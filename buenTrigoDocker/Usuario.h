#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    string nombre;
    string tipo;
    string password;

public:
    Usuario(string nombre, string tipo, string password);
    virtual ~Usuario() {}
    
    bool login(string password);
    string getNombre();
    string getTipo();
    virtual void mostrarMenu() = 0;
};

#endif