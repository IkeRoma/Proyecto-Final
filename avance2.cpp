/*
 * @file
 * @author Adrian Rodriguez (arodriguezm2205@alumno.ipn.mx)
 *@author Ariadna Esquivel ()
 * @brief Definimiento del problema para el almacen.
 * @version 0.1
 * @brief version 0.1, se definen las clases que se planean ocupar en el sistema.
 * @date 2023/13/12
 *
 * @version 0.2
 * @brief version 0.2, se acompletan más las clases agregando metodos necesarios para que estas funcionen. Pero se encuentra ael problema de la delimitacion.
 * @date 2023/17/12
 * 
 * @copyright Copyright (c) 2023
 *
 */
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

class Item
{
private:
    int tamano;
    int cantidad;
    string nombre;
    float precio;
    string id;

public:
    Item(string nombre, float precio, string id, int tamano, int cantidad) : nombre(nombre), precio(precio), id(id), tamano(tamano), cantidad(cantidad) {}
    string getNombre() { return nombre; }
    float getprecio() { return precio; }
    string getID() { return id; }
    int getTamano() { return tamano; }
    int getCantidad() { return cantidad; }
    void AgregarCantidad(int cantidadagregar) { cantidad += cantidadagregar; }
};

class Caja
{
private:
    vector<Item *> contenidoCaja;
    TamanoCaja espacio;
    int restante;
    Estado estado;

public:
    Caja(TamanoCaja tamano, int restante, Estado estado) : espacio(tamano), restante(restante), estado(estado) {}
    TamanoCaja getTamanoCaja() { return espacio; }
    int getRestante() { return restante; }
    Estado getEstado() { return estado; }
    void ModificarRestante(int anadido) { restante -= anadido; }
    void ModificarEstado(Estado nuevoEstado) { estado = nuevoEstado; }
};

class Rack
{
private:
    vector<Caja *> Cajas;
    vector<Item *> Items;
    int restante;
    int numero;

public:
    Rack(int numero) : numero(numero)
    {
        this->restante = 100;
    }
    int getRestante() { return restante; }
    int getNumero() { return numero; }

    // Método para obtener un string con la información de los items en el rack
    string getItemsxRack()
    {
        string lista;
        for (int i = 0; i < Items.size(); i++)
        {
            lista += "Nombre: " + Items[i]->getNombre() + ", ID: " + Items[i]->getID() +
                     ", Cantidad: " + to_string(Items[i]->getCantidad()) +
                     ", Precio: " + to_string(Items[i]->getprecio()) +
                     ", Tamaño: " + to_string(Items[i]->getTamano()) + "\n";
        }
        return lista;
    }

    void AgregarCaja(TamanoCaja tamano, int restante, Estado estado)
    {
        Cajas.push_back(new Caja(tamano, restante, estado));
    }

    void AgregarItem(string nombre, float precio, string id, int tamano, int cantidad)
    {
        Items.push_back(new Item(nombre, precio, id, tamano, cantidad));
    }
};

class Almacen
{
private:
    Gerente gerente;
    vector<Empleado *> ListaEmpleados;
    vector<Rack *> Racks;

public:
    // Método para obtener un string con la información de los items en todos los racks
    string ListadoItemGeneral()
    {
        string listado = "Listado de items: \n";
        for (int i = 0; i < Racks.size(); i++)
        {
            listado += "Rack " + to_string(i + 1) + ": \n" + Racks[i]->getItemsxRack() + "\n";
        }
        return listado;
    }

    int getCantidadEmpleado() { return ListaEmpleados.size(); }
    int getCantidadRacks() { return Racks.size(); }

    void AgregarEmpleado(unsigned int edad, string nombre, string curp, string rfc, string domicilio, Cargo rango)
    {
        ListaEmpleados.push_back(new Empleado(edad, nombre, curp, rfc, domicilio, rango));
    }

    void AgregarRack(int numero)
    {
        Racks.push_back(new Rack(numero));
    }
};

/**
 * @brief Limpia el texto de la terminal.
 *
 */
void limpia();

/**
 * @brief Pausa el programa en un determinado momento.
 *
 */
void pausar();
void Menu(int &Opc);
void MenuCajas(int &Opc);
void RegistroItem(Almacen &General);

int main()
{
    Almacen General;
    int Opc;

    do
    {
        Menu(Opc);
        if (Opc == 5)
        {
            MenuCajas(Opc);
        }
        else
        {
            switch (Opc)
            {
            case 1:
                limpia();
                cout << General.ListadoItemGeneral() << endl;
                pausar();
                break;

            case 2:
                limpia();

                break;
            }
        }
    } while (Opc != 0);

    return 0;
}

void Menu(int &Opc)
{
    do
    {
        limpia();
        cout << "Menu en modo Item. Para cambiar a modo caja presionar 5." << endl
             << "Las opciones disponibles son: " << endl
             << "1. Listar items." << endl
             << "2. Registrar item." << endl
             << "3. Agregar item existente." << endl
             << "4. Borrar item." << endl
             << "5. Modo Cajas." << endl
             << "6. Empleados." << endl
             << "0. Salir." << endl
             << "R= ";

        cin >> Opc;

        if (Opc == 0)
        {
            limpia();
            // poner "dia" bien escrito.
            cout << "Gracias, que tenga un lindo dia." << endl;
        }
    } while (Opc < 0 || Opc > 6);
}

void MenuCajas(int &Opc)
{
    do
    {
        limpia();
        cout << "Menu en modo Cajas. Para cambiar a modo item presionar ." << endl
             << "Las opciones disponibles son: " << endl
             << "1. Listar Cajas." << endl
             << "2. Añadir Caja." << endl
             << "3. Modificar Caja." << endl
             << "4. Modo Item." << endl
             << "5. Empleados." << endl
             << "0. Salir." << endl
             << "R= ";
        cin >> Opc;

        if (Opc == 0)
        {
            limpia();
            // poner "dia" bien escrito.
            cout << "Gracias, que tenga un lindo dia." << endl;
        }
    } while (Opc < 0 || Opc > 5);
}

void RegistroItem(Almacen &General)
{
}

void limpia()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
} // fin funcion limpia

void pausar()
{
    cout << "Presione enter para continuar...";
    cin.ignore();
    cin.get();
} // fin funcion pausar
