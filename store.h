#ifndef STORE_H
#define STORE_H

#include <vector>
#include <iostream>
#include "movie.h"

using namespace std;

class Store
{
    string nombre_tienda;
    vector<Movie> peliculas;

public:
    Store(string nombret);
    int buscar_movie(string nomb);
    void crear_pelicula(int _id, float _calificacion, string _nom, string _genero, string _director);
    void calificar_pelicula(float rating, unsigned int posicion);
    void ver_peliculas();
    void recomendar_peliculas();
};

#endif // STORE_H
