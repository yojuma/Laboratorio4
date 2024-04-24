#include "class_2.h"
#include <sstream>

CuentaCorriente::CuentaCorriente() {
    // Constructor por defecto
}

CuentaCorriente::CuentaCorriente(string nombre, string apellidos, string direccion, string telefono, double saldo) {
    // Constructor parametrizado
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->direccion = direccion;
    this->telefono = telefono;
    this->saldo = saldo;
}

CuentaCorriente::~CuentaCorriente() {
    // Destructor
}

// Implementación de métodos...
bool CuentaCorriente::validarUsuario(string documento, string clave) {
    // Método para validar el usuario
    return (this->documento == documento && this->clave == clave);
}

bool CuentaCorriente::cambiarClave(string documento, string claveAnterior, string nuevaClave) {
    // Método para cambiar la clave
    if (validarUsuario(documento, claveAnterior)) {
        clave = nuevaClave;
        cout << "Clave cambiada exitosamente." << endl;
        return true;
    } else {
        cout << "Documento o clave incorrectos. No se pudo cambiar la clave." << endl;
        return false;
    }
}

void CuentaCorriente::retirarDinero(double cantidad) {
    // Método para retirar dinero
    saldo -= cantidad;
}

void CuentaCorriente::ingresarDinero(double cantidad) {
    // Método para ingresar dinero
    saldo += cantidad;
}

void CuentaCorriente::consultarCuenta() {
    // Método para consultar la cuenta, imprime cada variable
    cout << "Nombre: " << nombre << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Saldo: " << saldo << endl;
}

bool CuentaCorriente::saldoNegativo() {
    // Retorna true o false si el saldo es negativo o no
    return saldo < 0;
}

string CuentaCorriente::getNombre() {
    // Getter para el nombre
    return nombre;
}

void CuentaCorriente::setNombre(string nombre_nuevo) {
    // Setter para el nombre
    nombre = nombre_nuevo;
}

void CuentaCorriente::setApellidos(string apellido_nuevo) {
    // Setter para los apellidos
    apellidos = apellido_nuevo;
}

void CuentaCorriente::setDireccion(string direccion_nueva) {
    // Setter para la dirección
    direccion = direccion_nueva;
}

void CuentaCorriente::setTelefono(string telefono_nuevo) {
    // Setter para el teléfono
    telefono = telefono_nuevo;
}

bool CuentaCorriente::iniciarSesion(string documento, string clave) {
    // Método para iniciar sesión
    if (validarUsuario(documento, clave)) {
        sesionActiva = true;
        cout << "Sesión iniciada correctamente." << endl;
        return true;
    } else {
        cout << "Documento o clave incorrectos. Acceso denegado." << endl;
        return false;
    }
}

void CuentaCorriente::cerrarSesion() {
    // Método para cerrar sesión
    sesionActiva = false;
    cout << "Sesión cerrada correctamente." << endl;
}

Autenticacion::Autenticacion() {
    // Constructor
}

Autenticacion::~Autenticacion() {
    // Destructor
}

bool Autenticacion::iniciarSesion(string usuario, string clave) {
    // Método para iniciar sesión
    auto iter = usuarios.find(usuario); // Buscar usuario en el mapa
    if (iter != usuarios.end() && iter->second == clave) {
        cout << "Inicio de sesion exitoso." << endl;
        return true;
    } else {
        cout << "Usuario o contrasena incorrectos." << endl;
        return false;
    }
}

bool Autenticacion::registrarUsuario(string usuario, string clave) {
    // Método para registrar un nuevo usuario
    if (usuarios.find(usuario) == usuarios.end()) {
        usuarios[usuario] = clave; // Agregar usuario y contraseña al mapa
        cout << "Usuario registrado exitosamente." << endl;
        return true;
    } else {
        cout << "El usuario ya existe." << endl;
        return false;
    }
}

bool Autenticacion::validarDocumento(string documento) {
    // Método para validar si un documento ya está registrado
    return usuarios.find(documento) != usuarios.end();
}
