#include "Cliente.h"
#include <iostream>
using namespace std;

// Constructor
Cliente::Cliente(int cedula, int cantidad_de_vehiculos, string nombre, 
                 string apellido, string email, string direccion, 
                 bool activo) 
    : cedula(cedula), cantidad_de_vehiculos(cantidad_de_vehiculos), 
      nombre(nombre), apellido(apellido), email(email), 
      direccion(direccion), activo(activo) {}

// Getters
int Cliente::getCedula() const {
    return cedula;
}

int Cliente::getCantidadVehiculos() const {
    return cantidad_de_vehiculos;
}

string Cliente::getNombre() const {
    return nombre;
}

string Cliente::getApellido() const {
    return apellido;
}

string Cliente::getEmail() const {
    return email;
}

string Cliente::getDireccion() const {
    return direccion;
}

bool Cliente::isActivo() const {
    return activo;
}

// Setters
void Cliente::setCedula(int cedula) {
    this->cedula = cedula;
}

void Cliente::setCantidadVehiculos(int cantidad_de_vehiculos) {
    this->cantidad_de_vehiculos = cantidad_de_vehiculos;
}

void Cliente::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Cliente::setApellido(const string& apellido) {
    this->apellido = apellido;
}

void Cliente::setEmail(const string& email) {
    this->email = email;
}

void Cliente::setDireccion(const string& direccion) {
    this->direccion = direccion;
}

void Cliente::setActivo(bool activo) {
    this->activo = activo;
}