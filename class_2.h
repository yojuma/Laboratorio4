#ifndef CLASS_2_H
#define CLASS_2_H

#include<iostream>
#include<string>
using namespace std;

class CuentaCorriente{
private:
    string nombre, apellidos, direccion, telefono, documento, clave;
    double saldo=0.0;
public:
    void retirarDinero(double cantidad);
    void ingresarDinero(double cantidad);
    void consultarCuenta();
    bool saldoNegativo();
    string getnombre();
    void setNombre(string nombre_nuevo);
    void setApellidos(string apellido_nuevo);
    void setDireccion(string direccion_nueva);
    void setTelefono(string telefono_nuevo);
    void setClave(string nueva_clave,string clave);


    CuentaCorriente(); //constructor por defecto
    CuentaCorriente(string nombre, string apellidos, string direccion, string telefono, double saldo); //constructor parametrizado
    ~CuentaCorriente(){
        //destructor
    }

};


#endif // CLASS_2_H



