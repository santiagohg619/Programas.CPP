#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

//Funcion #1
void numeroMasRepetido(){
    // Leer la cantidad de números
    int n;
    printf("Ingrese la dimension del arreglo: ");
    scanf("%d", &n);
    int arreglo[n];

    // Leer los números
    for (int i = 0; i < n; i++) {
        printf("Ingrese el valor de la posicion %d: ", i);
        scanf("%d", &arreglo[i]);
    }

    // Encontrar el elemento que más se repite
    int elementoMasRepetido, vecesRepetido = 0;
    for (int i = 0; i < n; i++) {
        int contador = 0;
        for (int j = 0; j < n; j++) {
            if (arreglo[j] == arreglo[i]) {
                contador++;
            }
        }
        if (contador > vecesRepetido) {
            vecesRepetido = contador;
            elementoMasRepetido = arreglo[i];
        }
    }
    printf("El elemento que más se repite es %d y se repite %d veces.\n", elementoMasRepetido, vecesRepetido);
}

void diagonalesMatriz(){
    //Tamano de la matriz:
    int dim;
    printf("\nIngrese la dimension de la matriz: ");
    scanf("%d", &dim);

    //Declarar la matriz
    float matriz[dim][dim];
    
    //Llenar la matriz
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            printf("Ingrese el valor de la posicion [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }

    //Diagonal principal
    // Encontrar el mayor valor en la diagonal principal
    float mayorDiagonalPrincipal = matriz[0][0];
    for (int i = 1; i < dim; i++) {
        if (matriz[i][i] > mayorDiagonalPrincipal) {
            mayorDiagonalPrincipal = matriz[i][i];
        }
    }

    //Diagonal secundaria
    // Encontrar el mayor valor en la diagonal secundaria
    float mayorDiagonalSecundaria = matriz[0][dim - 1];
    for (int i = 1; i < dim; i++) {
        if (matriz[i][dim - 1 - i] > mayorDiagonalSecundaria) {
            mayorDiagonalSecundaria = matriz[i][dim - 1 - i];
        }
    }

    printf("El mayor valor en la diagonal principal es: %.2f\n", mayorDiagonalPrincipal);
    printf("El mayor valor en la diagonal secundaria es: %.2f\n", mayorDiagonalSecundaria);
}

bool esPrimo(int n){
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void factoresPrimos(int n){
    printf("Los factores primos de %d son: ", n);
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }
    printf("\n");
}

int productoPunto(int vector1[], int vector2[]){
    int producto = 0;
    for (int i = 0; i < 3; i++){
        producto += vector1[i] * vector2[i];
    }
    return producto;

}

int main(){
    int opcion; //Variable para el menu
    int numeroPrimo; //Variable para verificar si un numero es primo
    int num; //Variable para los factores primos
    int dim; //Variable para la dimension de los vectores

    while(1){
        printf("\t [MENU DE OPCIONES]\n");
        printf("\n\n");
        printf("1. Numero que más se repite dentro de un arreglo\n");
        printf("2. Mayor valor dentro de la diagonal principal y diagonal secundaria de una matriz\n");
        printf("3. Determinar si un numero es primo\n");
        printf("4. Mostrar los factores primos de un numero\n");
        printf("5. Producto punto entre 2 vectores\n");
        printf("6. Suma de 2 matrices\n");
        printf("7. Multiplicacion entre 2 matrices\n");
        printf("8. Invertir un arreglo\n");
        printf("9. Calcular de base 10 a binario\n");
        printf("10. Calcular de binario a base 10\n");
        printf("11. ostrar la suma de los valores que se encuentran en la periferia de la misma\n");
        printf("12. Calcular matriz transpuesta\n");
        printf("13. Salir\n\n");

        printf("\n\tIngrese la opcion que desea: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                numeroMasRepetido();
                break;

            case 2:
                diagonalesMatriz();
                break;

            case 3:
                printf("Ingrese el numero que desea verificar si es primo: "); 
                scanf("%d", &numeroPrimo);
                if (esPrimo(numeroPrimo)) {
                    printf("El numero %d es primo.\n", numeroPrimo);
                } else {
                    printf("El numero %d no es primo.\n", numeroPrimo);
                }
                break;

            case 4:
                printf("Ingrese el numero del cual desea conocer sus factores primos: ");
                scanf("%d", &num);
                factoresPrimos(num);
                break;
            
            case 5:
                printf("Ingrese la dimension de los vectores: ");
                scanf("%d", &dim);
                int vector1[dim], vector2[dim];
                //Llenar los vectores
                //Vector 1
                for (int i = 0; i < dim; i++){
                    printf("Ingrese el valor del vector 1 en la posicion %d: ", i);
                    scanf("%d", &vector1[i]);
                }
                //Vector 2
                for (int i = 0; i < dim; i++){
                    printf("Ingrese el valor del vector 2 en la posicion %d: ", i);
                    scanf("%d", &vector2[i]);
                }
                printf("El producto punto entre los vectores es: %d\n", productoPunto(vector1, vector2));
                break;

            case 13:
                printf("Saliendo del programa...\n");
                return 0;
        }
    }
}
