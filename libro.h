#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
using namespace std;

class Libro
{
private:
    int codigo;
    string nombre, autor;
    char materia;
    bool disponible;
    friend bool buscar(Libro lib, string autor, string nombre);


public:
    Libro();
    Libro(int c, string n, string a, char m, bool d);

    void ver_informacion();
    void cambiar_nombre(string n);
    void cambiar_materia(char m);
    void alquiler();
    string consultar_literatura(char l);
};


#endif // LIBRO_H
