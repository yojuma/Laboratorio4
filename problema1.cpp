#include <iostream>
#include <vector>
#include <string>
#include"class_1.h"
using namespace std;
int cantidad;
void mostrarMenu() {
    cout << "-Bienvenido a la tienda-" << endl;
    cout << "1. Agregar productos" << endl;
    cout << "2. Modificar nombres, precios o % descuento" << endl;
    cout << "3. Realizar compra" << endl;
    cout << "4. Salir" << endl;
    cout << "------------------------" << endl;
}


void imprimirRecibo(const vector<Producto*>& carrito) {
    cout << "Recibo de compra:" << endl;
    cout << "-----------------" << endl;
    int total = 0;
    for (Producto const *producto : carrito) {
        producto->mostrarDetalles();
        cout << "Precio con descuento: $" << producto->calcularDescuento() << endl;
        total += producto->calcularPrecio(cantidad);
        cout << "-----------------" << endl;
    }
    cout << "Total a pagar: $" << total << endl;
    cout << endl;
}

int ejercicio1() {
    vector<Producto*> inventario;
    vector<Producto*> carrito;


    // Ejemplo de carga inicial de datos
    inventario.push_back(new Comestible("Leche", "Lala", 3500, 10, 0, "04/2024"));
    inventario.push_back(new Electronico("Smartphone", "Samsung", 750000, 5, 20, 12));
    inventario.push_back(new Aseo("Jabon", "Dove", 1500, 20, 0, "Liquido"));

    int opcion;
    do {
        mostrarMenu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int tipoProducto;
            cout << "Seleccione el tipo de producto a agregar:" << endl;
            cout << "1. Comestible" << endl;
            cout << "2. Electronico" << endl;
            cout << "3. Aseo" << endl;
            cout << "Ingrese una opcion: ";
            cin >> tipoProducto;

            string nombre, marca;
            int precio, cantidadInventario, descuento;
            switch (tipoProducto) {
                case 1: {
                    string fechaVencimiento;
                    cout << "Ingrese el nombre: ";
                    cin >> nombre;
                    cout << "Ingrese la marca: ";
                    cin >> marca;
                    cout << "Ingrese el precio: ";
                    cin >> precio;
                    cout << "Ingrese la cantidad en inventario: ";
                    cin >> cantidadInventario;
                    cout << "Ingrese el % de descuento: ";
                    cin >> descuento;
                    cout << "Ingrese la fecha de vencimiento (MM/AAAA): ";
                    cin >> fechaVencimiento;
                    inventario.push_back(new Comestible(nombre, marca, precio, cantidadInventario, descuento, fechaVencimiento));
                    cout << "Producto agregado correctamente." << endl;
                    cout << endl;
                    break;
                }
                case 2: {
                    int garantia;
                    cout << "Ingrese el nombre: ";
                    cin >> nombre;
                    cout << "Ingrese la marca: ";
                    cin >> marca;
                    cout << "Ingrese el precio: ";
                    cin >> precio;
                    cout << "Ingrese la cantidad en inventario: ";
                    cin >> cantidadInventario;
                    cout << "Ingrese el % de descuento: ";
                    cin >> descuento;
                    cout << "Ingrese la garantía en meses: ";
                    cin >> garantia;
                    inventario.push_back(new Electronico(nombre, marca, precio, cantidadInventario, descuento, garantia));
                    cout << "Producto agregado correctamente." << endl;
                    cout << endl;
                    break;
                }
                case 3: {
                    string material;
                    cout << "Ingrese el nombre: ";
                    cin >> nombre;
                    cout << "Ingrese la marca: ";
                    cin >> marca;
                    cout << "Ingrese el precio: ";
                    cin >> precio;
                    cout << "Ingrese la cantidad en inventario: ";
                    cin >> cantidadInventario;
                    cout << "Ingrese el % de descuento: ";
                    cin >> descuento;
                    cout << "Ingrese el material: ";
                    cin >> material;
                    inventario.push_back(new Aseo(nombre, marca, precio, cantidadInventario, descuento, material));
                    cout << "Producto agregado correctamente." << endl;
                    cout << endl;
                    break;
                }
                default: {
                    cout << "Opcion invalida." << endl;
                    cout << endl;
                    break;
                }
            }
            break;
        }
        case 2: {
            if (inventario.empty()) {
                cout << "No hay productos disponibles para modificar." << endl;
                cout << endl;
                break;
            }

            int opcionModificar;
            cout << "Seleccione el producto que desea modificar:" << endl;
            for (int i = 0; i < inventario.size(); ++i) {
                cout << i + 1 << ". ";
                inventario[i]->mostrarDetalles();
                cout << endl;
            }
            cout << "Ingrese el numero del producto que desea modificar: ";
            cin >> opcionModificar;

            if (opcionModificar < 1 || opcionModificar > inventario.size()) {
                cout << "Numero de producto invalido." << endl;
                cout << endl;
                break;
            }

            int opcionCampo;
            cout << "Seleccione el campo que desea modificar:" << endl;
            cout << "1. Nombre" << endl;
            cout << "2. Precio" << endl;
            cout << "3. % Descuento" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcionCampo;

            switch (opcionCampo) {
                case 1: {
                    string nuevoNombre;
                    cout << "Ingrese el nuevo nombre: ";
                    cin >> nuevoNombre;
                    // Modificar el nombre a través de un método público
                    inventario[opcionModificar - 1]->modificarNombre(nuevoNombre);
                    cout << "Nombre modificado correctamente." << endl;
                    cout << endl;
                    break;
                }
                case 2: {
                    int nuevoPrecio;
                    cout << "Ingrese el nuevo precio: ";
                    cin >> nuevoPrecio;
                    // Modificar el precio a través de un método público
                    inventario[opcionModificar - 1]->modificarPrecio(nuevoPrecio);
                    cout << "Precio modificado correctamente." << endl;
                    cout << endl;
                    break;
                }
                case 3: {
                    int nuevoDescuento;
                    cout << "Ingrese el nuevo % de descuento: ";
                    cin >> nuevoDescuento;
                    // Modificar el descuento a través de un método público
                    inventario[opcionModificar - 1]->modificarDescuento(nuevoDescuento);
                    cout << "% Descuento modificado correctamente." << endl;
                    cout << endl;
                    break;
                }
                default: {
                    cout << "Opcion invalida." << endl;
                    cout << endl;
                    break;
                }
            }
            break;
        }
            case 3: {
                for (Producto const *producto : inventario) {
                    producto->mostrarDetalles();
                    cout << endl;
                }
                int opcionProducto;
                do {
                    cout << "Seleccione un producto para agregar al carrito (0 para terminar): ";
                    cin >> opcionProducto;
                    if (opcionProducto >= 1 && opcionProducto <= inventario.size()) {
                        cout << "Ingrese la cantidad a comprar: ";
                        cin >> cantidad;
                        if (cantidad > 0 && cantidad <= inventario[opcionProducto - 1]->getCantidadInventario()) {
                            carrito.push_back(inventario[opcionProducto - 1]);
                            inventario[opcionProducto - 1]->reducirInventario(cantidad);
                            cout << "Producto agregado al carrito." << endl;
                            cout << endl;
                        } else {
                            cout << "Cantidad invalida o insuficiente en inventario." << endl;
                            cout << endl;
                        }
                    }
                } while (opcionProducto != 0);
                if (!carrito.empty()) {
                    imprimirRecibo(carrito);
                    carrito.clear();
                }
                break;
            }
            case 4: {
                break;
            }
            default: {
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                cout << endl;
            }
            for (Producto *&producto : carrito) {
                delete producto;
            }
        }
    }
    while (opcion != 4);

    for (Producto *&producto : inventario) {
        delete producto;
    }

    return 0;
}
