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
*	Implemente una clase amiga que permita saber si un "Libro" esta disponible o prestado
*/


#include "libro.h"

bool buscar(Libro lb, string autor, string nombre){
    if (lb.nombre == nombre && lb.autor == autor)
        return true;
    else
        return false;
}

int main(){

    int codigo;
    string nombre, autor;
    char materia;

    cout<<"Bienvenido a la biblioteca info 2"<<endl;
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

    cout<<"Digite un nombre de libro para buscar: ";
    cin>>nombre;
    cout<<"Digite un nombre de autor de libro: ";
    cin>>autor;
    if (buscar(lb1, autor, nombre))
        cout<<"El libro si existe"<<endl;
    else
        cout<<"El libro no existe. Lo sentimos"<<endl;

    return 0;
}
