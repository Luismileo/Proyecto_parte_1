#include "../Models/Cliente.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void borrar_fila_clientes(int indice) {
    ifstream arch_clientes("../bin/clientes.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_clientes.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_clientes, linea)) {
            if (contador != indice) {
                temp << linea << endl;
            }
            contador++;
        }
        arch_clientes.close();
        temp.close();

        remove("../bin/clientes.csv");
        rename("temp.csv", "../bin/clientes.csv");

        cout << "Fila eliminada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void actualizar_fila_completa_clientes(int indice, const Cliente& nuevo_cliente) {
    ifstream arch_clientes("../bin/clientes.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_clientes.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_clientes, linea)) {
            if (contador == indice) {
                temp << nuevo_cliente.getCedula() << ","
                     << nuevo_cliente.getNombre() << ","
                     << nuevo_cliente.getApellido() << ","
                     << nuevo_cliente.getEmail() << ","
                     << nuevo_cliente.getCantidadVehiculos() << ","
                     << nuevo_cliente.getDireccion() << ","
                     << (nuevo_cliente.isActivo() ? "si" : "no") << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_clientes.close();
        temp.close();

        remove("../bin/clientes.csv");
        rename("temp.csv", "../bin/clientes.csv");

        cout << "Fila actualizada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void actualizar_dato_especifico_clientes(int indice, int campo, const string& nuevo_valor) {
    ifstream arch_clientes("../bin/clientes.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_clientes.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_clientes, linea)) {
            if (contador == indice) {
                stringstream ss(linea);
                Cliente cliente(0, 0, "", "", "", "", false);

                string cedula_str, cantidad_vehiculos_str, activo_str;
                string nombre, apellido, email, direccion;

                getline(ss, cedula_str, ',');
                getline(ss, nombre, ',');
                getline(ss, apellido, ',');
                getline(ss, email, ',');
                getline(ss, cantidad_vehiculos_str, ',');
                getline(ss, direccion, ',');
                getline(ss, activo_str);

                cliente.setCedula(stoi(cedula_str));
                cliente.setNombre(nombre);
                cliente.setApellido(apellido);
                cliente.setEmail(email);
                cliente.setCantidadVehiculos(stoi(cantidad_vehiculos_str));
                cliente.setDireccion(direccion);
                cliente.setActivo(activo_str == "si");

                switch (campo) {
                    case 1: cliente.setCedula(stoi(nuevo_valor)); break;
                    case 2: cliente.setNombre(nuevo_valor); break;
                    case 3: cliente.setApellido(nuevo_valor); break;
                    case 4: cliente.setEmail(nuevo_valor); break;
                    case 5: cliente.setCantidadVehiculos(stoi(nuevo_valor)); break;
                    case 6: cliente.setDireccion(nuevo_valor); break;
                    case 7: cliente.setActivo(nuevo_valor == "si"); break;
                }

                // Escribir los datos actualizados
                temp << cliente.getCedula() << ","
                     << cliente.getNombre() << ","
                     << cliente.getApellido() << ","
                     << cliente.getEmail() << ","
                     << cliente.getCantidadVehiculos() << ","
                     << cliente.getDireccion() << ","
                     << (cliente.isActivo() ? "si" : "no") << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_clientes.close();
        temp.close();

        remove("../bin/clientes.csv");
        rename("temp.csv", "../bin/clientes.csv");

        cout << "Dato actualizado correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void agregar_fila_nueva_clientes(const Cliente& nuevo_cliente) {
    ofstream arch_clientes("../bin/clientes.csv", ios::app);

    if (arch_clientes.is_open()) {
        arch_clientes << nuevo_cliente.getCedula() << ","
                      << nuevo_cliente.getNombre() << ","
                      << nuevo_cliente.getApellido() << ","
                      << nuevo_cliente.getEmail() << ","
                      << nuevo_cliente.getCantidadVehiculos() << ","
                      << nuevo_cliente.getDireccion() << ","
                      << (nuevo_cliente.isActivo() ? "si" : "no") << endl;
        arch_clientes.close();
        cout << "Fila agregada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void leer_archivo_completo_clientes() {
    ifstream arch_clientes("../bin/clientes.csv", ios::in);

    if (arch_clientes.is_open()) {
        string linea;
        while (getline(arch_clientes, linea)) {
            cout << linea << endl;
        }
        arch_clientes.close();
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void leer_datos_especifico_clientes(int indice) {
    ifstream arch_clientes("../bin/clientes.csv", ios::in);
    if (arch_clientes.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_clientes, linea)) {
            if (contador == indice) {
                cout << linea << endl;
                arch_clientes.close();
                return;
            }
            contador++;
        }
        cout << "Índice no encontrado." << endl;
        arch_clientes.close();
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}