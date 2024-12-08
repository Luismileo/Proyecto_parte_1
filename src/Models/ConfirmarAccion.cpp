#include "ConfirmarAccion.h"
#include <iostream>
#include <algorithm>
using namespace std;

ConfirmarAccion::ConfirmarAccion() : confirmacion("") {}

// Getter
string ConfirmarAccion::getConfirmacion() const {
    return confirmacion;
}

// Setter
void ConfirmarAccion::setConfirmacion(const string& confirmacion) {
    this->confirmacion = confirmacion;
}

bool ConfirmarAccion::confirmar() {
    cout << "¿Está seguro de que desea realizar esta acción? (si/no): ";
    cin >> confirmacion;
    
    transform(confirmacion.begin(), confirmacion.end(), confirmacion.begin(), ::tolower);
    
    if (confirmacion == "si") {
        return true; // Confirmación positiva
    } else if (confirmacion == "no") {
        return false; // Confirmación negativa
    } else {
        cout << "Entrada no válida. Por favor ingrese 'si' o 'no'.\n";
        return confirmar(); // Recursivamente volver a pedir confirmación
    }
}