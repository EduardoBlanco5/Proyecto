#include "Aldeano.h"

void Aldeano::setNombre(const string &Nombre)
{
    this->Nombre = Nombre;
}

string Aldeano::getNombre() const 
{
    return Nombre;
}

void Aldeano::setGenero(const string &Genero)
{
    this-> Genero= Genero;
}

string Aldeano::getGenero()
{
    return Genero;
}

void Aldeano::setEdad(size_t Edad)
{
    this-> Edad= Edad;
}

size_t Aldeano::getEdad() const
{
    return Edad;
}

void Aldeano::setSalud(size_t Salud)
{
    this-> Salud= Salud;
}

size_t Aldeano::getSalud() const
{
    return Salud;
}