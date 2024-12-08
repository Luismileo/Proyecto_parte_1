#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
using namespace std;

class Cliente{
private:
    int cedula;
    int cantidad_de_vehiculos;
    string nombre;
    string apellido;
    string email;
    string direccion;
    bool activo;

public:
    // Constructor
    Cliente(int cedula, int cantidad_de_vehiculos, string nombre, 
            string apellido, string email, string direccion, 
            bool activo);

    // Getters
    int getCedula() const;
    int getCantidadVehiculos() const;
    string getNombre() const;
    string getApellido() const;
    string getEmail() const;
    string getDireccion() const;
    bool isActivo() const;

    // Setters
    void setCedula(int cedula);
    void setCantidadVehiculos(int cantidad_de_vehiculos);
    void setNombre(const string& nombre);
    void setApellido(const string& apellido);
    void setEmail(const string& email);
    void setDireccion(const string& direccion);
    void setActivo(bool activo);
};

#endif    // CLIENTE_H