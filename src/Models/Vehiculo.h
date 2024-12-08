#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include <string>
using namespace std;

class Vehiculo{
private:
    string modelo;
    string marca;
    string placa;
    string color;
    int ano;
    int kilometraje;
    bool rentado;
    string motor;
    int precio_renta;
    int ced_cliente;
    string fecha_de_entrega;

public:
    // Constructor
    Vehiculo(string modelo, string marca, string placa, string color, 
             int ano, int kilometraje, bool rentado, string motor, 
             int precio_renta, int ced_cliente, string fecha_de_entrega);

    // Getters
    string getModelo() const;
    string getMarca() const;
    string getPlaca() const;
    string getColor() const;
    int getAno() const;
    int getKilometraje() const;
    bool isRentado() const;
    string getMotor() const;
    int getPrecioRenta() const;
    int getCedCliente() const;
    string getFechaEntrega() const;

    // Setters
    void setModelo(const string& modelo);
    void setMarca(const string& marca);
    void setPlaca(const string& placa);
    void setColor(const string& color);
    void setAno(int ano);
    void setKilometraje(int kilometraje);
    void setRentado(bool rentado);
    void setMotor(const string& motor);
    void setPrecioRenta(int precio_renta);
    void setCedCliente(int ced_cliente);
    void setFechaEntrega(const string& fecha_de_entrega);
};

#endif       // VEHICULO_H