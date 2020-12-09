#ifndef VIDEOGAME_H
#define VIDEOGAME_H 

#include "Civilizacion.h"
#include "Videogame.h"
#include <vector>
class Videogame
{
    vector<Civilizacion> Civilizaciones;

public:

    void AgregarCivilizacion(const Civilizacion &C);
    void Mostrar();
    void Insertar(const Civilizacion &C, size_t pos);
    size_t size();
    void Inicializar(const Civilizacion &C, size_t n);
    void Primera();
    void Ultima();
    void OrdenarNombre();
    void OrdenarX();
    void OrdenarY();
    void OrdenarPuntuacion();
    void Eliminar(const string &Nombre);
    void Resumen();
    void Total();
    void respaldar_tabla();
    void respaldar();
    void recuperar();
    Civilizacion* Buscar(const Civilizacion &C);

    friend Videogame& operator<<(Videogame &vg, const Civilizacion &C)
    {
        vg.AgregarCivilizacion(C);

        return vg;
    }
};
#endif