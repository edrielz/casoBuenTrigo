#include "VistaLogin.h"
#include <iostream>

tuple<string, string> VistaLogin::solicitarCredenciales() {
    string usuario, password;
    
    cout << "\n=== LOGIN ===" << endl;
    cout << "Usuario: ";
    cin >> usuario;
    cout << "Password: ";
    cin >> password;
    
    return make_tuple(usuario, password);
}

void VistaLogin::mostrarError(string mensaje) {
    cout << "ERROR: " << mensaje << endl;
}