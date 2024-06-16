#include <stdio.h>
/*
Comprobar la nota de un alumno
*/
int main(){
    //Variables
    float nota1, nota2, nota3, promedio;

    //Lectura de datos:
    printf("Introduce la nota 1: ");
    scanf("%f", &nota1);
    printf("Introduce la nota 2: ");
    scanf("%f", &nota2);
    printf("Introduce la nota 3: ");
    scanf("%f", &nota3);

    //Calculo del promedio
    promedio = (nota1 + nota2 + nota3) / 3;

    //Comprobacion de la nota final
    if(promedio >= 7){
        printf("El alumno ha aprobado con un promedio de: %.2f\n", promedio);
    }
    else{
        printf("El alumno ha reprobado con un promedio de: %.2f\n", promedio);
    }
}