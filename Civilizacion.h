#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include "Aldeano.h"
#include <list>
#include <iostream>
#include <iomanip>
using namespace std;

class Civilizacion
{
private:
    list<Aldeano> Aldeanos;
    string Nombre;
    string X;
    int Y;
    float Puntuacion;
public:
    Civilizacion(){}
    Civilizacion(const string &Nombre, const string &X, int Y, float Puntuacion);

    void setNombre(const string &z);
    string getNombre();
    void setX(const string &z);
    string getX();
    void setY(int z);
    int getY();
    void setPuntuacion(float z);
    float getPuntuacion();

    friend ostream& operator<<(ostream &out, const Civilizacion &C)
    {
        out << left;
        out << setw(25)<< C.Nombre;
        out << setw(25)<< C.X;
        out << setw(25)<< C.Y;
        out << setw(20)<< C.Puntuacion;
        out << endl;

        return out;
    }

    friend istream& operator>>(istream &in, Civilizacion &C)
    {
        string temp;
        int Y;
        float Puntuacion;

        cout << "Nombre de la Civilizacion: ";
        getline(cin, C.Nombre);

        cout << "Ubicacion en X: ";
        getline(cin, C.X);

        cout << "Ubicacion en Y: ";
        cin >> C.Y;

        cout << "Puntuacion: ";
        cin >> C.Puntuacion;

        return in; 
    }
    
    bool operator==(const Civilizacion& p)
    {
        return Nombre == p.Nombre;
    }
    bool operator==(const Civilizacion& p) const
    {
        return Nombre == p.Nombre;
    }
    bool operator<(const Civilizacion& C)
    {
        return Nombre < C.Nombre;
    }
    bool operator<(const Civilizacion& C) const
    {
        return Nombre < C.Nombre;
    }

    //Aldeano
    void AgregarInicio(const Aldeano &A);
    void AgregarFinal(const Aldeano &A);
    void Mostrar();
    void EliminarN(const string &Nombre);
    void EliminarE();
    void EliminarS(size_t Salud);
    void ClasificarN();//as
    void ClasificarE();//des
    void ClasificarS();
    Aldeano* Buscar(const Aldeano &A);
    void respaldar_tabla();
    void respaldar();
    void recuperar();


};
#endif