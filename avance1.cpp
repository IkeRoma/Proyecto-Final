#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

enum Estado
{
    sinCompletar,
    Completado
};

enum TamanoCaja
{
    chica,
    media,
    grande,
    extragrande
};

enum Cargo
{
    EmpleadoCargo,
    GerenteCargo
};

class DateTime
{
private:
    int dia, mes, anio, hora, minuto, segundo;

public:
    DateTime()
    {
        time_t tt = time(0);
        tm *ahora = localtime(&tt);
        dia = ahora->tm_mday;
        mes = ahora->tm_mon + 1;
        anio = ahora->tm_year + 1900;
        hora = ahora->tm_hour;
        minuto = ahora->tm_min;
        segundo = ahora->tm_sec;
    }

    int Dia() { return dia; }
    int Mes() { return mes; }
    int Anio() { return anio; }
    int Hora() { return hora; }
    int Minuto() { return minuto; }
    int Segundo() { return segundo; }
    string getHora()
    {
        string str = to_string(Dia()) + "/" + to_string(Mes()) + "/" + to_string(Anio()) + "\tcon Hora de : " + to_string(Hora()) + ":" + to_string(Minuto()) + ":" + to_string(Segundo());
        return str;
    }
};

class Empleado
{
protected:
    unsigned int edad;
    string nombre;
    string curp;
    string rfc;
    string domicilio;
    Cargo rango;

public:
    Empleado(unsigned int edad, string nombre, string curp, string rfc, string domicilio, Cargo rango)
        : edad(edad), nombre(nombre), curp(curp), rfc(rfc), domicilio(domicilio), rango(rango) {}

    unsigned int getEdad() { return edad; }
    string getNombre() { return nombre; }
    string getCURP() { return curp; }
    string getRFC() { return rfc; }
    Cargo getCargo() { return rango; }
};

class Gerente : public Empleado
{
private:
    int claveGerente;

public:
    Gerente(unsigned int edad, string nombre, string curp, string rfc, string domicilio, Cargo rango, int claveGerente)
        : Empleado(edad, nombre, curp, rfc, domicilio, rango), claveGerente(claveGerente) {}

    int getClaveGerente() { return claveGerente; }
};

class DatosEmpleados
{
    private:
    Gerente gerente;
    vector <Empleado *> ListaEmpleados;
};
class Item
{
    private:
    int tamano;
    int cantidad;
    string nombre;
    float precio;
    string id;

    public:
    Item(string nombre, float precio, string id, int tamano, int cantidad): nombre(nombre), precio(precio), id(id), tamano(tamano), cantidad(cantidad) {}
    string getNombre() { return nombre; }
    float getprecio() { return precio; }
    string getID() { return id; }
    int getTamano() { return tamano; }
    int getCantidad() { return cantidad; }
    void AgregarCantidad(int cantidadagregar) { cantidad+=cantidadagregar; }
};

class Caja
{
    private:
    vector <Item * > contenidoCaja;
    TamanoCaja espacio;
    int restante;
    Estado estado;

    public:
    Caja(TamanoCaja tamano, int restante, Estado estado): espacio(tamano), restante(restante), estado(estado) {}
    TamanoCaja getTamanoCaja() { return espacio; }
    int getRestante() { return restante; }
    Estado getEstado() { return estado; }
    void ModificarRestante(int anadido) { restante-=anadido; }
    void ModificarEstado (Estado nuevoEstado) { estado=nuevoEstado; }
};

class Rack
{
    private: 
    vector <Caja *> Cajas;
    vector <Item *> Items;
    int restante;
    int numero;

    public:
};

class Almacen
{
    private:
    vector <Rack *> Racks;
};

int main()
{
    cout << "Hola mundo" << endl;

    return 0;
}
