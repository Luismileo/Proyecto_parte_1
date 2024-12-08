#include "../Models/Repuesto.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void borrar_fila_repuestos(int indice) {
    ifstream arch_repuestos("../bin/repuestos.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_repuestos.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_repuestos, linea)) {
            if (contador != indice) {
                temp << linea << endl;
            }
            contador++;
        }
        arch_repuestos.close();
        temp.close();

        remove("../bin/repuestos.csv");
        rename("temp.csv", "../bin/repuestos.csv");

        cout << "Fila eliminada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void actualizar_fila_completa_repuestos(int indice, const Repuesto& nuevo_repuesto) {
    ifstream arch_repuestos("../bin/repuestos.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_repuestos.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_repuestos, linea)) {
            if (contador == indice) {
                temp << nuevo_repuesto.getModelo() << ","
                     << nuevo_repuesto.getMarca() << ","
                     << nuevo_repuesto.getNombre() << ","
                     << nuevo_repuesto.getModeloCarro() << ","
                     << nuevo_repuesto.getAnoCarro() << ","
                     << nuevo_repuesto.getPrecio() << ","
                     << nuevo_repuesto.getExistencias() << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_repuestos.close();
        temp.close();

        remove("../bin/repuestos.csv");
        rename("temp.csv", "../bin/repuestos.csv");

        cout << "Fila actualizada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void actualizar_dato_especifico_repuestos(int indice, int campo, const string& nuevo_valor) {
    ifstream arch_repuestos("../bin/repuestos.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_repuestos.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_repuestos, linea)) {
            if (contador == indice) {
                stringstream ss(linea);
                Repuesto repuesto("", "", "", "", 0, 0, 0);

                string modelo, marca, nombre, modelo_carro;
                string ano_carro_str, precio_str, existencias_str;

                getline(ss, modelo, ',');
                getline(ss, marca, ',');
                getline(ss, nombre, ',');
                getline(ss, modelo_carro, ',');
                getline(ss, ano_carro_str, ',');
                getline(ss, precio_str, ',');
                getline(ss, existencias_str);

                repuesto.setModelo(modelo);
                repuesto.setMarca(marca);
                repuesto.setNombre(nombre);
                repuesto.setModeloCarro(modelo_carro);
                repuesto.setAnoCarro(stoi(ano_carro_str));
                repuesto.setPrecio(stoi(precio_str));
                repuesto.setExistencias(stoi(existencias_str));

                switch (campo) {
                    case 1: repuesto.setModelo(nuevo_valor); break;
                    case 2: repuesto.setMarca(nuevo_valor); break;
                    case 3: repuesto.setNombre(nuevo_valor); break;
                    case 4: repuesto.setModeloCarro(nuevo_valor); break;
                    case 5: repuesto.setAnoCarro(stoi(nuevo_valor)); break;
                    case 6: repuesto.setPrecio(stoi(nuevo_valor)); break;
                    case 7: repuesto.setExistencias(stoi(nuevo_valor)); break;
                }

                temp << repuesto.getModelo() << ","
                     << repuesto.getMarca() << ","
                     << repuesto.getNombre() << ","
                     << repuesto.getModeloCarro() << ","
                     << repuesto.getAnoCarro() << ","
                     << repuesto.getPrecio() << ","
                     << repuesto.getExistencias() << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_repuestos.close();
        temp.close();

        remove("../bin/repuestos.csv");
        rename("temp.csv", "../bin/repuestos.csv");

        cout << "Dato actualizado correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void agregar_fila_nueva_repuestos(const Repuesto& nuevo_repuesto) {
    ofstream arch_repuestos("../bin/repuestos.csv", ios::app);

    if (arch_repuestos.is_open()) {
        arch_repuestos << nuevo_repuesto.getModelo() << ","
                       << nuevo_repuesto.getMarca() << ","
                       << nuevo_repuesto.getNombre() << ","
                       << nuevo_repuesto.getModeloCarro() << ","
                       << nuevo_repuesto.getAnoCarro() << ","
                       << nuevo_repuesto.getPrecio() << ","
                       << nuevo_repuesto.getExistencias() << endl;
        arch_repuestos.close();
        cout << "Fila agregada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void leer_archivo_completo_repuestos() {
    ifstream arch_repuestos("../bin/repuestos.csv", ios::in);

    if (arch_repuestos.is_open()) {
        string linea;
        while (getline(arch_repuestos, linea)) {
            cout << linea << endl;
        }
        arch_repuestos.close();
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void leer_datos_especifico_repuestos(int indice) {
    ifstream arch_repuestos("../bin/repuestos.csv", ios::in);
    if (arch_repuestos.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_repuestos, linea)) {
            if (contador == indice) {
                cout << linea << endl;
                arch_repuestos.close();
                return;
            }
            contador++;
        }
        cout << "Índice no encontrado." << endl;
        arch_repuestos.close();
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}