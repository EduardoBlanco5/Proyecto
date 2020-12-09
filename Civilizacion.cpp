#include "Civilizacion.h"

Civilizacion::Civilizacion(const string &Nombre, const string &X, int Y, float Puntuacion)
{
    this-> Nombre = Nombre;
    this-> X = X; 
    this-> Y = Y;
    this-> Puntuacion = Puntuacion; 
}

void Civilizacion::setNombre(const string &z)
{
    Nombre = z;
}
string Civilizacion::getNombre()
{
    return Nombre;
}

void Civilizacion::setX(const string &z)
{
    X = z;
}
string Civilizacion::getX()
{
    return X;
}

void Civilizacion::setY(int z)
{
    Y = z;
}
int Civilizacion::getY()
{
    return Y;
}
void Civilizacion::setPuntuacion(float z)
{
    Puntuacion = z;
}
float Civilizacion::getPuntuacion()
{
    return Puntuacion;
}

//Aldeano
void Civilizacion::AgregarInicio(const Aldeano &A)
{
    Aldeanos.push_front(A);
}
void Civilizacion::AgregarFinal(const Aldeano &A)
{
    Aldeanos.push_back(A);
}

void Civilizacion::Mostrar()
{
    for(auto it = Aldeanos.begin(); it != Aldeanos.end(); it++)
    {
        cout << *it << endl;
    }
}

void Civilizacion::EliminarN(const string &Nombre)
{
    for(auto it = Aldeanos.begin(); it != Aldeanos.end(); it++)
    {
        Aldeano &A = *it;
        if(Nombre == A.getNombre())
        {
            Aldeanos.erase(it);
            break;

        }
    }
}

bool Comparador(const Aldeano &A)
{
    return A.getEdad() >= 60;
}
void Civilizacion::EliminarE()
{
    Aldeanos.remove_if(Comparador);
}
void Civilizacion::EliminarS(size_t Salud)
{
    Aldeanos.remove_if([Salud](const Aldeano &A){return A.getSalud() < Salud;});
}

void Civilizacion::ClasificarN()
{
    Aldeanos.sort();
}

bool ComparadorE(const Aldeano &A1, const Aldeano &A2)
{
    return A1.getEdad() > A2.getEdad();
}
void Civilizacion::ClasificarE()
{
    Aldeanos.sort(ComparadorE);
}

void Civilizacion::ClasificarS()
{
    Aldeanos.sort([](const Aldeano &A1, const Aldeano &A2){return A1.getSalud() > A2.getSalud();});
}

Aldeano* Civilizacion::Buscar(const Aldeano &A)
{
    for(auto it = Aldeanos.begin(); it != Aldeanos.end(); it++)
    {
        Aldeano &A = *it;
        if(Nombre == A.getNombre())
        {
            cout<< *it<< endl;
            break;
        }
    }
    
}