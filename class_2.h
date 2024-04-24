#ifndef PROBLEMA2_H
#define PROBLEMA2_H

#include <iostream>
#include <string>
#include <map>
#include <windows.h>

using namespace std;

class CuentaCorriente {
private:
    string nombre, apellidos, direccion, telefono, documento;
    string clave = "12345"; // Clave por defecto
    double saldo = 0.0;


public:
    bool sesionActiva = false;
    CuentaCorriente();
    CuentaCorriente(string nombre, string apellidos, string direccion, string telefono, double saldo);
    ~CuentaCorriente();

    // Métodos...
    bool validarUsuario(string documento, string clave);
    bool cambiarClave(string documento, string claveAnterior, string nuevaClave);
    void retirarDinero(double cantidad);
    void ingresarDinero(double cantidad);
    void consultarCuenta();
    bool saldoNegativo();
    string getNombre();
    void setNombre(string nombre_nuevo);
    void setApellidos(string apellido_nuevo);
    void setDireccion(string direccion_nueva);
    void setTelefono(string telefono_nuevo);
    bool iniciarSesion(string documento, string clave);
    void cerrarSesion();
};

class Autenticacion {
private:
    map<string, string> usuarios; // Almacena usuarios y contraseñas

public:
    Autenticacion();
    ~Autenticacion();

    // Métodos...
    bool iniciarSesion(string usuario, string clave);
    bool registrarUsuario(string usuario, string clave);
    bool validarDocumento(string documento);
};

#endif // PROBLEMA2_H



