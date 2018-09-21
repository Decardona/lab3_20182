/* Practica de Laboratorio 3
*  Informatica 2 - 2018_2
*  Prof: Juan Camilo Correa Chica
*  Fecha: Septiembre 10/2018 - Septiembre 17/2018 - Septiembre 24/2018
*  Plazo máximo para enviar enlace para clonar el repositorio: Septiembre 10/2018 11:00pm
*  Estudiante1: Diego Esteban Cardona Bedoya
*  Estudiante2: Victor Parra Julio
*  Fecha del ultimo Commit en GitHub: 23:00
*
* 1. Diseñe e implemente una clase llamada "Libro" que tiene los siguientes atributos privados:
*	Un atributo de tipo entero para el codigo de catalogo del libro
*	Un atributo de tipo cadena de caracteres para el nombre del libro
*	Un atributo de tipo char para la materia del libro (L = Literatura, C = Ciencias, G = Geografia, A = Arte, E = Enciclopedia, D = Diccionario)
*	Un atributo de tipo cadena de caracteres para el nombre del autor
*	Un atributo tipo bool para indicar si el libro esta disponible o prestado (True = disponible, False = prestado)
*	
*	Adicionalmente la clase debe contar con metodos publicos para modificar y obtener el valor de los atributos
*   La clase debe tener un constructor que permita inicializar todos los atributos de la clase al declarar un objeto (NO es constructor por defecto)
*	Implemente una funcion amiga que permita buscar un "Libro" por Titulo y por Nombre de Autor
*	Implemente una clase amiga que permita saber si un "Libro" esta disponible o prestado*/
/* * 2. Diseñe e implemente una clase llamada "Movie" que tiene los siguientes atributos privados:
* Un atributo de tipo entero para el ID de la pelicula
* Un atributo de tipo cadena de caracteres para el nombre de la pelicula
* Un atributo de tipo cadena de caracteres para el genero de la pelicula
* Un atributo de tipo cadena de caracteres para el director de la pelicula
* Un atributo tipo float para el "rating promedio" de la pelicula (el rating es un valor de 0.0 a 5.0 con el que los cinefilos califican una pelicula)
* Un atributo tipo int que almacena el número de veces que la pelicula ha sido calificada
*
* El "rating promedio" de una pelicula se calcula como el total de la suma de todas las calificaciones que se le han dado a una pelicula
* sobre el numero de calificaciones.
*
* La clase debe contar con un constructor por defecto, un constructor para inicializar atributos al instanciar objetos de la clase y un
* constructor por copia.
* La clase debe contar con metodos para modificar y obtener el valor de cada atributo individualmente.
*
* 3. Utilizando la clase que acaba de implementar, diseñe una pequeña aplicacion que permite a un usuario calificar peliculas. Si la pelicula ya ha sido calificada previamente (es decir,
* si ya existe en la base de datos) entonces debe pedirle al usuario una calificación de 0.0 a 5.0 para esa pelicula. Si la pelicula no está
* en la base de datos, entonces el programa debe permitirle al usuario ingresar la nueva pelicula a la base de datos, con el diligenciamiento
* de todos sus datos, incluida la calificación de la pelicula por supuesto.
*
* La aplicación debe tener una opcion que sirve para recomendar peliculas a los usuarios. Esta recomendación se debe hacer de acuerdo a la
* popularidad y a la calificación de la pelicula. Es decir, se deben recomendar las peliculas con las calificaciones más altas y con el
* mayor número de calificaciones recibidas, osea que no tiene sentido recomendar una pelicula que ha sido calificada con 5.0 pero tiene
* una sola calificación de un aficionado al cine.
*/


#include "libro.h"
#include "store.h"

using namespace std;

bool buscar(Libro lb){
    string autor, nombre;
    cout<<"Digite un nombre de libro para buscar: ";
    cin>>nombre;
    cout<<"Digite un nombre de autor de libro: ";
    cin>>autor;
    if (lb.nombre == nombre && lb.autor == autor)
        return true;
    else
        return false;
}



int main(){

    int codigo, opcion=0;
    string nombre, autor;
    char materia;
    Store videotienda("Video_Info2");
    do{
        cout <<"Laboratorio N3 de informatica 2. Bienvenido"<<endl;
        cout<<"----Menu----"<<endl<<"Elija cualquiera de las siguientes opciones"<<endl<<endl;
        cout<<"1) Opciones de la clase libro 2) Opciones de la clase Movie 0) Salir: "<<endl;
        cin>>opcion;
        switch (opcion) {
            case 1:
            {
            cout<<endl<<"Bienvenido a la biblioteca info 2"<<endl;
            cout<<"Codigo para el libro: ";
            cin>>codigo;
            cout<<"Nombre del libro: ";
            cin>>nombre;
            cout<<"Autor del libro: ";
            cin>>autor;
            cout<<"Materia (L = Literatura, C = Ciencias, G = Geografia, A = Arte, E = Enciclopedia, D = Diccionario): ";
            cin>>materia;

            Libro lb1(codigo, nombre, autor, materia, true);
            lb1.ver_informacion();
            videotienda.agregar_libro(lb1);


            if (buscar(lb1))
                cout<<"El libro si existe"<<endl;
            else
                cout<<"El libro no existe. Lo sentimos"<<endl;
            break;
            }
        case 2:
            do{
                cout<<endl<<"Bienvenido a la opcion de Movie"<<endl;
                cout<<"1) Calificar peliculas |  2) Recomiendame una pelicula | 3) Ver todas las peliculas "<<endl;
                cout<<"4) Buscar si existe libro disponible en la tienda |  0) Salir "<<endl;
                cin>>opcion;
                switch (opcion) {
                    case 1:
                    {   string nom, director, genero;
                        int id = 0, index_movie=0;
                        float calificacion = 0.0f;
                        cout<<"Ingresa el nombre de la pelicula: ";
                        cin>>nom;
                        cout<<"Ingresa tu calificacion de esta pelicula entre 0 y 5: ";
                        cin>>calificacion;
                        index_movie = videotienda.buscar_movie(nom);

                        if (calificacion>5 or calificacion<0){
                            cout<<"Valor de calificacion incorrecto"<<endl;
                        }else{
                            if (index_movie>=0){
                                videotienda.calificar_pelicula(calificacion,index_movie);
                            }else{
                                cout<<"Al parecer tu pelicula no se ha agregado a nuestro sistema. Vamos a agregarla"<<endl;
                                cout<<"Identificador de la pelicula: ";
                                cin>>id;
                                cout<<"Genero de la pelicula: ";
                                cin>>genero;
                                cout<<"Director de la pelicula: ";
                                cin>>director;
                                videotienda.crear_pelicula(id,calificacion,nom,genero,director);
                                cout<<"Listo hemos agregado la pelicula con tu calificacion"<<endl;
                            }
                        }
                        break;
                    }
                    case 2:
                        videotienda.recomendar_peliculas();
                    break;
                    case 3:
                        videotienda.ver_peliculas();
                    break;
                    case 4:
                        videotienda.verificar_libro();
                    break;

                }
           }while(opcion>0);
           break;

        }

     }while (opcion>0);

    return 0;
}
