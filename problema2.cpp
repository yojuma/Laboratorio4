#include<iostream>
#include<windows.h> // para el método HANDLE para texto de color
#include"class_2.h"


using namespace std;

int ejercicio2() {
    CuentaCorriente *cuenta = new CuentaCorriente();
    Autenticacion autenticacion; // Creamos un objeto de la clase Autenticacion
    int option;
    string nombre, apellidos, direccion, telefono;
    bool acceso = false;
    while (!acceso) {
        cout << "***MENU CUENTA***" << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Crear una nueva cuenta" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;
        switch(option) {
            case 1: {
                string documento;
                string clave_inicio;

                cout << "Ingrese su Documento: ";
                cin >> documento;
                cout << "Ingrese su clave: ";
                cin >> clave_inicio;
                if (autenticacion.iniciarSesion(documento, clave_inicio)) {
                    acceso = true;
                }
                break;
            }
            case 2: {
                string documento;
                string clave_registro;

                cout << "Ingrese su Documento: ";
                cin >> documento;
                cout << "Ingrese una clave: ";
                cin >> clave_registro;
                if (autenticacion.registrarUsuario(documento, clave_registro)) {
                    acceso = true; // Establecer acceso a true después de registrar el usuario
                    // Resto del código para ingresar datos adicionales de la cuenta...
                } else {
                    cout << "Error al registrar el usuario. Inténtelo de nuevo." << endl;
                }
                break;

                cout << "Ingrese su nombre: ";
                cin >> nombre;
                cout << "Ingrese su apellido: ";
                cin >> apellidos;
                cout << "Ingrese su direccion: ";
                cin >> direccion;
                cout << "Ingrese su telefono: ";
                cin >> telefono;
                *cuenta = CuentaCorriente(nombre, apellidos, direccion, telefono, 0.0);
                break;
            }
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }
    while (true) {
        int opcion1;
        cout << "\n***MENU E1***" << endl;
        cout << "1. Consultar datos de la cuenta" << endl;
        cout << "2. Modificar datos de la cuenta" << endl;
        cout << "3. Ingresar Dinero" << endl;
        cout << "4. Retirar Dinero" << endl;
        cout << "5. Modificar clave" << endl; // Añadido para la opción de modificar clave
        cout << "6. Salir" << endl; // Cambio en el número de opción
        cout << "Seleccione una opcion: ";
        cin >> opcion1;

        switch(opcion1) {
            case 1:
                if (cuenta->sesionActiva) {
                    cuenta->consultarCuenta();
                } else {
                    cout << "Acceso denegado. Debe iniciar sesión primero." << endl;
                }
                break;
            case 2: {
                int dato;
                string nuevo_valor;
                if (cuenta->sesionActiva) {
                    cout << "Que dato desea modificar?" << endl;
                    cout << "1. Nombre" << endl;
                    cout << "2. Apellidos" << endl;
                    cout << "3. Direccion" << endl;
                    cout << "4. Telefono" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> dato;
                    cout << "Ingrese el nuevo valor: ";
                    cin >> nuevo_valor;
                    switch (dato) {
                        case 1:
                            cuenta->setNombre(nuevo_valor);
                            break;
                        case 2:
                            cuenta->setApellidos(nuevo_valor);
                            break;
                        case 3:
                            cuenta->setDireccion(nuevo_valor);
                            break;
                        case 4:
                            cuenta->setTelefono(nuevo_valor);
                            break;
                        default:
                            cout << "Opcion no valida" << endl;
                            break;
                    }
                } else {
                    cout << "Acceso denegado. Debe iniciar sesión primero." << endl;
                }
                break;
            }
            case 3:
                if (cuenta->sesionActiva) {
                    double cantidad_ingreso;
                    cout << "Ingrese la cantidad a ingresar: ";
                    cin >> cantidad_ingreso;
                    cuenta->ingresarDinero(cantidad_ingreso);
                } else {
                    cout << "Acceso denegado. Debe iniciar sesión primero." << endl;
                }
                break;
            case 4:
                if (cuenta->sesionActiva) {
                    double cantidad_retiro;
                    cout << "Ingrese la cantidad a retirar: ";
                    cin >> cantidad_retiro;
                    cuenta->retirarDinero(cantidad_retiro);
                    if (cuenta->saldoNegativo()) {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 4);
                        cout << "ALERTA: Tienes saldo negativo o pendiente\n";
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                } else {
                    cout << "Acceso denegado. Debe iniciar sesión primero." << endl;
                }
                break;
            case 5: // Opción para modificar clave
                if (cuenta->sesionActiva) {
                    string documento, claveAnterior, nuevaClave;
                    cout << "Ingrese su documento: ";
                    cin >> documento;
                    if (autenticacion.validarDocumento(documento)) {
                        cout << "Ingrese la clave anterior: ";
                        cin >> claveAnterior;
                        cout << "Ingrese la nueva clave: ";
                        cin >> nuevaClave;
                        cuenta->cambiarClave(documento, claveAnterior, nuevaClave);
                    } else {
                        cout << "Documento no registrado." << endl;
                    }
                } else {
                    cout << "Acceso denegado. Debe iniciar sesión primero." << endl;
                }
                break;
            case 6: // Opción para salir
                delete cuenta;
                return 0;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }
    delete cuenta;
    return 0;
}

