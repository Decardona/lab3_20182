#include "libro.h"

Libro::Libro()
{

}

Libro::Libro(int c, string n, string a, char m, bool d)
{
    this->codigo = c;
    this->nombre = n;
    this->materia = m;
    this->autor = a;
    this->disponible = d;
}

void Libro::ver_informacion()
{
    cout<<"Codigo de libro: "<<this->codigo<<endl;
    cout<<"Nombre de libro: "<<this->nombre<<endl;
    cout<<"Materia del libro: "<<this->consultar_literatura(this->materia)<<endl;
    cout<<"Autor del libro: "<<this->autor<<endl;
    if(this->disponible)
        cout<<"Libro disponible"<<endl;
    else
        cout<<"Libro no disponible"<<endl;
}

void Libro::cambiar_nombre(string n)
{
    this->nombre = n;
}

void Libro::cambiar_materia(char m)
{
    this->materia = m;
}

void Libro::alquiler()
{
    if (this->disponible)
        this->disponible = false;
    else
        this->disponible = true;
}

string Libro::consultar_literatura(char l)
{
    switch (l){
    case 'L':
        return "Literatura";

    case 'C':
        return "Ciencias";

    case 'G':
        return "Geografia";

    case 'A':
        return "Arte";

    case 'E':
        return "Enciclopedia";

    case 'D':
        return "Diccionario";

    }
}
