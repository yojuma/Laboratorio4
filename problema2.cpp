#include <class_2.h>
#include<iostream>
#include<windows.h> //para el metodo HANDLE para texto de color
using namespace std;

bool validarDocumentoyClave(string documento,string clave){
    string id,password;
    cout<<"Ingrese su documento: ";
    cin>>id;
    cout<<"Ingrese su clave: ";
    cin>>password;
    if(id==documento || password==clave){
        return true;
    }
    else{
        return false;
    }
}

int ejercicio2(){
    CuentaCorriente *cuenta = new CuentaCorriente();
    int option;
    string nombre, apellidos, direccion, telefono, documento, clave;
    cout<<"***MENU CUENTA***"<<endl;
    cout<<"1. Cuenta existente"<<endl;
    cout<<"2. Nueva cuenta\n"<<endl;
    cout<<"Seleccione una opcion: "<<endl;
    cin>>option;
    switch(option){
        case 1:
        cout<<"Ingrese su documento: ";
        cin>>documento;
        cout<<"Ingrese su clave: ";
        cin>>clave;
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
        case 2:
        cout<<"Ingrese un documento temporal: ";
        cin>>documento;
        cout<<"Ingrese una clave temporal: ";
        cin>>clave;
        *cuenta = CuentaCorriente("samuel", "Garcia", "123_Medellin_bello", "3125406142", 180500);
        break;
    }

    while(true){
        int opcion1;
        cout<<"\n***MENU E1***"<<endl;
        cout << "1. Consultar datos de la cuenta" << endl;
        cout << "2. Modificar datos de la cuenta" << endl;
        cout<<"3. Ingresar Dinero"<<endl;
        cout<<"4. Retirar Dinero"<<endl;
        cout<<"5. salir\n"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion1;

        switch(opcion1){
        case 1:
            cuenta->consultarCuenta();
            break;
        case 2:{
            if(validarDocumentoyClave(documento,clave)==true){
            int dato;
            string nuevo_valor;
            cout << "Que dato desea modificar?" << endl;
            cout << "1. Nombre" << endl;
            cout << "2. Apellidos" << endl;
            cout << "3. Direccion" << endl;
            cout << "4. Telefono" << endl;
            cout << "5. Clave" << endl;
            cout << "Seleccione una opcion: ";
            cin >> dato;
            switch (dato) {
                case 1:
                    cout << "Ingrese el nuevo nombre: ";
                    cin >> nuevo_valor;
                    cuenta->setNombre(nuevo_valor);
                    break;
                case 2:
                cout << "Ingrese el nuevo apellido: ";
                cin >> nuevo_valor;
                    cuenta->setApellidos(nuevo_valor);
                    break;
                case 3:
                cout << "Ingrese la nueva direccion: ";
                cin >> nuevo_valor;
                    cuenta->setDireccion(nuevo_valor);
                    break;
                case 4:
                cout << "Ingrese el nuevo telefono: ";
                cin >> nuevo_valor;
                    cuenta->setTelefono(nuevo_valor);
                    break;
                case 5:
                cout << "Ingrese su clave anterior: ";
                cin >> clave;
                cout << "Ingrese su nueva clave: ";
                cin >> nuevo_valor;
                    cuenta->setClave(nuevo_valor,clave);
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
            }
            break;
        }
        case 3:
            if(validarDocumentoyClave(documento,clave)==true){
            double cantidad_ingreso;
            cout << "Ingrese la cantidad a ingresar: ";
            cin >> cantidad_ingreso;
            cuenta->ingresarDinero(cantidad_ingreso);
            }
            break;
        case 4:
            if(validarDocumentoyClave(documento,clave)==true){
            double cantidad_retiro;
            cout << "Ingrese la cantidad a retirar: ";
            cin>>cantidad_retiro;
            cuenta->retirarDinero(cantidad_retiro);
            if(cuenta->saldoNegativo()==true){
                HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);       //-----------------------------------------------------
                SetConsoleTextAttribute(hConsole,4);                    //esta parte pone roja la alerta del saldo, este metodo
                cout<<"AlERTA: Tienes saldo negativo o pendiente\n";    //lo encontré en internet y no altera el codigo
                SetConsoleTextAttribute(hConsole,7);                    //_____________________________________________________
            }
            }
            break;
        case 5:
            delete cuenta;
            return 0;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
        }
    }
    delete cuenta;
    return 0;
}



