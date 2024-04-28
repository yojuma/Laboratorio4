#include "class_3.h"

using namespace std;

//class base Producto
int Producto::getCantidadInventario3(){
    return cantidadInventario;
}

void Producto::reducirInventario3(int cantidad){
    cantidadInventario -= cantidad;
}

void Comestible::mostrarDetalles3() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Marca: " << marca << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Descuento: " << descuento << "%" << endl;
    cout << "Cantidad en inventario: " << cantidadInventario << endl;
    cout << "Fecha de vencimiento: " << fechaVencimiento << endl;
}

int Comestible::calcularDescuento3() const{
    return precio - (precio * descuento / 100);
}

int Comestible::calcularPrecio3(int cantidad) const{
    int precioTotal = precio * cantidad;
    int descuentoTotal = (precioTotal * descuento / 100);
    return precioTotal - descuentoTotal;
}
void Comestible::modificarNombre3(const string& nuevoNombre) {
    nombre = nuevoNombre;
}
void Comestible::modificarPrecio3(int nuevoPrecio){
    precio = nuevoPrecio;
}
void Comestible::modificarDescuento3(int nuevoDescuento) {
    descuento = nuevoDescuento;
}

//class Electronico
void Electronico::mostrarDetalles3() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Marca: " << marca << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Descuento: " << descuento << "%" << endl;
    cout << "Cantidad en inventario: " << cantidadInventario << endl;
    cout << "Garantia (meses): " << garantia << endl;
}

int Electronico::calcularDescuento3() const{
    return precio - (precio * descuento / 100);
}
int Electronico::calcularPrecio3(int cantidad) const{
    int precioTotal = precio * cantidad;
    int descuentoTotal = (precioTotal * descuento / 100);
    return precioTotal - descuentoTotal;
}
void Electronico::modificarNombre3(const string& nuevoNombre) {
    nombre = nuevoNombre;
}
void Electronico::modificarPrecio3(int nuevoPrecio) {
    precio = nuevoPrecio;
}
void Electronico::modificarDescuento3(int nuevoDescuento)  {
    descuento = nuevoDescuento;
}

//class Aseo
void Aseo::mostrarDetalles3() const{
    cout << "Nombre: " << nombre << endl;
    cout << "Marca: " << marca << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Descuento: " << descuento << "%" << endl;
    cout << "Cantidad en inventario: " << cantidadInventario << endl;
    cout << "Material: " << material << endl;
}

int Aseo::calcularDescuento3() const{
    return precio - (precio * descuento / 100);
}
int Aseo::calcularPrecio3(int cantidad) const{
    int precioTotal = precio * cantidad;
    int descuentoTotal = (precioTotal * descuento / 100);
    return precioTotal - descuentoTotal;
}
void Aseo::modificarNombre3(const string& nuevoNombre){
    nombre = nuevoNombre;
}

void Aseo::modificarPrecio3(int nuevoPrecio) {
    precio = nuevoPrecio;
}

void Aseo::modificarDescuento3(int nuevoDescuento) {
    descuento = nuevoDescuento;
}

void CuentaCorriente::ingresarDinero3(double cantidad){
    //metodo para ingresar dinero
    saldo += cantidad;
}

void CuentaCorriente::consultarCuenta3(){
    //metodo para consultar la cuenta, imprime cada variable
    cout << "Nombre: " << nombre << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Saldo: " << int(saldo) << endl;
}

bool CuentaCorriente::saldoNegativo3() {
    //retorna true o false si el saldo es negativo o no
    return saldo < 0;
}

void CuentaCorriente::setNombre3(string nombre_nuevo){
    //sobreescribe sobre el nombre anterior de la cuenta
    nombre = nombre_nuevo;
}

void CuentaCorriente::setApellidos3(string apellido_nuevo){
    //sobreescribe sobre el apellido anterior de la cuenta
    apellidos = apellido_nuevo;
}

void CuentaCorriente::setDireccion3(string direccion_nueva){
    //sobreescribe sobre la direccion anterior de la cuenta
    direccion = direccion_nueva;
}

void CuentaCorriente::setTelefono3(string telefono_nuevo){
    //sobreescribe sobre el telefono anterior de la cuenta
    telefono = telefono_nuevo;
}

void CuentaCorriente::setClave3(string nueva_clave, string clave){
    if(clave==nueva_clave){
        cout<<"La nueva clave no debe ser igual a la anterior"<<endl;
    }
    else{
        clave = nueva_clave;
        cout<<"Clave actualizada correctamente"<<endl;
    }
}

int CuentaCorriente::getSaldo3(){
    return saldo;
}

string CuentaCorriente::getDocumento3()const{
    return documento;
}

string CuentaCorriente::getClave3()const{
    return clave;
}

bool CuentaCorriente::validarCuenta3(const string& documento, const string& clave, const CuentaCorriente& cuenta) {
    if (documento == cuenta.getDocumento3() && clave == cuenta.getClave3()) {
        return true; // La cuenta es válida
    } else {
        return false; // La cuenta no es válida
    }
}

void CuentaCorriente::realizarCompra3(double monto) {
    saldo -= monto;
}
