#include <stdio.h>



int main(){
    //Variables
    int opc;
    int saldo = 10000;

    //Menu
    printf("\tBienvenido a su cajero automatico\n");
    printf("1. Consultar saldo\n");
    printf("2. Retirar dinero\n");
    printf("3. Depositar dinero\n");   
    printf("4. Salir\n");
    printf("Que operacion desea realizar?\n");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        printf("Su saldo es de: %d\n", saldo);
        break;

    case 2:
        printf("Cuanto dinero desea retirar?\n");
        int retiro;
        scanf("%d", &retiro);
        if(retiro > saldo){
            printf("No tiene suficiente saldo\n");
        }else{
            saldo = saldo - retiro;
            printf("Retiro exitoso\n");
        }
        printf("Su saldo es de: %d\n", saldo);
        break;

    case 3:
        printf("Cuanto dinero desea depositar?\n");
        int deposito;
        scanf("%d", &deposito);
        saldo = saldo + deposito;
        printf("Deposito exitoso\n");
        printf("Su saldo es de: %d\n", saldo);
        break;

    case 4:
        printf("Gracias por usar el cajero automatico\n");
        break;
    
    default:
        break;
    }
}
