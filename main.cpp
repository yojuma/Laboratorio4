#include<iostream>
#include<problemas.h>

using namespace std;

int main(){
    while(true){
        int opcion;
        cout << "---MENU PRINCIPAL---" << endl;
        cout << "1. Ejercicio 1" << endl;
        cout << "2. Ejercicio 2" << endl;
        cout << "3. Ejercicio 3" << endl;
        cout << "4. Salir" << endl;
        cout << "--------------------"<<endl;
        cout << "Seleccione una opcion: ";
        cin>>opcion;
        cout<<endl;
        switch(opcion){
            case 1:
                ejercicio1();
                break;
            case 2:
                ejercicio2();
                break;
            case 3:
                ejercicio3();
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;

        }
    }
    return 0;
}
