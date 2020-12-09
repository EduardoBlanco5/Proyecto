#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Aldeano
{
private:
    string Nombre;
    string Genero;
    size_t Edad;
    size_t Salud;

public: 
    Aldeano(){}
    Aldeano(const string &Nombre, const string &Genero, size_t Edad, size_t Salud)
    :Nombre(Nombre), Genero(Genero), Edad(Edad), Salud(Salud){}

    void setNombre(const string &Nombre);
    string getNombre()const;

    void setGenero(const string &Genero);
    string getGenero();

    void setEdad(size_t Edad);
    size_t getEdad() const;

    void setSalud(size_t Salud);
    size_t getSalud() const ;

    friend ostream& operator<<(ostream &out, const Aldeano &A)
    {
        out << left;
        out << setw(10)<< A.Nombre;
        out << setw(10)<< A.Genero;
        out << setw(10)<< A.Edad;
        out << setw(10)<< A.Salud;

        return out;

    }

    bool operator<(const Aldeano &A) const
    {
        return Nombre < A.getNombre();
    }
};

#endif