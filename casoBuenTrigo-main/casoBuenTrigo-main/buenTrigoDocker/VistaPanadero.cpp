#include "VistaPanadero.h"
#include <iostream>
#include <iomanip>

using namespace std;

void VistaPanadero::mostrarMenu() {
    cout << "\n=== MENU PANADERO ===" << endl;
    cout << "1. Registrar nueva receta" << endl;
    cout << "2. Modificar receta existente" << endl;
    cout << "3. Eliminar receta" << endl;
    cout << "4. Registrar producción de pan" << endl;
    cout << "5. Consultar stock de panes" << endl;
    cout << "6. Ver todas las recetas" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opción: ";
}

tuple<string, map<string, double>> VistaPanadero::solicitarDatosReceta() {
    string nombrePan;
    map<string, double> ingredientes;
    
    cout << "\n=== REGISTRAR NUEVA RECETA ===" << endl;
    cout << "Nombre del pan: ";
    cin.ignore();
    getline(cin, nombrePan);
    
    char agregarMas;
    do {
        string nombreIngrediente;
        double cantidad;
        
        cout << "Nombre del ingrediente: ";
        getline(cin, nombreIngrediente);
        cout << "Cantidad necesaria (en gramos): ";
        cin >> cantidad;
        cin.ignore(); // Limpiar buffer
        
        ingredientes[nombreIngrediente] = cantidad;
        
        cout << "¿Desea agregar otro ingrediente? (s/n): ";
        cin >> agregarMas;
        cin.ignore();
    } while (agregarMas == 's' || agregarMas == 'S');
    
    return make_tuple(nombrePan, ingredientes);
}

void VistaPanadero::mostrarRecetas(vector<Receta*> recetas) {
    cout << "\n=== RECETAS REGISTRADAS ===" << endl;
    if (recetas.empty()) {
        cout << "No hay recetas registradas." << endl;
        return;
    }
    
    for (size_t i = 0; i < recetas.size(); i++) {
        cout << "\n" << (i + 1) << ". " << recetas[i]->getNombrePan() << endl;
        auto ingredientes = recetas[i]->getIngredientesConNombre(); // Usar nuevo método
        
        if (ingredientes.empty()) {
            cout << "   No hay ingredientes registrados." << endl;
        } else {
            cout << "   Ingredientes:" << endl;
            for (const auto& [nombre, cantidad] : ingredientes) {
                cout << "   - " << nombre << ": " << cantidad << "g" << endl;
            }
        }
        cout << "------------------------" << endl;
    }
}

void VistaPanadero::mostrarResultadoProduccion(bool exito) {
    if (exito) {
        cout << "\n✅ Producción registrada exitosamente." << endl;
        cout << "Los ingredientes han sido descontados del inventario." << endl;
    } else {
        cout << "\n❌ Error en la producción." << endl;
        cout << "No hay suficientes ingredientes en el inventario." << endl;
        cout << "Por favor, verifique el stock antes de producir." << endl;
    }
}

void VistaPanadero::mostrarStockPanes(vector<tuple<string, int>> stock) {
    cout << "\n=== STOCK DE PANES ===" << endl;
    if (stock.empty()) {
        cout << "No hay panes en stock." << endl;
        return;
    }
    
    cout << left << setw(25) << "Tipo de Pan" << setw(15) << "Cantidad" << endl;
    cout << "----------------------------------------" << endl;
    
    bool hayStockBajo = false;
    for (const auto& [tipo, cantidad] : stock) {
        cout << left << setw(25) << tipo << setw(15) << cantidad;
        if (cantidad == 0) {
            cout << "⚠ AGOTADO";
            hayStockBajo = true;
        } else if (cantidad < 10) {
            cout << "⚠ STOCK BAJO";
            hayStockBajo = true;
        }
        cout << endl;
    }
    
    if (hayStockBajo) {
        cout << "\n⚠ ALERTA: Hay panes con stock bajo o agotado." << endl;
        cout << "Considere planificar una nueva producción." << endl;
    }
}

void VistaPanadero::solicitarDatosProduccion(string& nombreReceta, int& cantidad) {
    cout << "\n=== REGISTRAR PRODUCCIÓN ===" << endl;
    cout << "Nombre de la receta a producir: ";
    cin.ignore();
    getline(cin, nombreReceta);
    
    cout << "Cantidad de panes a producir: ";
    cin >> cantidad;
    
    while (cantidad <= 0) {
        cout << "La cantidad debe ser mayor a 0. Intente nuevamente: ";
        cin >> cantidad;
    }
}

void VistaPanadero::mostrarRecetasParaSeleccion(vector<Receta*> recetas) {
    cout << "\n=== SELECCIONAR RECETA ===" << endl;
    if (recetas.empty()) {
        cout << "No hay recetas disponibles." << endl;
        return;
    }
    
    for (size_t i = 0; i < recetas.size(); i++) {
        cout << (i + 1) << ". " << recetas[i]->getNombrePan() << endl;
    }
    cout << "Seleccione el número de la receta: ";
}

int VistaPanadero::solicitarSeleccionReceta(int maxOpción) {
    int seleccion;
    cin >> seleccion;
    
    while (seleccion < 1 || seleccion > maxOpción) {
        cout << "Selección inválida. Intente nuevamente (1-" << maxOpción << "): ";
        cin >> seleccion;
    }
    
    return seleccion - 1; // Convertir a índice base 0
}

void VistaPanadero::mostrarConfirmacionEliminacion(string nombreReceta) {
    cout << "\n¿Está seguro que desea eliminar la receta: '" << nombreReceta << "'?" << endl;
    cout << "Esta acción no se puede deshacer. (s/n): ";
}

void VistaPanadero::mostrarMensaje(string mensaje) {
    cout << "\n" << mensaje << endl;
}

void VistaPanadero::mostrarIngredientesFaltantes(map<string, double> ingredientesFaltantes) {
    cout << "\n❌ INGREDIENTES INSUFICIENTES:" << endl;
    cout << "Los siguientes ingredientes no tienen suficiente stock:" << endl;
    
    for (const auto& [ingrediente, cantidadFaltante] : ingredientesFaltantes) {
        cout << " - " << ingrediente << ": faltan " << cantidadFaltante << "g" << endl;
    }
    
    cout << "\nPor favor, contacte al encargado de inventario para reponer los ingredientes." << endl;
}