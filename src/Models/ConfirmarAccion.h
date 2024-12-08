#ifndef CONFIRMAR_ACCION_H
#define CONFIRMAR_ACCION_H
#include <string>
using namespace std;

class ConfirmarAccion{
private:
    string confirmacion;

public:
    ConfirmarAccion();

    string getConfirmacion() const; // Getter

    void setConfirmacion(const string& confirmacion); // Setter




    // Método para confirmar la acción
    bool confirmar();
};

#endif // CONFIRMAR_ACCION_H