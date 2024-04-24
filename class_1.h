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
    Producto(string _nombre, string _marca, int _precio, int _cantidadInventario, int _descuento)
        : nombre(_nombre), marca(_marca), precio(_precio), cantidadInventario(_cantidadInventario), descuento(_descuento) {}

    virtual void mostrarDetalles() const = 0;
    virtual int calcularDescuento() const = 0;
    virtual int calcularPrecio(int cantidad) const = 0;
    int getCantidadInventario();
    void reducirInventario(int cantidad);

    // Métodos virtuales puros para modificar atributos
    virtual void modificarNombre(const string& nuevoNombre) = 0;
    virtual void modificarPrecio(int nuevoPrecio) = 0;
    virtual void modificarDescuento(int nuevoDescuento) = 0;
};


class Comestible : public Producto {
private:
    string fechaVencimiento;
    int cantidad;

public:
    Comestible(string _nombre, string _marca, int _precio, int _cantidadInventario, int _descuento, string _fechaVencimiento)
        : Producto(_nombre, _marca, _precio, _cantidadInventario, _descuento), fechaVencimiento(_fechaVencimiento) {}

    void mostrarDetalles() const override;
    int calcularDescuento() const override;
    int calcularPrecio(int cantidad) const override;
    void modificarNombre(const string& nuevoNombre) override;
    void modificarPrecio(int nuevoPrecio) override;
    void modificarDescuento(int nuevoDescuento) override;
};


class Electronico : public Producto {
private:
    int garantia;
    int cantidad;

public:
    Electronico(string _nombre, string _marca, int _precio, int _cantidadInventario, int _descuento, int _garantia)
        : Producto(_nombre, _marca, _precio, _cantidadInventario, _descuento), garantia(_garantia) {}

    void mostrarDetalles() const override;

    int calcularDescuento() const override;
    int calcularPrecio(int cantidad) const override;
    void modificarNombre(const string& nuevoNombre) override;
    void modificarPrecio(int nuevoPrecio) override;
    void modificarDescuento(int nuevoDescuento) override;
};

// Clase Aseo
class Aseo : public Producto {
private:
    string material;
    int cantidad;

public:
    Aseo(string _nombre, string _marca, int _precio, int _cantidadInventario, int _descuento, string _material)
        : Producto(_nombre, _marca, _precio, _cantidadInventario, _descuento), material(_material) {}

    void mostrarDetalles() const override;
    int calcularDescuento() const override;
    int calcularPrecio(int cantidad) const override;
    void modificarNombre(const string& nuevoNombre) override;
    void modificarPrecio(int nuevoPrecio) override;
    void modificarDescuento(int nuevoDescuento) override;
};
