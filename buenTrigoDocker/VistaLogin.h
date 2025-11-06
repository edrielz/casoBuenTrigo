#ifndef VISTALOGIN_H
#define VISTALOGIN_H

#include <string>
#include <tuple>
using namespace std;

class VistaLogin {
public:
    tuple<string, string> solicitarCredenciales();
    void mostrarError(string mensaje);
};

#endif