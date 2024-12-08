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
         << "1. Seleccionar Vehiculo\n"
         << "\n"
         << "--Actualizar datos--\n"
         << "2. Actualizar Vehiculo\n"
         << "3. Actualizar dato especifico del Vehiculo\n"
         << "\n"
         << "--Agregar datos--\n"
         << "4. Agregar Vehiculo\n"
         << "\n"
         << "--Leer datos--\n"
         << "5. Leer todos los Vehiculos\n"
         << "6. Leer Vehiculo\n"
         << "\n"
         << "--Busqueda/Consulta especifica--\n"
         << "7. Busqueda del Vehiculo\n"
         << "\n"
         << "8. Ir a menu principal\n"
         << "9. Terminar programa\n"
         << "Ingrese opcion: ";
}

void mostrarMenuClientes() {
     cout << "(Archivo Clientes)\n"
         << "--Borrar datos--\n"
         << "1. Seleccionar Cliente\n"
         << "\n"
         << "--Actualizar datos--\n"
         << "2. Actualizar Cliente\n"
         << "3. Actualizar dato especifico del Cliente\n"
         << "\n"
         << "--Agregar datos--\n"
         << "4. Agregar Cliente\n"
         << "\n"
         << "--Leer datos--\n"
         << "5. Leer todos los Clientes\n"
         << "6. Leer Cliente\n"
         << "\n"
         << "--Busqueda/Consulta especifica--\n"
         << "7. Busqueda del Cliente\n"
         << "\n"
         << "8. Ir a menu principal\n"
         << "9. Terminar programa\n"
         << "Ingrese opcion: ";
}

void mostrarMenuRepuestos() {
     cout << "(Archivo Repuestos)\n"
         << "--Borrar datos--\n"
         << "1. Seleccionar Repuesto\n"
         << "\n"
         << "--Actualizar datos--\n"
         << "2. Actualizar Repuesto\n"
         << "3. Actualizar dato especifico del Repuesto\n"
         << "\n"
         << "--Agregar datos--\n"
         << "4. Agregar Repuesto\n"
         << "\n"
         << "--Leer datos--\n"
         << "5. Leer todos los Repuestos\n"
         << "6. Leer Repuesto\n"
         << "\n"
         << "--Busqueda/Consulta especifica--\n"
         << "7. Busqueda del Repuesto\n"
         << "\n"
         << "8. Ir a menu principal\n"
         << "9. Terminar programa\n"
         << "Ingrese opcion: ";
}


//Funciones para manejar las opciones del menu de Vehiculos

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

void actualizar_fila_completa_vehiculos(int indice, const vehiculos& nuevo_vehiculo) {
    ifstream arch_vehiculos("../bin/vehiculos.csv", ios::in);
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
        remove("../bin/vehiculos.csv");
        rename("temp.csv", "../bin/vehiculos.csv");

        cout << "Dato actualizado correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
    }
}

void agregar_fila_nueva_vehiculos(const vehiculos& nuevo_vehiculo) {
    ofstream arch_vehiculos("../bin/vehiculos.csv", ios::app);

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
    ifstream arch_vehiculos("../bin/vehiculos.csv", ios::in);

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
    ifstream arch_vehiculos("../bin/vehiculos.csv", ios::in);
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

void busqueda_consulta_vehiculos(){
    ifstream arch_vehiculos("../bin/vehiculos.csv", ios::in);
    if (!arch_vehiculos.is_open()) {
        cerr << "No se pudo abrir el archivo vehiculos.csv" << endl;
        return;
    }

    int campo;
    string valor_busqueda;
    cout << "Ingrese el numero del campo por el cual desea buscar (1-11): \n";
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
    cout << "Ingrese el valor de busqueda: "; cin.ignore(); getline(cin, valor_busqueda);

    string linea;
    bool encontrado = false;
    while (getline(arch_vehiculos, linea)) {
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

        bool coincide = false;
        switch (campo) {
            case 1: coincide = (vehiculo.modelo == valor_busqueda); break;
            case 2: coincide = (vehiculo.marca == valor_busqueda); break;
            case 3: coincide = (vehiculo.placa == valor_busqueda); break;
            case 4: coincide = (vehiculo.color == valor_busqueda); break;
            case 5: coincide = (to_string(vehiculo.ano) == valor_busqueda); break;
            case 6: coincide = (to_string(vehiculo.kilometraje) == valor_busqueda); break;
            case 7: coincide = (vehiculo.rentado == (valor_busqueda == "si")); break;
            case 8: coincide = (vehiculo.motor == valor_busqueda); break;
            case 9: coincide = (to_string(vehiculo.precio_renta) == valor_busqueda); break;
            case 10: coincide = (to_string(vehiculo.ced_cliente) == valor_busqueda); break;
            case 11: coincide = (vehiculo.fecha_de_entrega == valor_busqueda); break;
        }

        if (coincide) {
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
                 << "Fecha de Entrega: " << vehiculo.fecha_de_entrega << "\n"
                 << "-----------------------------\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron coincidencias." << endl;
    }

    arch_vehiculos.close();
}

//Funciones para manejar las opciones del menu de Clientes

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

        // Reemplazar el archivo original con el archivo temporal
        remove("../bin/clientes.csv");
        rename("temp.csv", "../bin/clientes.csv");

        cout << "Fila eliminada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void actualizar_fila_completa_clientes(int indice, const clientes& nuevo_cliente) {
    ifstream arch_clientes("../bin/clientes.csv", ios::in);
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
        remove("../bin/clientes.csv");
        rename("temp.csv", "../bin/clientes.csv");

        cout << "Dato actualizado correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
    }
}

void agregar_fila_nueva_clientes(const clientes& nuevo_cliente) {
    ofstream arch_clientes("../bin/clientes.csv", ios::app);

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

void busqueda_consulta_clientes(){
    ifstream arch_clientes("../bin/clientes.csv", ios::in);
    if (!arch_clientes.is_open()) {
        cerr << "No se pudo abrir el archivo clientes.csv" << endl;
        return;
    }

    // Ignorar la primera línea (cabecera)
    string cabecera;
    getline(arch_clientes, cabecera);

    int campo;
    string valor_busqueda;
    cout << "Ingrese el numero del campo por el cual desea buscar (1-7): \n";
    cout << "1. Cédula\n";
    cout << "2. Nombre\n";
    cout << "3. Apellido\n";
    cout << "4. Email\n";
    cout << "5. Cantidad de Vehículos Rentados\n";
    cout << "6. Dirección\n";
    cout << "7. Activo (si/no)\n";
    cout << "Ingrese valor: "; cin >> campo;
    cout << "Ingrese el valor de busqueda: "; cin.ignore(); getline(cin, valor_busqueda);

    string linea;
    bool encontrado = false;
    while (getline(arch_clientes, linea)) {
        stringstream ss(linea);
        clientes cliente;
        string cedula_str, cantidad_de_vehiculos_str, activo_str;
        getline(ss, cedula_str, ',');
        try {
            cliente.cedula = stoi(cedula_str);
        } catch (const invalid_argument& e) {
            cerr << "Error de conversión de cédula: " << e.what() << " en línea: " << linea << endl;
            continue;
        }
        getline(ss, cliente.nombre, ',');
        getline(ss, cliente.apellido, ',');
        getline(ss, cliente.email, ',');
        getline(ss, cantidad_de_vehiculos_str, ',');
        try {
            cliente.cantidad_de_vehiculos = stoi(cantidad_de_vehiculos_str);
        } catch (const invalid_argument& e) {
            cerr << "Error de conversión de cantidad de vehículos: " << e.what() << " en línea: " << linea << endl;
            continue;
        }
        getline(ss, cliente.direccion, ',');
        getline(ss, activo_str, ',');
        cliente.activo = (activo_str == "true");

        bool coincide = false;
        try {
            switch (campo) {
                case 1: coincide = (to_string(cliente.cedula) == valor_busqueda); break;
                case 2: coincide = (cliente.nombre == valor_busqueda); break;
                case 3: coincide = (cliente.apellido == valor_busqueda); break;
                case 4: coincide = (cliente.email == valor_busqueda); break;
                case 5: coincide = (to_string(cliente.cantidad_de_vehiculos) == valor_busqueda); break;
                case 6: coincide = (cliente.direccion == valor_busqueda); break;
                case 7: coincide = (cliente.activo == (valor_busqueda == "si")); break;
                default: throw invalid_argument("Campo no válido");
            }
        } catch (const invalid_argument& e) {
            cerr << "Error de conversión: " << e.what() << " en línea: " << linea << endl;
            continue;
        }

        if (coincide) {
            cout << "Cédula: " << cliente.cedula << "\n"
                 << "Nombre: " << cliente.nombre << "\n"
                 << "Apellido: " << cliente.apellido << "\n"
                 << "Email: " << cliente.email << "\n"
                 << "Cantidad de Vehículos Rentados: " << cliente.cantidad_de_vehiculos << "\n"
                 << "Dirección: " << cliente.direccion << "\n"
                 << "Activo: " << (cliente.activo ? "Sí" : "No") << "\n"
                 << "-----------------------------\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron coincidencias." << endl;
    }

    arch_clientes.close();
}

//Funciones para manejar las opciones del menu de Repuestos

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

        // Reemplazar el archivo original con el archivo temporal
        remove("../bin/repuestos.csv");
        rename("temp.csv", "../bin/repuestos.csv");

        cout << "Fila eliminada correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void actualizar_fila_completa_repuestos(int indice, const repuestos& nuevo_repuesto) {
    ifstream arch_repuestos("../bin/repuestos.csv", ios::in);
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
        remove("../bin/repuestos.csv");
        rename("temp.csv", "../bin/repuestos.csv");

        cout << "Dato actualizado correctamente." << endl;
    } else {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
    }
}

void agregar_fila_nueva_repuestos(const repuestos& nuevo_repuesto) {
    ofstream arch_repuestos("../bin/repuestos.csv", ios::app);

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

void busqueda_consulta_repuestos(){
    ifstream arch_repuestos("../bin/repuestos.csv", ios::in);
    if (!arch_repuestos.is_open()) {
        cerr << "No se pudo abrir el archivo repuestos.csv" << endl;
        return;
    }

    int campo;
    string valor_busqueda;
    cout << "Ingrese el numero del campo por el cual desea buscar (1-7): \n";
    cout << "1. Modelo\n";
    cout << "2. Marca\n";
    cout << "3. Nombre\n";
    cout << "4. Modelo del Carro\n";
    cout << "5. Año del Carro\n";
    cout << "6. Precio\n";
    cout << "7. Existencias\n";
    cout << "Ingrese valor: "; cin >> campo;
    cout << "Ingrese el valor de busqueda: "; cin.ignore(); getline(cin, valor_busqueda);

    string linea;
    bool encontrado = false;
    while (getline(arch_repuestos, linea)) {
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

        bool coincide = false;
        switch (campo) {
            case 1: coincide = (repuesto.modelo == valor_busqueda); break;
            case 2: coincide = (repuesto.marca == valor_busqueda); break;
            case 3: coincide = (repuesto.nombre == valor_busqueda); break;
            case 4: coincide = (repuesto.modelo_carro == valor_busqueda); break;
            case 5: coincide = (to_string(repuesto.ano_carro) == valor_busqueda); break;
            case 6: coincide = (to_string(repuesto.precio) == valor_busqueda); break;
            case 7: coincide = (to_string(repuesto.existencias) == valor_busqueda); break;
        }

        if (coincide) {
            cout << "Modelo: " << repuesto.modelo << "\n"
                 << "Marca: " << repuesto.marca << "\n"
                 << "Nombre: " << repuesto.nombre << "\n"
                 << "Modelo del Carro: " << repuesto.modelo_carro << "\n"
                 << "Año del Carro: " << repuesto.ano_carro << "\n"
                 << "Precio: " << repuesto.precio << "\n"
                 << "Existencias: " << repuesto.existencias << "\n"
                 << "-----------------------------\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron coincidencias." << endl;
    }

    arch_repuestos.close();
}

//funciones generales

void ir_a_menu_principal(bool &opcion_valida) {
    opcion_valida = true;
}

void terminar_programa(){
    cout << "Terminando programa..." << endl;
    exit(0);
}

bool confirmar_accion() {
    string confirmacion;
    cout << "¿Está seguro de que desea realizar esta acción? (si/no): ";
    cin >> confirmacion;
    return (confirmacion == "si" || confirmacion == "Si");
}

int main(){
int Archivos_csv,indice, campo;
    string nuevo_valor;
    bool opcion_valida = true;

        while (true) {
        opcion_valida = false;
        while(!opcion_valida){
            mostrarMenuPrincipal();
            cin >> Archivos_csv;

            switch(Archivos_csv){
                case 1:
                    opcion_valida = true;
                    while (opcion_valida) {
                        int opcion_vehiculo;
                        mostrarMenuVehiculos();
                        cin >> opcion_vehiculo;
                        // Manejar opciones de vehiculos

                    switch(opcion_vehiculo){
                        case 1: {
                            if (confirmar_accion()) {
                                        cout << "Ingrese el indice de la fila que desea eliminar: ";
                                        cin >> indice;
                                        borrar_fila_vehiculos(indice);
                                    }
                                    break;
                            }

                            case 2: {
                                if (confirmar_accion()) {
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
                                    } 
                                break;
                                
                            }

                            case 3: {
                                if (confirmar_accion()) {
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
                                    }
                                break;
                            }
                            
                            case 4: {
                                if (confirmar_accion()) {
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
                                        cin.ignore();
                                        cout << "Ingrese fecha de entrega (d/m/yyyy): "; cin >> nuevo_vehiculo.fecha_de_entrega; 
                                        agregar_fila_nueva_vehiculos(nuevo_vehiculo);
                                    } 
                                break;
                            }

                            case 5:{
                                if (confirmar_accion()) {
                                        leer_archivo_completo_vehiculos();
                                    } 
                                break;
                            }
                            case 6:{
                                if (confirmar_accion()) {
                                    cout << "Ingrese el indice del regidtro del vehiculo que desea leer: "; cin >> indice;
                                        leer_datos_especifico_vehiculos(indice);
                                    } 
                                break;
                            }

                            case 7:{
                                if(confirmar_accion()){
                                    busqueda_consulta_vehiculos();
                                }
                                    break;
                            }

                            case 8:{
                                    ir_a_menu_principal(opcion_valida);
                                break;
                            }

                            case 9:{
                                if(confirmar_accion()){
                                    terminar_programa();
                                }
                                break;
                            }
                        }
                    }


                break;
            

                case 2:
                    opcion_valida = true;
                    while (opcion_valida) {
                        int opcion_clientes;
                        mostrarMenuClientes();
                        cin >> opcion_clientes;
                        // Manejar opciones de clientes

                        switch(opcion_clientes){
                            case 1: {
                                if (confirmar_accion()) {
                                        cout << "Ingrese el indice de la fila que desea eliminar: ";
                                        cin >> indice;
                                        borrar_fila_clientes(indice);
                                    } 
                                break;
                            }

                            case 2: {
                                if (confirmar_accion()) {
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
                                    } 
                                break;
                            }

                            case 3: {
                                if (confirmar_accion()) {
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
                                    } 
                                break;
                            }
                            case 4: {
                                if (confirmar_accion()) {
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
                                    } 
                                break;
                            }

                            case 5:{
                                if (confirmar_accion()) {
                                        leer_archivo_completo_clientes();
                                    } else {
                                        ir_a_menu_principal(opcion_valida);
                                    }
                                
                                break;
                            }
                            case 6:{
                                if (confirmar_accion()) {
                                        cout << "Ingrese el indice del registro del cliente que desea leer: ";
                                        cin >> indice;
                                        leer_datos_especifico_clientes(indice);
                                    } 
                            }    break;

                            case 7:{
                                if(confirmar_accion()){
                                    busqueda_consulta_clientes();
                                }
                                break;
                            }

                            case 8:{
                                    ir_a_menu_principal(opcion_valida);
                                break;
                            } 

                            case 9:{
                                if(confirmar_accion()){
                                    terminar_programa();
                                }
                                break;
                            } 
                        }    
                    }

                break;

                case 3:
                    opcion_valida = true;
                    while (opcion_valida) {
                        int opcion_repuestos;
                        mostrarMenuRepuestos();
                        cin >> opcion_repuestos;
                        // Manejar opciones de repuestos

                        switch(opcion_repuestos){
                            
                            case 1: {
                                if (confirmar_accion()) {
                                        cout << "Ingrese el indice de la fila que desea eliminar: ";
                                        cin >> indice;
                                        borrar_fila_repuestos(indice);
                                    } 
                                break;
                            }

                            case 2: {
                                if (confirmar_accion()) {
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
                                    } 
                                break;
                            }

                        case 3: {
                                if (confirmar_accion()) {
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
                                    } 
                                break;
                            }

                            case 4: {
                                if (confirmar_accion()) {
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
                                    } 
                                break;
                            

                            case 5:{
                                if (confirmar_accion()) {
                                        leer_archivo_completo_repuestos();
                                    } 
                                break;
                            }

                            case 6: {
                                if (confirmar_accion()) {
                                        cout << "Ingrese el indice del registro del repuesto que desea leer: ";
                                        cin >> indice;
                                        leer_datos_especifico_repuestos(indice);
                                    } 
                                break;
                            }

                            case 7:{
                                if(confirmar_accion()){
                                        busqueda_consulta_repuestos();
                                }
                                break;
                            }

                            case 8:{
                                    ir_a_menu_principal(opcion_valida);
                                break;
                            } 

                            case 9:{
                                if(confirmar_accion()){
                                    terminar_programa();
                                }
                                break;
                            } 
                        }    
                    }
                break;

                default:
                    cout << "Se introdujo un valor no valido, intente de nuevo." << endl;
                break;
            }
    
            return 0;
        
            }
        }
    }
}