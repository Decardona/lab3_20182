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
}

void Store::ver_peliculas()
{
    for (unsigned int i=0; i<peliculas.size(); i++){
        cout<<"Pelcula numero "<<i+1<<endl;
        cout<<"Codigo: "<<peliculas.at(i).getId()<<endl;
        cout<<"Nombre: "<<peliculas.at(i).getNombre()<<endl;
        cout<<"Votos: "<<peliculas.at(i).getNvotos()<<endl;
        cout<<"Promedio de votos: "<<peliculas.at(i).getRating()<<endl;
    }
}

void Store::recomendar_peliculas()
{
    unsigned int size = peliculas.size(); int nvotos=0;
    float rank=0.0f;
    if (size>0){
        if (size>=3){
            unsigned int mas_votadas[3] = {1,1,1};
            unsigned int mejores_calificadas[3] = {1,1,1};
            for (unsigned int i=1; i<=size; i++){
                nvotos = peliculas.at(i).getNvotos();
                for (unsigned int j=0; j<3; j++){
                    if (peliculas.at(mas_votadas[j]).getNvotos()>nvotos){
                        mas_votadas[j] = i;
                        break;
                    }
                }
            }
            for (unsigned int i=0; i<=3; i++){
                rank = peliculas.at(mas_votadas[i]).getRating();
                for (unsigned int j=0; j<3; j++){
                   if (peliculas.at(mejores_calificadas[j]).getRating()<rank){
                       mejores_calificadas[j] = i;
                       break;
                   }
                }
            }
            cout<<"Podemos recomendarte las siguientes peliculas "<<endl;
            for (unsigned int i=0; i<3; i++){
                unsigned int idx = mejores_calificadas[i];
                cout<<"En la posicion "<<i<<" la pelicula "<<peliculas.at(idx).getNombre()<<" con "<<peliculas.at(idx).getRating()<<" en "<<peliculas.at(idx).getNvotos()<<" usuarios que calificaron"<<endl;
            }
        }
        else{
                cout<<"Hay muy pocas peliculas, no podemos garantizarte una buena pelicula. Solo hay "<<size<<" peliculas. Revisalas si quieres"<<endl;
            }
    }else{
        cout<<"No tenemos peliculas. Lo sentimos"<<endl;
    }
}
