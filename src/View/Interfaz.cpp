#include <iostream>
using namespace std;

void ir_a_menu_principal(bool &opcion_valida) {
    opcion_valida = true;
}

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

void terminar_programa(){
    cout << "Terminando programa..." << endl;
    exit(0);
}