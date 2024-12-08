#include <iostream>
#include "Vehiculo.h"
using namespace std;

Vehiculo::Vehiculo(string modelo, string marca, string placa, 
                   string color, int ano, int kilometraje, bool rentado, 
                   string motor, int precio_renta, int ced_cliente, 
                   string fecha_de_entrega) 
    : modelo(modelo), marca(marca), placa(placa), color(color), 
      ano(ano), kilometraje(kilometraje), rentado(rentado), 
      motor(motor), precio_renta(precio_renta), ced_cliente(ced_cliente), 
      fecha_de_entrega(fecha_de_entrega) {}

// Getters
string Vehiculo::getModelo() const { return modelo; }
string Vehiculo::getMarca() const { return marca; }
string Vehiculo::getPlaca() const { return placa; }
string Vehiculo::getColor() const { return color; }
int Vehiculo::getAno() const { return ano; }
int Vehiculo::getKilometraje() const { return kilometraje; }
bool Vehiculo::isRentado() const { return rentado; }
string Vehiculo::getMotor() const { return motor; }
int Vehiculo::getPrecioRenta() const { return precio_renta; }
int Vehiculo::getCedCliente() const { return ced_cliente; }
string Vehiculo::getFechaEntrega() const { return fecha_de_entrega; }

// Setters
void Vehiculo::setModelo(const string& modelo) { this->modelo = modelo; }
void Vehiculo::setMarca(const string& marca) { this->marca = marca; }
void Vehiculo::setPlaca(const string& placa) { this->placa = placa; }
void Vehiculo::setColor(const string& color) { this->color = color; }
void Vehiculo::setAno(int ano) { this->ano = ano; }
void Vehiculo::setKilometraje(int kilometraje) { this->kilometraje = kilometraje; }
void Vehiculo::setRentado(bool rentado) { this->rentado = rentado; }
void Vehiculo::setMotor(const string& motor) { this->motor = motor; }
void Vehiculo::setPrecioRenta(int precio_renta) { this->precio_renta = precio_renta; }
void Vehiculo::setCedCliente(int ced_cliente) { this->ced_cliente = ced_cliente; }
void Vehiculo::setFechaEntrega(const string& fecha_de_entrega) { this->fecha_de_entrega = fecha_de_entrega; }