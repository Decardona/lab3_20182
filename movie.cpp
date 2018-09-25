#include "movie.h"

Movie::Movie()
{
    this->nvotos = 0;
    this->rating_promedio = 0.0f;
}

Movie::Movie(int _id, int _nvotos, float _rating, string _nombre, string _genero, string _director)
{
    this->id = _id;
    this->nombre = _nombre;
    this->genero = _genero;
    this->director = _director;
    this->nvotos = _nvotos;
    this->rating_promedio = 0.0f +_rating;
}

Movie::Movie(const Movie &obj)
{
    this->id = obj.id;
    this->nombre = obj.nombre;
    this->genero = obj.genero;
    this->director = obj.director;
    this->nvotos = obj.nvotos;
    this->rating_promedio = obj.rating_promedio;
}

void Movie::setIdentificador(int _id)
{
    this->id = _id;
}

void Movie::setNvotos(int _nvotos)
{
    this->nvotos = _nvotos;
}

void Movie::setNombre(string _nombre)
{
    this->nombre = _nombre;
}

void Movie::setGenero(string _genero)
{
    this->genero = _genero;
}

void Movie::setDirector(string _director)
{
    this->director = _director;
}

void Movie::setRating_pro(float rating)
{
    float auxiliar = 0.0f;
    this->agregar_voto();
    if (this->getNvotos()==1){
        this->rating_promedio = rating;
    }else{
        auxiliar = rating + this->getRating();
        this->rating_promedio = (float) auxiliar/2;
    }

}

void Movie::agregar_voto()
{
    this->nvotos +=1;
}

int Movie::getId()
{
    return this->id;
}

int Movie::getNvotos()
{
    return this->nvotos;
}

string Movie::getNombre()
{
    return this->nombre;
}

string Movie::getGenero()
{
    return this->genero;
}

string Movie::getDirector()
{
    return this->director;
}

float Movie::getRating()
{
    return this->rating_promedio;
}
