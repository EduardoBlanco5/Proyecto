#include "Videogame.h"
#include <fstream>
#include <algorithm>

void Videogame::AgregarCivilizacion(const Civilizacion &C)
{
    Civilizaciones.push_back(C);
}

void Videogame::Insertar(const Civilizacion &C, size_t pos)
{
    Civilizaciones.insert(Civilizaciones.begin() + pos, C);
}
size_t Videogame::size()
{
    return Civilizaciones.size();
}

void Videogame::Inicializar(const Civilizacion &C, size_t n)
{
    Civilizaciones = vector<Civilizacion>(n, C);
}

void Videogame::Eliminar(const string &Nombre)
{
    for (auto it = Civilizaciones.begin(); it != Civilizaciones.end(); it++)
    {
        Civilizacion &C = *it;

        if (Nombre == C.getNombre())
        {
            Civilizaciones.erase(it);
            break;
        }
    }
}

Civilizacion *Videogame::Buscar(const Civilizacion &C)
{
    auto it = find(Civilizaciones.begin(), Civilizaciones.end(), C);

    if (it == Civilizaciones.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}

void Videogame::Primera()
{
    if (Civilizaciones.empty())
    {
        cout << "Vector vacio..." << endl;
    }
    else
    {
        cout << Civilizaciones.front() << endl;
    }
}

void Videogame::Ultima()
{
    if (Civilizaciones.empty())
    {
        cout << "Vector vacio..." << endl;
    }
    else
    {
        cout << Civilizaciones.back() << endl;
    }
}

void Videogame::OrdenarNombre()
{
    sort(Civilizaciones.begin(), Civilizaciones.end(),
         [](Civilizacion C1, Civilizacion C2) { return C1.getNombre() < C2.getNombre(); });
}
void Videogame::OrdenarX()
{
    sort(Civilizaciones.begin(), Civilizaciones.end(),
         [](Civilizacion C1, Civilizacion C2) { return C1.getX() < C2.getX(); });
}
void Videogame::OrdenarY()
{
    sort(Civilizaciones.begin(), Civilizaciones.end(),
         [](Civilizacion C1, Civilizacion C2) { return C1.getY() < C2.getY(); });
}
void Videogame::OrdenarPuntuacion()
{
    sort(Civilizaciones.begin(), Civilizaciones.end(),
         [](Civilizacion C1, Civilizacion C2) { return C1.getPuntuacion() > C2.getPuntuacion(); });
}

void Videogame::Resumen()
{
    cout << left;
    cout << setw(25) << "Nombre de Civilizacion";
    cout << setw(25) << "Ubicacion en X";
    cout << setw(25) << "Ubicacion en Y";
    cout << setw(20) << "Puntuacion";
    cout << endl;
    for (size_t i = 0; i < Civilizaciones.size(); i++)
    {
        Civilizacion &C = Civilizaciones[i];
        cout << C;
    }
}

void Videogame::Total()
{
    int cont;
    for (auto it = Civilizaciones.begin(); it != Civilizaciones.end(); it++)
    {
        Civilizacion &C = *it;
        cont++;
    }
    cout << "Total de civilizaciones: " << cont << " " << endl;
}

void Videogame::respaldar_tabla()
{

    ofstream archivo("Civilizaciones_tabla.txt");
    if (archivo.is_open())
    {
        cout << left;
        cout << setw(25) << "Nombre de Civilizacion";
        cout << setw(25) << "Ubicacion en X";
        cout << setw(25) << "Ubicacion en Y";
        cout << setw(20) << "Puntuacion";
        cout << endl;
        for (size_t i = 0; i < Civilizaciones.size(); i++)
        {
            Civilizacion &C = Civilizaciones[i];
            archivo << C;
        }
    }
    archivo.close();
}

void Videogame::respaldar()
{

    ofstream archivo("Civilizaciones.txt");
    if (archivo.is_open())
    {
        for (size_t i = 0; i < Civilizaciones.size(); i++)
        {
            Civilizacion &C = Civilizaciones[i];
            archivo << C.getNombre() << endl;
            archivo << C.getX() << endl;
            archivo << C.getY() << endl;
            archivo << C.getPuntuacion() << endl;
        }
    }
    archivo.close();
}

void Videogame::recuperar()
{
    ifstream archivo("Civilizaciones.txt");
    if (archivo.is_open())
    {
        string temp;
        int Y;
        float Puntuacion;
        Civilizacion C;

        while (true)
        {
            getline(archivo, temp);
            if (archivo.eof())
            {
                break;
            }
            C.setNombre(temp);

            getline(archivo, temp);
            C.setX(temp);

            getline(archivo, temp);
            Puntuacion = stof(temp); //string-to-float
            C.setPuntuacion(Puntuacion);

            getline(archivo, temp);
            Y = stoi(temp); //string-to-int
            C.setY(Y);

            AgregarCivilizacion(C);
        }
    }
    archivo.close();
}