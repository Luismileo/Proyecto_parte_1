#ifndef REPUESTO_H
#define REPUESTO_H
#include <iostream>
#include <string>
using namespace std;

class Repuesto {
private:
    string modelo;
    string marca;
    string nombre;
    string modelo_carro;
    int ano_carro;
    int precio;
    int existencias;

public:
    // Constructor
    Repuesto(string modelo, string marca, string nombre, 
             string modelo_carro, int ano_carro, int precio, 
             int existencias);

    // Getters
    string getModelo() const;
    string getMarca() const;
    string getNombre() const;
    string getModeloCarro() const;
    int getAnoCarro() const;
    int getPrecio() const;
    int getExistencias() const;

    // Setters
    void setModelo(const string& modelo);
    void setMarca(const string& marca);
    void setNombre(const string& nombre);
    void setModeloCarro(const string& modelo_carro);
    void setAnoCarro(int ano_carro);
    void setPrecio(int precio);
    void setExistencias(int existencias);
};

#endif     // REPUESTO_H