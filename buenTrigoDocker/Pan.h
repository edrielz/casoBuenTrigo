#ifndef PAN_H
#define PAN_H

#include <string>
using namespace std;

class Pan {
private:
    string tipo;
    int cantidad;

public:
    Pan(string tipo, int cantidad);
    
    string getTipo();
    int getCantidad();
    void setCantidad(int nuevaCantidad);
    void aumentarCantidad(int cantidad);
    void disminuirCantidad(int cantidad);
};

#endif