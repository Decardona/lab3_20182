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
    unsigned int size = peliculas.size(), j=0, ida=0; int nvotos=0, aux=0;
    float rank=0.0f;
    if (size>0){
        if (size>=3){
            unsigned int mas_votadas[3] = {0,0,0};
            unsigned int mejores_calificadas[3] = {0,0,0};
            for (unsigned int i=1; i<size; i++){
                nvotos = peliculas.at(i).getNvotos();
                for (j=0; j<3; j++){
                    aux = peliculas.at(mas_votadas[j]).getNvotos();
                    if (aux<nvotos){
                        ida = mas_votadas[j];
                        mas_votadas[j] = i;
                        if (j<=2){
                            mas_votadas[j+1]=ida;
                        }
                        j=3;
                    }
                }
            }
            j=0;
            for (unsigned int i=0; i<3; i++){
                rank = peliculas.at(mas_votadas[i]).getRating();
                j = i+1;
                if (j==3)
                    j=2;
                if (rank<peliculas.at(mas_votadas[j]).getRating()){
                    mejores_calificadas[j] = mas_votadas[i];
                    mejores_calificadas[i] = mas_votadas[j];
                }

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
