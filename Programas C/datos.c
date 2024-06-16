#include <stdio.h>

/*
* %c es el formato para imprimir un caracter
//Tamaño 1 byte rango: 0-255

* %d es el formato para imprimir un entero, short, long, doble
//Tamaño 1 byte rango: -128 a 127 = short
//Tamaño 2 bytes rango: -32,768 a 32,767 = entero
//Tamaño 4 bytes rango: -2,147,483,648 a 2,147,483,647 = long
//Tamaño 2 bytes rango: 0 a 65,535 = usigned int
//Tamaño 8 bytes rango: 1.7E-308 a 1.7E+308 = double

* %f es el formato para imprimir un flotante
//Tamaño 4 bytes rango: 3.4E-38 a 3.4E+38

* %s es el formato para imprimir una cadena de caracteres
//Tamaño 1 byte rango: 0-255
*/

int main(){
    char a = 'e';
    short b = 32767;
    int c = 32768;
    unsigned int d = 4294967295;
    long e = 2147483647;
    float f = 3.4E+38;
    double g = 1.7E+308;


    printf("El valor de a es: %c\n", a);
    printf("El valor de b es: %d\n", b);
    printf("El valor de c es: %d\n", c);
    printf("El valor de d es: %u\n", d);
    printf("El valor de e es: %ld\n", e);
    printf("El valor de f es: %f\n", f);
    printf("El valor de g es: %f\n", g);
    }