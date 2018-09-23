#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
using namespace std;

class Movie
{
    int id, nvotos;
    string nombre, genero, director;
    float rating_promedio;
public:
    Movie();
    Movie(int _id, int _nvotos, float _rating, string _nombre, string _genero, string _director);
    Movie(const Movie &obj);
    void setIdentificador(int _id);
    void setNvotos(int _nvotos);
    void setNombre(string _nombre);
    void setGenero(string _genero);
    void setDirector(string _director);
    void setRating_pro(float rating);
    void agregar_voto();
    int getId();
    int getNvotos();
    string getNombre();
    string getGenero();
    string getDirector();
    float getRating();
};

#endif // MOVIE_H
