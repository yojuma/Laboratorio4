#ifndef CLASS_3_H
#define CLASS_3_H


#include<iostream>
using namespace std;
// Clase base
class Producto {
protected:
    string nombre;
    string marca;
    int precio;
    int cantidadInventario;
    int descuento;

public:
    Producto();
    Producto(string _nombre, string _marca, int _precio, int _cantidadInventario, int _descuento)
        : nombre(_nombre), marca(_marca), precio(_precio), cantidadInventario(_cantidadInventario), descuento(_descuento) {}

    virtual void mostrarDetalles3() const = 0;
    virtual int calcularDescuento3() const = 0;
    virtual int calcularPrecio3(int cantidad) const = 0;
    int getCantidadInventario3();
    void reducirInventario3(int cantidad);

    // Métodos virtuales puros para modificar atributos
    virtual void modificarNombre3(const string& nuevoNombre) = 0;
    virtual void modificarPrecio3(int nuevoPrecio) = 0;
    virtual void modificarDescuento3(int nuevoDescuento) = 0;
};


class Comestible : public Producto {
private:
    string fechaVencimiento;
    int cantidad;

public:
    Comestible(string _nombre, string _marca, int _precio, int _cantidadInventario, int _descuento, string _fechaVencimiento)
        : Producto(_nombre, _marca, _precio, _cantidadInventario, _descuento), fechaVencimiento(_fechaVencimiento) {}

    void mostrarDetalles3() const override;
    int calcularDescuento3() const override;
    int calcularPrecio3(int cantidad) const override;
    void modificarNombre3(const string& nuevoNombre) override;
    void modificarPrecio3(int nuevoPrecio) override;
    void modificarDescuento3(int nuevoDescuento) override;
};


class Electronico : public Producto {
private:
    int garantia;
    int cantidad;

public:
    Electronico(string _nombre, string _marca, int _precio, int _cantidadInventario, int _descuento, int _garantia)
        : Producto(_nombre, _marca, _precio, _cantidadInventario, _descuento), garantia(_garantia) {}

    void mostrarDetalles3() const override;

    int calcularDescuento3() const override;
    int calcularPrecio3(int cantidad) const override;
    void modificarNombre3(const string& nuevoNombre) override;
    void modificarPrecio3(int nuevoPrecio) override;
    void modificarDescuento3(int nuevoDescuento) override;
};

// Clase Aseo
class Aseo : public Producto {
private:
    string material;
    int cantidad;

public:
    Aseo(string _nombre, string _marca, int _precio, int _cantidadInventario, int _descuento, string _material)
        : Producto(_nombre, _marca, _precio, _cantidadInventario, _descuento), material(_material) {}

    void mostrarDetalles3() const override;
    int calcularDescuento3() const override;
    int calcularPrecio3(int cantidad) const override;
    void modificarNombre3(const string& nuevoNombre) override;
    void modificarPrecio3(int nuevoPrecio) override;
    void modificarDescuento3(int nuevoDescuento) override;
};

class CuentaCorriente{
private:
    string nombre, apellidos, direccion, telefono, documento, clave;
    double saldo=0.0;
public:
    void retirarDinero3(double cantidad);
    void ingresarDinero3(double cantidad);
    void consultarCuenta3();
    bool saldoNegativo3();
    int getSaldo3();
    void setNombre3(string nombre_nuevo);
    void setApellidos3(string apellido_nuevo);
    void setDireccion3(string direccion_nueva);
    void setTelefono3(string telefono_nuevo);
    void setClave3(string nueva_clave,string clave);
    bool validarCuenta3(const string& documento, const string& clave, const CuentaCorriente& cuenta);
    string getClave3()const;
    string getDocumento3()const;
    void realizarCompra3(double monto);


    CuentaCorriente(); //constructor por defecto
    CuentaCorriente(string _nombre, string _apellidos, string _direccion, string _telefono, double _saldo); //constructor parametrizado
    ~CuentaCorriente(){
        //destructor
    }

};

#endif // CLASS_3_H
