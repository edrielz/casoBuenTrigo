#ifndef VISTAADMINISTRADOR_H
#define VISTAADMINISTRADOR_H

#include <string>
using namespace std;

class VistaAdministrador {
public:
    void mostrarMenu();
    void mostrarReporteCompleto(string reporteInventario, string reporteStock);
    void mostrarMensaje(string mensaje);
    void mostrarError(string error);
    bool solicitarExportacion();
};

#endif