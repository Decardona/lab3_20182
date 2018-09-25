#include "store.h"

Store::Store(string nombret)
{
    this->nombre_tienda = nombret;
}

int Store::buscar_movie(string nomb)
{
    int retorno = -1;
    unsigned int i = 0, tamanio = peliculas.size();
    if (tamanio>0)
    {
        do{
            if (peliculas.at(i).getNombre().compare(nomb) == 0){
                retorno = i;
                goto l;
            }
            else if (i<tamanio)
                i++;
        }while(i<tamanio);
    }
    l:
    return retorno;
}

void Store::crear_pelicula(int _id, float _calificacion, string _nom, string _genero, string _director)
{
    peliculas.push_back(Movie (_id, 1, _calificacion, _nom, _genero, _director));

}

void Store::calificar_pelicula(float rating, unsigned int posicion)
{
    peliculas.at(posicion).setRating_pro(rating);
    cout<<"Listo. Hemos agregado tu calificacion"<<endl<<endl;
}

void Store::ver_peliculas()
{
    if (peliculas.size()==0)
    {
        cout<<"Nada que mostrar. No tenemos peliculas"<<endl<<endl;
    }else{

        for (unsigned int i=0; i<peliculas.size(); i++){
        cout<<endl<<"---------- Pelcula numero "<<i+1<<endl;
        cout<<"Codigo: "<<peliculas.at(i).getId()<<endl;
        cout<<"Nombre: "<<peliculas.at(i).getNombre()<<endl;
        cout<<"Votos: "<<peliculas.at(i).getNvotos()<<endl;
        cout<<"Promedio de votos: "<<peliculas.at(i).getRating()<<endl;
        }
     }
}

void Store::recomendar_peliculas()
{
    unsigned int size = peliculas.size(), ida=0; int nvotos=0;
    if (size>0){
        if (size>=3){
            unsigned int mas_votadas[2] = {0,0};
            unsigned int mejores_calificadas[2] = {0,0};
            for (unsigned int i=1; i<size; i++){
                nvotos = peliculas.at(i).getNvotos();
                if (nvotos>peliculas.at(mas_votadas[0]).getNvotos()){
                    ida = mas_votadas[0];
                    mas_votadas[0] = i;
                    mas_votadas[1] = ida;
                }else if (nvotos>peliculas.at(mas_votadas[1]).getNvotos() and mas_votadas[1] != i){
                    mas_votadas[1] = i;
                }
            }
            if (peliculas.at(mas_votadas[1]).getRating()>peliculas.at(mas_votadas[0]).getRating()){
                mejores_calificadas[0] = mas_votadas[1];
                mejores_calificadas[1] = mas_votadas [0];
            }else{
                mejores_calificadas[0] = mas_votadas[0];
                mejores_calificadas[1] = mas_votadas [1];
            }
            cout<<"Podemos recomendarte las siguientes peliculas "<<endl;
            for (unsigned int i=0; i<2; i++){
                unsigned int idx = mejores_calificadas[i];
                cout<<"En la posicion "<<i+1<<" la pelicula "<<peliculas.at(idx).getNombre()<<" con un ranking de "<<peliculas.at(idx).getRating()<<" de "<<peliculas.at(idx).getNvotos()<<" calificaciones"<<endl;
            }
        }
        else{
                cout<<"Hay muy pocas peliculas, no podemos garantizarte una buena pelicula. Solo hay "<<size<<" peliculas. Revisalas si quieres"<<endl<<endl;
            }
    }else{
        cout<<"No tenemos peliculas. Lo sentimos"<<endl<<endl;
    }
}

void Store::agregar_libro(Libro lb)
{
    this->lib.push_back(lb);
}


void Store::verificar_libro()
{
    if (this->lib.size()>0){
        if (this->lib.at(0).disponible)
            cout<<"El libro "<<this->lib.at(0).nombre<<" esta disponible"<<endl;
        else
            cout<<"El libro "<<this->lib.at(0).nombre<<" no esta disponible"<<endl;
    }else{
        cout<<"No hay libros en nuestra tienda. Debes crear uno"<<endl;
    }
}
