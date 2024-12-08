#include "ConfirmarAccion.h"
#include <iostream>
using namespace std;

bool obtenerConfirmacion(ConfirmarAccion &confirmarAccion){
    return confirmarAccion.confirmar();
}

string getConfirmacion(const ConfirmarAccion &confirmarAccion){       // Getter
    return confirmarAccion.getConfirmacion();
}

void setConfirmacion(ConfirmarAccion &confirmarAccion, const string &confirmacion){      // Setter
    confirmarAccion.setConfirmacion(confirmacion);
}