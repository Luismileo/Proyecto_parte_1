#include "../Models/Vehiculo.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

void borrar_fila_vehiculos(int indice) {
    ifstream arch_vehiculos("../bin/vehiculos.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_vehiculos.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_vehiculos, linea)) {
            if (contador != indice) {
                temp << linea << endl;
            }
            contador++;
        }
        arch_vehiculos.close();
        temp.close();

        // Reemplazar el archivo original con el archivo temporal
        remove("../bin/vehiculos.csv");
        rename("temp.csv", "../bin/vehiculos.csv");

        cout << "Fila eliminada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}

void actualizar_fila_completa_vehiculos(int indice, const Vehiculo& nuevo_vehiculo) {
    ifstream arch_vehiculos("../bin/vehiculos.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_vehiculos.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_vehiculos, linea)) {
            if (contador == indice) {
                temp << nuevo_vehiculo.getModelo() << ","
                     << nuevo_vehiculo.getMarca() << ","
                     << nuevo_vehiculo.getPlaca() << ","
                     << nuevo_vehiculo.getColor() << ","
                     << nuevo_vehiculo.getAno() << ","
                     << nuevo_vehiculo.getKilometraje() << ","
                     << (nuevo_vehiculo.isRentado() ? "true" : "false") << ","
                     << nuevo_vehiculo.getMotor() << ","
                     << nuevo_vehiculo.getPrecioRenta() << ","
                     << nuevo_vehiculo.getCedCliente() << ","
                     << nuevo_vehiculo.getFechaEntrega() << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_vehiculos.close();
        temp.close();

        // Reemplazar el archivo original con el archivo temporal
        remove("../bin/vehiculos.csv");
        rename("temp.csv", "../bin/vehiculos.csv");

        cout << "Fila actualizada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}

void actualizar_dato_especifico_vehiculos(int indice, int campo, const string& nuevo_valor) {
    ifstream arch_vehiculos("../bin/vehiculos.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_vehiculos.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_vehiculos, linea)) {
            if (contador == indice) {
                stringstream ss(linea);
                Vehiculo vehiculo("", "marca", "placa", "color", 0, 0, false, "motor", 0, 0, "ced_cliente");

                string modelo, marca, placa, color, motor, fecha_entrega, rentado_str;
                int ano, kilometraje, precio_renta, ced_cliente;

                // Usar variables temporales para leer los valores
                getline(ss, modelo, ',');
                getline(ss, marca, ',');
                getline(ss, placa, ',');
                getline(ss, color, ',');
                ss >> ano;
                ss.ignore();
                ss >> kilometraje;
                ss.ignore();
                getline(ss, rentado_str, ',');
                getline(ss, motor, ',');
                ss >> precio_renta;
                ss.ignore();
                ss >> ced_cliente;
                ss.ignore();
                getline(ss, fecha_entrega, ',');

                // Asignar los valores leídos a los atributos del objeto Vehiculo
                vehiculo.setModelo(modelo);
                vehiculo.setMarca(marca);
                vehiculo.setPlaca(placa);
                vehiculo.setColor(color);
                vehiculo.setAno(ano);
                vehiculo.setKilometraje(kilometraje);
                vehiculo.setRentado(rentado_str == "true");
                vehiculo.setMotor(motor);
                vehiculo.setPrecioRenta(precio_renta);
                vehiculo.setCedCliente(ced_cliente);
                vehiculo.setFechaEntrega(fecha_entrega);

                // Modificar el campo deseado
                switch (campo) {
                    case 1: vehiculo.setModelo(nuevo_valor); break;
                    case 2: vehiculo.setMarca(nuevo_valor); break;
                    case 3: vehiculo.setPlaca(nuevo_valor); break;
                    case 4: vehiculo.setColor(nuevo_valor); break;
                    case 5: vehiculo.setAno(stoi(nuevo_valor)); break;
                    case 6: vehiculo.setKilometraje(stoi(nuevo_valor)); break;
                    case 7: vehiculo.setRentado(nuevo_valor == "si"); break;
                    case 8: vehiculo.setMotor(nuevo_valor); break;
                    case 9: vehiculo.setPrecioRenta(stoi(nuevo_valor)); break;
                    case 10: vehiculo.setCedCliente(stoi(nuevo_valor)); break;
                    case 11: vehiculo.setFechaEntrega(nuevo_valor); break;
                }

                // Escribir la línea actualizada en el archivo temporal
                temp << vehiculo.getModelo() << ","
                     << vehiculo.getMarca() << ","
                     << vehiculo.getPlaca() << ","
                     << vehiculo.getColor() << ","
                     << vehiculo.getAno() << ","
                     << vehiculo.getKilometraje() << ","
                     << (vehiculo.isRentado() ? "true" : "false") << ","
                     << vehiculo.getMotor() << ","
                     << vehiculo.getPrecioRenta() << ","
                     << vehiculo.getCedCliente() << ","
                     << vehiculo.getFechaEntrega() << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_vehiculos.close();
        temp.close();

        // Reemplazar el archivo original con el archivo temporal
        remove("../bin/vehiculos.csv");
        rename("temp.csv", "../bin/vehiculos.csv");

        cout << "Dato actualizado correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}

void agregar_fila_nueva_vehiculos(const Vehiculo& nuevo_vehiculo) {
    ofstream arch_vehiculos("../bin/vehiculos.csv", ios::app);

    if (arch_vehiculos.is_open()) {
        arch_vehiculos << nuevo_vehiculo.getModelo() << ","
                       << nuevo_vehiculo.getMarca() << ","
                       << nuevo_vehiculo.getPlaca() << ","
                       << nuevo_vehiculo.getColor() << ","
                       << nuevo_vehiculo.getAno() << ","
                       << nuevo_vehiculo.getKilometraje() << ","
                       << (nuevo_vehiculo.isRentado() ? "true" : "false") << ","
                       << nuevo_vehiculo.getMotor() << ","
                       << nuevo_vehiculo.getPrecioRenta() << ","
                       << nuevo_vehiculo.getCedCliente() << ","
                       << nuevo_vehiculo.getFechaEntrega() << endl;
        arch_vehiculos.close();
        cout << "Fila agregada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}

void leer_datos_especifico_vehiculos(int indice) {
    ifstream arch_vehiculos("../bin/vehiculos.csv", ios::in);
    if (arch_vehiculos.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_vehiculos, linea)) {
            if (contador == indice) {
                stringstream ss(linea);
                string modelo, marca, placa, color, motor, fecha_entrega, rentado_str;
                int ano, kilometraje, precio_renta, ced_cliente;

                getline(ss, modelo, ',');
                getline(ss, marca, ',');
                getline(ss, placa, ',');
                getline(ss, color, ',');
                ss >> ano;
                ss.ignore();
                ss >> kilometraje;
                ss.ignore();
                getline(ss, rentado_str, ',');
                bool rentado = (rentado_str == "true");
                getline(ss, motor, ',');
                ss >> precio_renta;
                ss.ignore();
                ss >> ced_cliente;
                ss.ignore();
                getline(ss, fecha_entrega, ',');

                // Crear una instancia de Vehiculo con los datos leídos
                Vehiculo vehiculo(modelo, marca, placa, color, ano, kilometraje, rentado, motor, precio_renta, ced_cliente, fecha_entrega);

                // Mostrar los datos del vehículo
                cout << "Modelo: " << vehiculo.getModelo() << "\n"
                     << "Marca: " << vehiculo.getMarca() << "\n"
                     << "Placa: " << vehiculo.getPlaca() << "\n"
                     << "Color: " << vehiculo.getColor() << "\n"
                     << "Año: " << vehiculo.getAno() << "\n"
                     << "Kilometraje: " << vehiculo.getKilometraje() << "\n"
                     << "Rentado: " << (vehiculo.isRentado() ? "Sí" : "No") << "\n"
                     << "Motor: " << vehiculo.getMotor() << "\n"
                     << "Precio de Renta: " << vehiculo.getPrecioRenta() << "\n"
                                          << "Cédula del Cliente: " << vehiculo.getCedCliente() << "\n"
                     << "Fecha de Entrega: " << vehiculo.getFechaEntrega() << "\n";
                arch_vehiculos.close();
                return;
            }
            contador++;
        }
        cout << "Índice no encontrado." << endl;
        arch_vehiculos.close();
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}

void busqueda_consulta_vehiculos() {
    ifstream arch_vehiculos("../bin/vehiculos.csv", ios::in);
    if (!arch_vehiculos.is_open()) {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
        return;
    }

    int campo;
    string valor_busqueda;
    cout << "Ingrese el número del campo por el cual desea buscar (1-11): \n";
    cout << "1. Modelo\n";
    cout << "2. Marca\n";
    cout << "3. Placa\n";
    cout << "4. Color\n";
    cout << "5. Año\n";
    cout << "6. Kilometraje\n";
    cout << "7. Rentado (si/no)\n";
    cout << "8. Motor\n";
    cout << "9. Precio de Renta\n";
    cout << "10. Cédula del Cliente\n";
    cout << "11. Fecha de Entrega\n";
    cout << "Ingrese valor: "; cin >> campo;
    cout << "Ingrese el valor de búsqueda: "; cin.ignore(); getline(cin, valor_busqueda);

    string linea;
    bool encontrado = false;
    while (getline(arch_vehiculos, linea)) {
        stringstream ss(linea);
        string modelo, marca, placa, color, motor, fecha_entrega, rentado_str;
        int ano, kilometraje, precio_renta, ced_cliente;

        getline(ss, modelo, ',');
        getline(ss, marca, ',');
        getline(ss, placa, ',');
        getline(ss, color, ',');
        ss >> ano;
        ss.ignore();
        ss >> kilometraje;
        ss.ignore();
        getline(ss, rentado_str, ',');
        bool rentado = (rentado_str == "true");
        getline(ss, motor, ',');
        ss >> precio_renta;
        ss.ignore();
        ss >> ced_cliente;
        ss.ignore();
        getline(ss, fecha_entrega, ',');

        // Crear una instancia de Vehiculo
        Vehiculo vehiculo(modelo, marca, placa, color, ano, kilometraje, rentado, motor, precio_renta, ced_cliente, fecha_entrega);

        bool coincide = false;
        switch (campo) {
            case 1: coincide = (vehiculo.getModelo() == valor_busqueda); break;
            case 2: coincide = (vehiculo.getMarca() == valor_busqueda); break;
            case 3: coincide = (vehiculo.getPlaca() == valor_busqueda); break;
            case 4: coincide = (vehiculo.getColor() == valor_busqueda); break;
            case 5: coincide = (to_string(vehiculo.getAno()) == valor_busqueda); break;
            case 6: coincide = (to_string(vehiculo.getKilometraje()) == valor_busqueda); break;
            case 7: coincide = (vehiculo.isRentado() == (valor_busqueda == "si")); break;
            case 8: coincide = (vehiculo.getMotor() == valor_busqueda); break;
            case 9: coincide = (to_string(vehiculo.getPrecioRenta()) == valor_busqueda); break;
            case 10: coincide = (to_string(vehiculo.getCedCliente()) == valor_busqueda); break;
            case 11: coincide = (vehiculo.getFechaEntrega() == valor_busqueda); break;
        }

        if (coincide) {
            cout << "Modelo: " << vehiculo.getModelo() << "\n"
                 << "Marca: " << vehiculo.getMarca() << "\n"
                 << "Placa: " << vehiculo.getPlaca() << "\n"
                 << "Color: " << vehiculo.getColor() << "\n"
                 << "Año: " << vehiculo.getAno() << "\n"
                 << "Kilometraje: " << vehiculo.getKilometraje() << "\n"
                 << "Rentado: " << (vehiculo.isRentado() ? "Sí" : "No") << "\n"
                 << "Motor: " << vehiculo.getMotor() << "\n"
                 << "Precio de Renta: " << vehiculo.getPrecioRenta() << "\n"
                 << "Cédula del Cliente: " << vehiculo.getCedCliente() << "\n"
                 << "Fecha de Entrega: " << vehiculo.getFechaEntrega() << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron resultados para la búsqueda." << endl;
    }

    arch_vehiculos.close();
}