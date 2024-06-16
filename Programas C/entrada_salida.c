#include <stdio.h>

// Programa que pide un número por teclado y lo muestra por pantalla
// scanf() es una función que permite leer un valor por teclado
// & es el operador de dirección, que permite obtener la dirección de una variable
// printf() es una función que permite mostrar un valor por pantalla

int main(){
    int a;
    float b;
    char c;
    printf("Introduce un número: \n");
    scanf("%d", &a);
    printf("Introduce un número real: \n");
    scanf("%f", &b);
    printf("Introduce un carácter: \n");
    scanf(" %c", &c);

    printf("El número introducido es: %d\n", a);
    printf("El número real introducido es: %f\n", b);
    printf("El carácter introducido es: %c\n", c);

    return 0;
}