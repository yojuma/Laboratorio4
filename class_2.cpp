#include "class_2.h"
CuentaCorriente::CuentaCorriente(){
    //constructor por defecto
}

CuentaCorriente::CuentaCorriente(string nombre, string apellidos, string direccion, string telefono, double saldo){
     //constructor parametrizado
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->direccion = direccion;
    this->telefono = telefono;
    this->saldo = saldo;
}

void CuentaCorriente::ingresarDinero(double cantidad){
    //metodo para ingresar dinero
    saldo += cantidad;
}

void CuentaCorriente::retirarDinero(double cantidad){
    //metodo para retirar dinero
    saldo -= cantidad;
}

void CuentaCorriente::consultarCuenta(){
    //metodo para consultar la cuenta, imprime cada variable
    cout << "Nombre: " << nombre << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Saldo: " << int(saldo) << endl;
}

bool CuentaCorriente::saldoNegativo() {
    //retorna true o false si el saldo es negativo o no
    return saldo < 0;
}

void CuentaCorriente::setNombre(string nombre_nuevo){
    //sobreescribe sobre el nombre anterior de la cuenta
    nombre = nombre_nuevo;
}

void CuentaCorriente::setApellidos(string apellido_nuevo){
    //sobreescribe sobre el apellido anterior de la cuenta
    apellidos = apellido_nuevo;
}

void CuentaCorriente::setDireccion(string direccion_nueva){
    //sobreescribe sobre la direccion anterior de la cuenta
    direccion = direccion_nueva;
}

void CuentaCorriente::setTelefono(string telefono_nuevo){
    //sobreescribe sobre el telefono anterior de la cuenta
    telefono = telefono_nuevo;
}

void CuentaCorriente::setClave(string nueva_clave, string clave){
    if(clave==nueva_clave){
        cout<<"La nueva clave no debe ser igual a la anterior"<<endl;
    }
    else{
        clave = nueva_clave;
        cout<<"Clave actualizada correctamente"<<endl;
    }
}

