#include <iostream>
#include "Repuesto.h"
using namespace std;

Repuesto::Repuesto(string modelo, string marca, string nombre, 
                   string modelo_carro, int ano_carro, int precio, 
                   int existencias) 
    : modelo(modelo), marca(marca), nombre(nombre), 
      modelo_carro(modelo_carro), ano_carro(ano_carro), 
      precio(precio), existencias(existencias) {}

// Getters
string Repuesto::getModelo() const { return modelo; }
string Repuesto::getMarca() const { return marca; }
string Repuesto::getNombre() const { return nombre; }
string Repuesto::getModeloCarro() const { return modelo_carro; }
int Repuesto::getAnoCarro() const { return ano_carro; }
int Repuesto::getPrecio() const { return precio; }
int Repuesto::getExistencias() const { return existencias; }

// Setters
void Repuesto::setModelo(const string& modelo) { this->modelo = modelo; }
void Repuesto::setMarca(const string& marca) { this->marca = marca; }
void Repuesto::setNombre(const string& nombre) { this->nombre = nombre; }
void Repuesto::setModeloCarro(const string& modelo_carro) { this->modelo_carro = modelo_carro; }
void Repuesto::setAnoCarro(int ano_carro) { this->ano_carro = ano_carro; }
void Repuesto::setPrecio(int precio) { this->precio = precio; }
void Repuesto::setExistencias(int existencias) { this->existencias = existencias; }