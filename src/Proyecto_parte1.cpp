#include<iostream>
#include<fstream>
#include<cmath>
#include<sstream>
#include<string>

using namespace std;

struct vehiculos {
    string modelo, marca, placa, color,motor, fecha_de_entrega;
    int ano, kilometraje, precio_renta, ced_cliente;
    bool rentado;
};

struct clientes {
    int cedula, cantidad_de_vehiculos;
    string nombre, apellido, email, direccion;
    bool activo;
};

struct repuestos {
    string modelo, marca, nombre, modelo_carro;
    int ano_carro, precio, existencias;
};

void mostrarMenuPrincipal() {
    cout << "Seleccione un de los archivos con lo que desee trabajar:\n" 
         << "1. Vehiculos\n" 
         << "2. Clientes\n" 
         << "3. Repuestos\n"
         << "Ingrese opcion: ";
}

void mostrarMenuVehiculos() {
    cout << "(Archivo Vehiculos)\n"
         << "--Borrar datos--\n"
         << "1. Seleccionar fila para eliminar\n"
         << "\n"
         << "--Actualizar datos--\n"
         << "2. Actualizar fila completa\n"
         << "3. Actualizar dato especifico\n"
         << "\n"
         << "--Agregar datos--\n"
         << "4. Agregar fila  nueva de datos\n"
         << "\n"
         << "--Leer datos--\n"
         << "5. Leer archivo completo\n"
         << "6. Leer fila especifica\n"
         << "\n"
         << "--Busqueda/Consulta especifica--\n"
         << ""
         << "7. Ir a inicio\n"
         << "8. Terminar programa\n"
         << "Ingrese opcion: ";
}

void mostrarMenuClientes() {
     cout << "(Archivo Clientes)\n"
         << "--Borrar datos--\n"
         << "1. Seleccionar fila para eliminar\n"
         << "\n"
         << "--Actualizar datos--\n"
         << "2. Actualizar fila completa\n"
         << "3. Actualizar dato especifico\n"
         << "\n"
         << "--Agregar datos--\n"
         << "4. Agregar fila  nueva de datos\n"
         << "\n"
         << "--Leer datos--\n"
         << "5. Leer archivo completo\n"
         << "6. Leer fila especifica\n"
         << "\n"
         << "--Busqueda/Consulta especifica--\n"
         << ""
         << "7. Ir a inicio\n"
         << "8. Terminar programa\n"
         << "Ingrese opcion: ";
}

void mostrarMenuRepuestos() {
     cout << "(Archivo Repuestos)\n"
         << "--Borrar datos--\n"
         << "1. Seleccionar fila para eliminar\n"
         << "\n"
         << "--Actualizar datos--\n"
         << "2. Actualizar fila completa\n"
         << "3. Actualizar dato especifico\n"
         << "\n"
         << "--Agregar datos--\n"
         << "4. Agregar fila  nueva de datos\n"
         << "\n"
         << "--Leer datos--\n"
         << "5. Leer archivo completo\n"
         << "6. Leer fila especifica\n"
         << "\n"
         << "--Busqueda/Consulta especifica--\n"
         << ""
         << "7. Ir a inicio\n"
         << "8. Terminar programa\n"
         << "Ingrese opcion: ";
}

//Funciones para manejar las opciones del menu de Vehiculos

void borrar_fila_vehiculos(int indice) {
    ifstream arch_vehiculos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv", ios::in);
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
        remove("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv");
        rename("temp.csv", "/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv");

        cout << "Fila eliminada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}

void actualizar_fila_completa_vehiculos(int indice, const vehiculos& nuevo_vehiculo) {
    ifstream arch_vehiculos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_vehiculos.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_vehiculos, linea)) {
            if (contador == indice) {
                temp << nuevo_vehiculo.modelo << ","
                     << nuevo_vehiculo.marca << ","
                     << nuevo_vehiculo.placa << ","
                     << nuevo_vehiculo.color << ","
                     << nuevo_vehiculo.ano << ","
                     << nuevo_vehiculo.kilometraje << ","
                     << (nuevo_vehiculo.rentado ? "true" : "false") << ","
                     << nuevo_vehiculo.motor << ","
                     << nuevo_vehiculo.precio_renta << ","
                     << nuevo_vehiculo.ced_cliente << ","
                     << nuevo_vehiculo.fecha_de_entrega << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_vehiculos.close();
        temp.close();

        // Reemplazar el archivo original con el archivo temporal
        remove("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv");
        rename("temp.csv", "/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv");

        cout << "Fila actualizada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}

void actualizar_dato_especifico_vehiculos(int indice, int campo, const string& nuevo_valor) {
    ifstream arch_vehiculos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_vehiculos.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_vehiculos, linea)) {
            if (contador == indice) {
                stringstream ss(linea);
                vehiculos vehiculo;
                string rentado_str;
                getline(ss, vehiculo.modelo, ',');
                getline(ss, vehiculo.marca, ',');
                getline(ss, vehiculo.placa, ',');
                getline(ss, vehiculo.color, ',');
                ss >> vehiculo.ano;
                ss.ignore();
                ss >> vehiculo.kilometraje;
                ss.ignore();
                getline(ss, rentado_str, ',');
                vehiculo.rentado = (rentado_str == "true");
                getline(ss, vehiculo.motor, ',');
                ss >> vehiculo.precio_renta;
                ss.ignore();
                ss >> vehiculo.ced_cliente;
                ss.ignore();
                getline(ss, vehiculo.fecha_de_entrega, ',');

                switch (campo) {
                    case 1: vehiculo.modelo = nuevo_valor; break;
                    case 2: vehiculo.marca = nuevo_valor; break;
                    case 3: vehiculo.placa = nuevo_valor; break;
                    case 4: vehiculo.color = nuevo_valor; break;
                    case 5: vehiculo.ano = stoi(nuevo_valor); break;
                    case 6: vehiculo.kilometraje = stoi(nuevo_valor); break;
                    case 7: vehiculo.rentado = (nuevo_valor == "si"); break;
                    case 8: vehiculo.motor = nuevo_valor; break;
                    case 9: vehiculo.precio_renta = stoi(nuevo_valor); break;
                    case 10: vehiculo.ced_cliente = stoi(nuevo_valor); break;
                    case 11: vehiculo.fecha_de_entrega = nuevo_valor; break;
                }

                temp << vehiculo.modelo << ","
                     << vehiculo.marca << ","
                     << vehiculo.placa << ","
                     << vehiculo.color << ","
                     << vehiculo.ano << ","
                     << vehiculo.kilometraje << ","
                     << (vehiculo.rentado ? "true" : "false") << ","
                     << vehiculo.motor << ","
                     << vehiculo.precio_renta << ","
                     << vehiculo.ced_cliente << ","
                     << vehiculo.fecha_de_entrega << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_vehiculos.close();
        temp.close();

        // Reemplazar el archivo original con el archivo temporal
        remove("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv");
        rename("temp.csv", "/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv");

        cout << "Dato actualizado correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}

void agregar_fila_nueva_vehiculos(const vehiculos& nuevo_vehiculo) {
    ofstream arch_vehiculos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv", ios::app);

    if (arch_vehiculos.is_open()) {
        arch_vehiculos << nuevo_vehiculo.modelo << ","
                       << nuevo_vehiculo.marca << ","
                       << nuevo_vehiculo.placa << ","
                       << nuevo_vehiculo.color << ","
                       << nuevo_vehiculo.ano << ","
                       << nuevo_vehiculo.kilometraje << ","
                       << (nuevo_vehiculo.rentado ? "true" : "false") << ","
                       << nuevo_vehiculo.motor << ","
                       << nuevo_vehiculo.precio_renta << ","
                       << nuevo_vehiculo.ced_cliente << ","
                       << nuevo_vehiculo.fecha_de_entrega << endl;
        arch_vehiculos.close();
        cout << "Fila agregada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}
void leer_archivo_completo_vehiculos() {
    ifstream arch_vehiculos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv", ios::in);

    if (arch_vehiculos.is_open()) {
        string linea;
        while (getline(arch_vehiculos, linea)) {
            cout << linea << endl;
        }
        arch_vehiculos.close();
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}

void leer_datos_especifico_vehiculos(int indice) {
    ifstream arch_vehiculos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/vehiculos.csv", ios::in);
    if (arch_vehiculos.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_vehiculos, linea)) {
            if (contador == indice) {
                stringstream ss(linea);
                vehiculos vehiculo;
                string rentado_str;
                getline(ss, vehiculo.modelo, ',');
                getline(ss, vehiculo.marca, ',');
                getline(ss, vehiculo.placa, ',');
                getline(ss, vehiculo.color, ',');
                ss >> vehiculo.ano;
                ss.ignore();
                ss >> vehiculo.kilometraje;
                ss.ignore();
                getline(ss, rentado_str, ',');
                vehiculo.rentado = (rentado_str == "true");
                getline(ss, vehiculo.motor, ',');
                ss >> vehiculo.precio_renta;
                ss.ignore();
                ss >> vehiculo.ced_cliente;
                ss.ignore();
                getline(ss, vehiculo.fecha_de_entrega, ',');

                cout << "Modelo: " << vehiculo.modelo << "\n"
                     << "Marca: " << vehiculo.marca << "\n"
                     << "Placa: " << vehiculo.placa << "\n"
                     << "Color: " << vehiculo.color << "\n"
                     << "Año: " << vehiculo.ano << "\n"
                     << "Kilometraje: " << vehiculo.kilometraje << "\n"
                     << "Rentado: " << (vehiculo.rentado ? "Sí" : "No") << "\n"
                     << "Motor: " << vehiculo.motor << "\n"
                     << "Precio de Renta: " << vehiculo.precio_renta << "\n"
                     << "Cédula del Cliente: " << vehiculo.ced_cliente << "\n"
                     << "Fecha de Entrega: " << vehiculo.fecha_de_entrega << "\n";
                arch_vehiculos.close();
                return;
            }
            contador++;
        }
        cout << "Indice no encontrado." << endl;
        arch_vehiculos.close();
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}

void busqeuda_consulta_vehiculos(){

}

//Funciones para manejar las opciones del menu de Clientes

void borrar_fila_clientes(int indice) {
    ifstream arch_clientes("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv", ios::in);
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

        // Reemplazar el archivo original con el archivo temporal
        remove("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv");
        rename("temp.csv", "/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv");

        cout << "Fila eliminada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void actualizar_fila_completa_clientes(int indice, const clientes& nuevo_cliente) {
    ifstream arch_clientes("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_clientes.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_clientes, linea)) {
            if (contador == indice) {
                temp << nuevo_cliente.cedula << ","
                     << nuevo_cliente.nombre << ","
                     << nuevo_cliente.apellido << ","
                     << nuevo_cliente.email << ","
                     << nuevo_cliente.cantidad_de_vehiculos << ","
                     << nuevo_cliente.direccion << ","
                     << (nuevo_cliente.activo ? "true" : "false") << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_clientes.close();
        temp.close();

        // Reemplazar el archivo original con el archivo temporal
        remove("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv");
        rename("temp.csv", "/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv");

        cout << "Fila actualizada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void actualizar_dato_especifico_clientes(int indice, int campo, const string& nuevo_valor) {
    ifstream arch_clientes("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_clientes.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_clientes, linea)) {
            if (contador == indice) {
                stringstream ss(linea);
                clientes cliente;
                string cedula_str, cantidad_de_vehiculos_str, activo_str;

                getline(ss, cedula_str, ',');
                cliente.cedula = stoi(cedula_str);

                getline(ss, cliente.nombre, ',');
                getline(ss, cliente.apellido, ',');
                getline(ss, cliente.email, ',');

                getline(ss, cantidad_de_vehiculos_str, ',');
                cliente.cantidad_de_vehiculos = stoi(cantidad_de_vehiculos_str);

                getline(ss, cliente.direccion, ',');

                getline(ss, activo_str, ',');
                cliente.activo = (activo_str == "true");

                switch (campo) {
                    case 1: cliente.cedula = stoi(nuevo_valor); break;
                    case 2: cliente.nombre = nuevo_valor; break;
                    case 3: cliente.apellido = nuevo_valor; break;
                    case 4: cliente.email = nuevo_valor; break;
                    case 5: cliente.cantidad_de_vehiculos = stoi(nuevo_valor); break;
                    case 6: cliente.direccion = nuevo_valor; break;
                    case 7: cliente.activo = (nuevo_valor == "si"); break;
                }

                temp << cliente.cedula << ","
                     << cliente.nombre << ","
                     << cliente.apellido << ","
                     << cliente.email << ","
                     << cliente.cantidad_de_vehiculos << ","
                     << cliente.direccion << ","
                     << (cliente.activo ? "true" : "false") << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_clientes.close();
        temp.close();

        // Reemplazar el archivo original con el archivo temporal
        remove("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv");
        rename("temp.csv", "/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv");

        cout << "Dato actualizado correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void agregar_fila_nueva_clientes(const clientes& nuevo_cliente) {
    ofstream arch_clientes("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv", ios::app);

    if (arch_clientes.is_open()) {
        arch_clientes << nuevo_cliente.cedula << ","
                      << nuevo_cliente.nombre << ","
                      << nuevo_cliente.apellido << ","
                      << nuevo_cliente.email << ","
                      << nuevo_cliente.cantidad_de_vehiculos << ","
                      << nuevo_cliente.direccion << ","
                      << (nuevo_cliente.activo ? "true" : "false") << endl;
        arch_clientes.close();
        cout << "Fila agregada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void leer_archivo_completo_clientes(){
    ifstream arch_clientes("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv", ios::in);

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
    ifstream arch_clientes("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/clientes.csv", ios::in);
    if (arch_clientes.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_clientes, linea)) {
            if (contador == indice) {
                stringstream ss(linea);
                clientes cliente;
                string cedula_str, cantidad_de_vehiculos_str, activo_str;
                
                getline(ss, cedula_str, ',');
                cliente.cedula = stoi(cedula_str);
                
                getline(ss, cliente.nombre, ',');
                getline(ss, cliente.apellido, ',');
                getline(ss, cliente.email, ',');
                
                getline(ss, cantidad_de_vehiculos_str, ',');
                cliente.cantidad_de_vehiculos = stoi(cantidad_de_vehiculos_str);
                
                getline(ss, cliente.direccion, ',');
                getline(ss, activo_str, ',');
                cliente.activo = (activo_str == "true");

                cout << "Cédula: " << cliente.cedula << "\n"
                     << "Cantidad de Vehículos: " << cliente.cantidad_de_vehiculos << "\n"
                     << "Nombre: " << cliente.nombre << "\n"
                     << "Apellido: " << cliente.apellido << "\n"
                     << "Email: " << cliente.email << "\n"
                     << "Dirección: " << cliente.direccion << "\n"
                     << "Activo: " << (cliente.activo ? "Sí" : "No") << "\n";
                arch_clientes.close();
                return;
            }
            contador++;
        }
        cout << "Indice no encontrado." << endl;
        arch_clientes.close();
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void busqeuda_consulta_clientes(){

}

//Funciones para manejar las opciones del menu de Repuestos

void borrar_fila_repuestos(int indice) {
    ifstream arch_repuestos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv", ios::in);
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

        // Reemplazar el archivo original con el archivo temporal
        remove("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv");
        rename("temp.csv", "/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv");

        cout << "Fila eliminada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void actualizar_fila_completa_repuestos(int indice, const repuestos& nuevo_repuesto) {
    ifstream arch_repuestos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_repuestos.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_repuestos, linea)) {
            if (contador == indice) {
                temp << nuevo_repuesto.modelo << ","
                     << nuevo_repuesto.marca << ","
                     << nuevo_repuesto.nombre << ","
                     << nuevo_repuesto.modelo_carro << ","
                     << nuevo_repuesto.ano_carro << ","
                     << nuevo_repuesto.precio << ","
                     << nuevo_repuesto.existencias << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_repuestos.close();
        temp.close();

        // Reemplazar el archivo original con el archivo temporal
        remove("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv");
        rename("temp.csv", "/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv");

        cout << "Fila actualizada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void actualizar_dato_especifico_repuestos(int indice, int campo, const string& nuevo_valor) {
    ifstream arch_repuestos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv", ios::in);
    ofstream temp("temp.csv", ios::out);

    if (arch_repuestos.is_open() && temp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_repuestos, linea)) {
            if (contador == indice) {
                stringstream ss(linea);
                repuestos repuesto;
                getline(ss, repuesto.modelo, ',');
                getline(ss, repuesto.marca, ',');
                getline(ss, repuesto.nombre, ',');
                getline(ss, repuesto.modelo_carro, ',');
                ss >> repuesto.ano_carro;
                ss.ignore();
                ss >> repuesto.precio;
                ss.ignore();
                ss >> repuesto.existencias;

                switch (campo) {
                    case 1: repuesto.modelo = nuevo_valor; break;
                    case 2: repuesto.marca = nuevo_valor; break;
                    case 3: repuesto.nombre = nuevo_valor; break;
                    case 4: repuesto.modelo_carro = nuevo_valor; break;
                    case 5: repuesto.ano_carro = stoi(nuevo_valor); break;
                    case 6: repuesto.precio = stoi(nuevo_valor); break;
                    case 7: repuesto.existencias = stoi(nuevo_valor); break;
                }

                temp << repuesto.modelo << ","
                     << repuesto.marca << ","
                     << repuesto.nombre << ","
                     << repuesto.modelo_carro << ","
                     << repuesto.ano_carro << ","
                     << repuesto.precio << ","
                     << repuesto.existencias << endl;
            } else {
                temp << linea << endl;
            }
            contador++;
        }
        arch_repuestos.close();
        temp.close();

        // Reemplazar el archivo original con el archivo temporal
        remove("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv");
        rename("temp.csv", "/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv");

        cout << "Dato actualizado correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void agregar_fila_nueva_repuestos(const repuestos& nuevo_repuesto) {
    ofstream arch_repuestos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv", ios::app);

    if (arch_repuestos.is_open()) {
        arch_repuestos << nuevo_repuesto.modelo << ","
                       << nuevo_repuesto.marca << ","
                       << nuevo_repuesto.nombre << ","
                       << nuevo_repuesto.modelo_carro << ","
                       << nuevo_repuesto.ano_carro << ","
                       << nuevo_repuesto.precio << ","
                       << nuevo_repuesto.existencias << endl;
        arch_repuestos.close();
        cout << "Fila agregada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void leer_archivo_completo_repuestos(){
    ifstream arch_repuestos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv", ios::in);

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
    ifstream arch_repuestos("/Users/luismi/Documents/Uru/4to trimestre/Programacion2/Proyecto_parte_1/bin/repuestos.csv", ios::in);
    if (arch_repuestos.is_open()) {
        string linea;
        int contador = 0;
        while (getline(arch_repuestos, linea)) {
            if (contador == indice) {
                stringstream ss(linea);
                repuestos repuesto;
                string ano_carro_str, precio_str, existencias_str;
                
                getline(ss, repuesto.modelo, ',');
                getline(ss, repuesto.marca, ',');
                getline(ss, repuesto.nombre, ',');
                getline(ss, repuesto.modelo_carro, ',');
                
                getline(ss, ano_carro_str, ',');
                repuesto.ano_carro = stoi(ano_carro_str);
                
                getline(ss, precio_str, ',');
                repuesto.precio = stoi(precio_str);
                
                getline(ss, existencias_str, ',');
                repuesto.existencias = stoi(existencias_str);

                cout << "Modelo: " << repuesto.modelo << "\n"
                     << "Marca: " << repuesto.marca << "\n"
                     << "Nombre: " << repuesto.nombre << "\n"
                     << "Modelo del Carro: " << repuesto.modelo_carro << "\n"
                     << "Año del Carro: " << repuesto.ano_carro << "\n"
                     << "Precio: " << repuesto.precio << "\n"
                     << "Existencias: " << repuesto.existencias << "\n";
                arch_repuestos.close();
                return;
            }
            contador++;
        }
        cout << "Indice no encontrado." << endl;
        arch_repuestos.close();
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void busqeuda_consulta_repuestos(){

}

//funciones generales

void ir_a_menu_principal(){

}

void terminar_programa(){

}

void confirmar_accion(){

}

void mostrarVehiculo(const vehiculos& vehiculo) {
    cout << "Modelo: " << vehiculo.modelo << ", Marca: " << vehiculo.marca << ", Placa: " << vehiculo.placa
         << ", Color: " << vehiculo.color << ", Año: " << vehiculo.ano << ", Precio de renta: " << vehiculo.precio_renta << "\n";
}

void mostrarCliente(const clientes& cliente) {
    cout << "Cédula: " << cliente.cedula << ", Nombre: " << cliente.nombre << ", Apellido: " << cliente.apellido
         << ", Email: " << cliente.email << ", Dirección: " << cliente.direccion << "\n";
}

void mostrarRepuesto(const repuestos& repuesto) {
    cout << "Nombre: " << repuesto.nombre << ", Modelo: " << repuesto.modelo << ", Año del carro: " << repuesto.ano_carro
         << ", Precio: " << repuesto.precio << ", Existencias: " << repuesto.existencias << "\n";
}

void leerCSVVehiculos(const string& nombreArchivo, vehiculos vehiculosArr[], int& totalVehiculos, int maxVehiculos) {
    ifstream archivo(nombreArchivo);
    string linea;

    totalVehiculos = 0;
    do {
        if (getline(archivo, linea)) {
            stringstream sstream(linea);
            vehiculos& vehiculo = vehiculosArr[totalVehiculos];
            string temp;

            getline(sstream, vehiculo.modelo, ',');
            getline(sstream, vehiculo.marca, ',');
            getline(sstream, vehiculo.placa, ',');
            getline(sstream, vehiculo.color, ',');
            getline(sstream, vehiculo.motor, ',');
            getline(sstream, vehiculo.fecha_de_entrega, ',');

            getline(sstream, temp, ',');
            vehiculo.ano = stoi(temp);

            getline(sstream, temp, ',');
            vehiculo.kilometraje = stoi(temp);

            getline(sstream, temp, ',');
            vehiculo.precio_renta = stoi(temp);

            getline(sstream, temp, ',');
            vehiculo.ced_cliente = stoi(temp);

            getline(sstream, temp, ',');
            vehiculo.rentado = (temp == "1");

            totalVehiculos++;
        }
    } while (archivo && totalVehiculos < maxVehiculos);
}

void leerCSVClientes(const string& nombreArchivo, clientes clientesArr[], int& totalClientes, int maxClientes) {
    ifstream archivo(nombreArchivo);
    string linea;

    totalClientes = 0;
    do {
        if (getline(archivo, linea)) {
            stringstream sstream(linea);
            clientes& cliente = clientesArr[totalClientes];
            string temp;

            getline(sstream, temp, ',');
            cliente.cedula = stoi(temp);

            getline(sstream, cliente.nombre, ',');
            getline(sstream, cliente.apellido, ',');
            getline(sstream, cliente.email, ',');
            getline(sstream, cliente.direccion, ',');

            getline(sstream, temp, ',');
            cliente.cantidad_de_vehiculos = stoi(temp);

            getline(sstream, temp, ',');
            cliente.activo = (temp == "1");

            totalClientes++;
        }
    } while (archivo && totalClientes < maxClientes);
}

void leerCSVRepuestos(const string& nombreArchivo, repuestos repuestosArr[], int& totalRepuestos, int maxRepuestos) {
    ifstream archivo(nombreArchivo);
    string linea;

    totalRepuestos = 0;
    do {
        if (getline(archivo, linea)) {
            stringstream sstream(linea);
            repuestos& repuesto = repuestosArr[totalRepuestos];
            string temp;

            getline(sstream, repuesto.modelo, ',');
            getline(sstream, repuesto.marca, ',');
            getline(sstream, repuesto.nombre, ',');
            getline(sstream, repuesto.modelo_carro, ',');

            getline(sstream, temp, ',');
            repuesto.ano_carro = stoi(temp);

            getline(sstream, temp, ',');
            repuesto.precio = stoi(temp);

            getline(sstream, temp, ',');
            repuesto.existencias = stoi(temp);

            totalRepuestos++;
        }
    } while (archivo && totalRepuestos < maxRepuestos);
}

void realizarConsultas(vehiculos vehiculosArr[], int totalVehiculos, clientes clientesArr[], int totalClientes, repuestos repuestosArr[], int totalRepuestos) {
    int opcion;
    do {
        cout << "\n--- Menú de Consultas ---\n";
        cout << "1. Consultar Vehículo\n";
        cout << "2. Consultar Cliente\n";
        cout << "3. Consultar Repuesto\n";
        cout << "4. Regresar al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string placaBuscada;
                cout << "Ingrese la placa del vehículo: ";
                cin >> placaBuscada;
                bool encontrado = false;
                for (int i = 0; i < totalVehiculos; i++) {
                    if (vehiculosArr[i].placa == placaBuscada) {
                        mostrarVehiculo(vehiculosArr[i]);
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Vehículo no encontrado.\n";
                }
                break;
            }
            case 2: {
                int cedulaBuscada;
                cout << "Ingrese la cédula del cliente: ";
                cin >> cedulaBuscada;
                bool encontrado = false;
                for (int i = 0; i < totalClientes; i++) {
                    if (clientesArr[i].cedula == cedulaBuscada) {
                        mostrarCliente(clientesArr[i]);
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Cliente no encontrado.\n";
                }
                break;
            }
            case 3: {
                string nombreRepuestoBuscado;
                cout << "Ingrese el nombre del repuesto: ";
                cin >> nombreRepuestoBuscado;
                bool encontrado = false;
                for (int i = 0; i < totalRepuestos; i++) {
                    if (repuestosArr[i].nombre == nombreRepuestoBuscado) {
                        mostrarRepuesto(repuestosArr[i]);
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Repuesto no encontrado.\n";
                }
                break;
            }
            case 4:
                cout << "Regresando al menú principal...\n";
                break;

            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 4);
}
int main(){
    int Archivos_csv, indice, campo;
    string nuevo_valor;
    bool opcion_valida = false;

    while(!opcion_valida){
        mostrarMenuPrincipal();
        cin >> Archivos_csv;

        switch(Archivos_csv){
            case 1:
                opcion_valida = true;
                int opcion_vehiculo;
                mostrarMenuVehiculos();
                cin >> opcion_vehiculo;
                // Manejar opciones de vehiculos

                switch(opcion_vehiculo){
                    case 1: {
                        cout << "Ingrese el indice de la fila que desea eliminar: ";
                        cin >> indice;
                        borrar_fila_vehiculos(indice);
                        break;
                    }

                      case 2: {
                        vehiculos nuevo_vehiculo;
                        string rentado_str;

                        cout << "Ingrese la fila del vehiculo que quiere modificar: "; cin >> indice;
                        cout << "Ingrese los datos nuevos del vehiculo a modificar: \n";
                        cout << "Ingrese modelo: "; cin >> nuevo_vehiculo.modelo;
                        cout << "Ingrese marca: "; cin >> nuevo_vehiculo.marca;
                        cout << "Ingrese placa: "; cin >> nuevo_vehiculo.placa;
                        cout << "Ingrese color: "; cin >> nuevo_vehiculo.color;
                        cout << "Ingrese ano: "; cin >> nuevo_vehiculo.ano;
                        cout << "Ingrese kilometraje: "; cin >> nuevo_vehiculo.kilometraje;
                        cout << "Ingrese rentado (si/no): "; cin >> rentado_str;
                        nuevo_vehiculo.rentado = (rentado_str == "si");
                        cout << "Ingrese motor: "; cin >> nuevo_vehiculo.motor;
                        cout << "Ingrese precio de renta: "; cin >> nuevo_vehiculo.precio_renta;
                        cout << "Ingrese cedula del cliente: "; cin >> nuevo_vehiculo.ced_cliente;
                        cin.ignore(); 
                        cout << "Ingrese fecha de entrega (d/m/yyyy): "; getline(cin, nuevo_vehiculo.fecha_de_entrega);

                        actualizar_fila_completa_vehiculos(indice, nuevo_vehiculo);
                        break;
                    }

                    case 3: {
                        cout << "Ingrese la fila del vehiculo que quiere modificar: "; cin >> indice;
                        cout << "Ingrese el numero del campo que quiere modificar (1-11): \n";
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
                        cout << "Ingrese el dato actualizado: "; cin >> nuevo_valor;
                        actualizar_dato_especifico_vehiculos(indice, campo, nuevo_valor);
                        break;
                    }
                    
                    case 4: {
                        vehiculos nuevo_vehiculo;
                        string rentado_str;
                        cout << "Ingrese los datos del nuevo vehiculo: \n";
                        cout << "Ingrese modelo: "; cin >> nuevo_vehiculo.modelo; 
                        cout << "Ingrese marca: "; cin >> nuevo_vehiculo.marca; 
                        cout << "Ingrese placa: "; cin >> nuevo_vehiculo.placa; 
                        cout << "Ingrese color: "; cin >> nuevo_vehiculo.color; 
                        cout << "Ingrese ano (ej:1999): "; cin >> nuevo_vehiculo.ano; 
                        cout << "Ingrese kilometraje: "; cin >> nuevo_vehiculo.kilometraje; 
                        cout << "Ingrese rentado (si/no): "; cin >> rentado_str;
                        nuevo_vehiculo.rentado = (rentado_str == "si"); 
                        cout << "Ingrese motor: "; cin >> nuevo_vehiculo.motor; 
                        cout << "Ingrese precio de renta: "; cin >> nuevo_vehiculo.precio_renta; 
                        cout << "Ingrese cedula del cliente: "; cin >> nuevo_vehiculo.ced_cliente;
                        cout << "Ingrese fecha de entrega (d/m/yyyy): "; cin >> nuevo_vehiculo.fecha_de_entrega; 
                        agregar_fila_nueva_vehiculos(nuevo_vehiculo);
                        break;
                    }

                    case 5:{
                        leer_archivo_completo_vehiculos();
                        break;
                    }
                    case 6:{
                        cout << "Ingrese el indice del regidtro del vehiculo que desea leer: "; cin >> indice;
                        leer_datos_especifico_vehiculos(indice);
                        break;
                    }
                    case 7:
                    break;

                    case 8:
                    break;

                }

            break;


            case 2:
                opcion_valida = true;
                int opcion_clientes;
                mostrarMenuClientes();
                cin >> opcion_clientes;
                // Manejar opciones de clientes

                switch(opcion_clientes){
                    case 1: {
                        cout << "Ingrese el indice de la fila que desea eliminar: ";
                        cin >> indice;
                        borrar_fila_clientes(indice);
                        break;
                    }

                    case 2: {
                        clientes nuevo_cliente;
                        string activo_str;

                        cout << "Ingrese la fila del cliente que quiere modificar: "; cin >> indice;
                        cout << "Ingrese los datos nuevos del cliente a modificar: \n";
                        cout << "Ingrese cedula: "; cin >> nuevo_cliente.cedula;
                        cin.ignore(); // Ignorar el carácter de nueva línea pendiente
                        cout << "Ingrese nombre: "; getline(cin, nuevo_cliente.nombre);
                        cout << "Ingrese apellido: "; getline(cin, nuevo_cliente.apellido);
                        cout << "Ingrese email: "; cin >> nuevo_cliente.email;
                        cout << "Ingrese cantidad de vehiculos rentados: "; cin >> nuevo_cliente.cantidad_de_vehiculos;
                        cin.ignore(); // Ignorar el carácter de nueva línea pendiente
                        cout << "Ingrese direccion: "; getline(cin, nuevo_cliente.direccion);
                        cout << "Ingrese activo (si/no): "; cin >> activo_str;
                        nuevo_cliente.activo = (activo_str == "si");

                        actualizar_fila_completa_clientes(indice, nuevo_cliente);
                        break;
                    }

                    case 3: {
                        cout << "Ingrese la fila del cliente que quiere modificar: "; cin >> indice;
                        cout << "Ingrese el numero del campo que quiere modificar (1-7): \n";
                        cout << "1. Cédula\n";
                        cout << "2. Nombre\n";
                        cout << "3. Apellido\n";
                        cout << "4. Email\n";
                        cout << "5. Cantidad de Vehículos Rentados\n";
                        cout << "6. Dirección\n";
                        cout << "7. Activo (si/no)\n";
                        cout << "Ingrese valor: "; cin >> campo;
                        cout << "Ingrese el dato actualizado: "; cin >> nuevo_valor;
                        actualizar_dato_especifico_clientes(indice, campo, nuevo_valor);
                        break;
                    }
                    case 4: {
                        clientes nuevo_cliente;
                        string activo_str;
                        cout << "Ingrese los datos del nuevo cliente: \n";
                        cout << "Ingrese cedula: "; cin >> nuevo_cliente.cedula;
                        cin.ignore(); // Ignorar el carácter de nueva línea pendiente
                        cout << "Ingrese nombre: "; getline(cin, nuevo_cliente.nombre);
                        cout << "Ingrese apellido: "; getline(cin, nuevo_cliente.apellido);
                        cout << "Ingrese email: "; cin >> nuevo_cliente.email;
                        cout << "Ingrese cantidad de vehiculos rentados: "; cin >> nuevo_cliente.cantidad_de_vehiculos;
                        cin.ignore(); // Ignorar el carácter de nueva línea pendiente
                        cout << "Ingrese direccion: "; getline(cin, nuevo_cliente.direccion);
                        cout << "Ingrese activo (si/no): "; cin >> activo_str;
                        nuevo_cliente.activo = (activo_str == "si");
                        agregar_fila_nueva_clientes(nuevo_cliente);
                        break;
                    }

                    case 5:{
                        leer_archivo_completo_clientes();
                        break;
                    }
                    case 6:{
                        cout << "Ingrese el indice del registro del cliente que desea leer: ";
                        cin >> indice;
                        leer_datos_especifico_clientes(indice);
                    }    break;

                    case 7:
                    break;

                    case 8:
                    break;

                }

            break;

            case 3:
                opcion_valida = true;
                int opcion_repuestos;
                mostrarMenuRepuestos();
                cin >> opcion_repuestos;
                // Manejar opciones de repuestos

                switch(opcion_repuestos){
                    
                    case 1: {
                        cout << "Ingrese el indice de la fila que desea eliminar: ";
                        cin >> indice;
                        borrar_fila_repuestos(indice);
                        break;
                    }

                    case 2: {
                        repuestos nuevo_repuesto;

                        cout << "Ingrese la fila del repuesto que quiere modificar: "; cin >> indice;
                        cout << "Ingrese los datos nuevos del repuesto a modificar: \n";
                        cout << "Ingrese modelo: "; cin >> nuevo_repuesto.modelo;
                        cout << "Ingrese marca: "; cin >> nuevo_repuesto.marca;
                        cout << "Ingrese nombre: "; cin >> nuevo_repuesto.nombre;
                        cout << "Ingrese modelo del carro: "; cin >> nuevo_repuesto.modelo_carro;
                        cout << "Ingrese ano del carro: "; cin >> nuevo_repuesto.ano_carro;
                        cout << "Ingrese precio: "; cin >> nuevo_repuesto.precio;
                        cout << "Ingrese existencias: "; cin >> nuevo_repuesto.existencias;

                        actualizar_fila_completa_repuestos(indice, nuevo_repuesto);
                        break;
                    }

                   case 3: {
                        cout << "Ingrese la fila del repuesto que quiere modificar: "; cin >> indice;
                        cout << "Ingrese el numero del campo que quiere modificar (1-7): \n";
                        cout << "1. Modelo\n";
                        cout << "2. Marca\n";
                        cout << "3. Nombre\n";
                        cout << "4. Modelo del Carro\n";
                        cout << "5. Año del Carro\n";
                        cout << "6. Precio\n";
                        cout << "7. Existencias\n";
                        cin >> campo;
                        cout << "Ingrese el nuevo valor: "; cin >> nuevo_valor;
                        actualizar_dato_especifico_repuestos(indice, campo, nuevo_valor);
                        break;
                    }

                    case 4: {
                        repuestos nuevo_repuesto;
                        cout << "Ingrese los datos del nuevo repuesto: \n";
                        cout << "Ingrese modelo: "; cin >> nuevo_repuesto.modelo;
                        cout << "Ingrese marca: "; cin >> nuevo_repuesto.marca;
                        cout << "Ingrese nombre: "; cin >> nuevo_repuesto.nombre;
                        cout << "Ingrese modelo del carro: "; cin >> nuevo_repuesto.modelo_carro;
                        cout << "Ingrese ano del carro: "; cin >> nuevo_repuesto.ano_carro;
                        cout << "Ingrese precio: "; cin >> nuevo_repuesto.precio;
                        cout << "Ingrese existencias: "; cin >> nuevo_repuesto.existencias;
                        agregar_fila_nueva_repuestos(nuevo_repuesto);
                        break;
                    }

                    case 5:{
                        leer_archivo_completo_repuestos();
                        break;
                    }

                    case 6: {
                        cout << "Ingrese el indice del registro del repuesto que desea leer: ";
                        cin >> indice;
                        leer_datos_especifico_repuestos(indice);
                        break;
                    }

                    case 7:
                    break;

                    case 8:
                    break;

                }
            break;

            default:
                cout << "Se introdujo un valor no valido, intente de nuevo." << endl;
            break;
        }
    }
    const int MAX_VEHICULOS = 100;
    const int MAX_CLIENTES = 100;
    const int MAX_REPUESTOS = 100;
    vehiculos vehiculosArr[MAX_VEHICULOS];
    clientes clientesArr[MAX_CLIENTES];
    repuestos repuestosArr[MAX_REPUESTOS];
    int totalVehiculos, totalClientes, totalRepuestos;

    leerCSVVehiculos("bin/vehiculos.csv", vehiculosArr, totalVehiculos, MAX_VEHICULOS);
    leerCSVClientes("bin/clientes.csv", clientesArr, totalClientes, MAX_CLIENTES);
    leerCSVRepuestos("bin/repuestos.csv", repuestosArr, totalRepuestos, MAX_REPUESTOS);

    realizarConsultas(vehiculosArr, totalVehiculos, clientesArr, totalClientes, repuestosArr, totalRepuestos);

    return 0;
}