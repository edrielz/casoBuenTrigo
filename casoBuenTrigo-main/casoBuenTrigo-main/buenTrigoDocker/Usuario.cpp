#include "Usuario.h"

Usuario::Usuario(string nombre, string tipo, string password) 
    : nombre(nombre), tipo(tipo), password(password) {}

bool Usuario::login(string inputPassword) {
    return this->password == inputPassword;
}

string Usuario::getNombre() {
    return nombre;
}

string Usuario::getTipo() {
    return tipo;
}