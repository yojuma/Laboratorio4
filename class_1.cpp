#include <iostream>
#include"class_1.h"

using namespace std;

//class base Producto
int Producto::getCantidadInventario(){
    return cantidadInventario;
}

void Producto::reducirInventario(int cantidad){
    cantidadInventario -= cantidad;
}

void Comestible::mostrarDetalles() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Marca: " << marca << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Descuento: " << descuento << "%" << endl;
    cout << "Cantidad en inventario: " << cantidadInventario << endl;
    cout << "Fecha de vencimiento: " << fechaVencimiento << endl;
}

int Comestible::calcularDescuento() const{
    return precio - (precio * descuento / 100);
}

int Comestible::calcularPrecio(int cantidad) const{
    int precioTotal = precio * cantidad;
    int descuentoTotal = (precioTotal * descuento / 100);
    return precioTotal - descuentoTotal;
}
void Comestible::modificarNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}
void Comestible::modificarPrecio(int nuevoPrecio){
    precio = nuevoPrecio;
}
void Comestible::modificarDescuento(int nuevoDescuento) {
    descuento = nuevoDescuento;
}

//class Electronico
void Electronico::mostrarDetalles() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Marca: " << marca << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Descuento: " << descuento << "%" << endl;
    cout << "Cantidad en inventario: " << cantidadInventario << endl;
    cout << "Garantia (meses): " << garantia << endl;
}

int Electronico::calcularDescuento() const{
    return precio - (precio * descuento / 100);
}
int Electronico::calcularPrecio(int cantidad) const{
    int precioTotal = precio * cantidad;
    int descuentoTotal = (precioTotal * descuento / 100);
    return precioTotal - descuentoTotal;
}
void Electronico::modificarNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}
void Electronico::modificarPrecio(int nuevoPrecio) {
    precio = nuevoPrecio;
}
void Electronico::modificarDescuento(int nuevoDescuento)  {
    descuento = nuevoDescuento;
}

//class Aseo
void Aseo::mostrarDetalles() const{
    cout << "Nombre: " << nombre << endl;
    cout << "Marca: " << marca << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Descuento: " << descuento << "%" << endl;
    cout << "Cantidad en inventario: " << cantidadInventario << endl;
    cout << "Material: " << material << endl;
}

int Aseo::calcularDescuento() const{
    return precio - (precio * descuento / 100);
}
int Aseo::calcularPrecio(int cantidad) const{
    int precioTotal = precio * cantidad;
    int descuentoTotal = (precioTotal * descuento / 100);
    return precioTotal - descuentoTotal;
}
void Aseo::modificarNombre(const string& nuevoNombre){
    nombre = nuevoNombre;
}

void Aseo::modificarPrecio(int nuevoPrecio) {
    precio = nuevoPrecio;
}

void Aseo::modificarDescuento(int nuevoDescuento) {
    descuento = nuevoDescuento;
}



