
#include <stdio.h>

int main(){
    float precio, descuento, precioFinal;
    printf("Introduce el precio del producto: ");
    scanf("%f", &precio);

    descuento = precio * 0.15;
    precioFinal = precio - descuento;

    printf("El precio final del producto es: %.2f\n", precioFinal);

    return 0;
}