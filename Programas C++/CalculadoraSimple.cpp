//CALCULADORA SIMPLE:
#include <iostream>
#include <locale.h>



using namespace std;

//FUNCIONES:

//Función sumar:
int sumar(int a, int b){
    return a + b;
}

//Función restas:
int restar(int a, int b){
    return a - b;
}

//Funcion multiplicar:
int multiplicar(int a, int b){
    return a * b;
}

//Funcion dividir:
int dividir(int a, int b){
    if(b != 0){
        return static_cast<float>(a) / b;
        }
    else{
        cout << "Error: No se puede dividir entre cero." << endl;
        return 0.0;
    }
}

//Función Principal:
int main(){

    setlocale(LC_ALL, "Spanish");
    int num1, num2, opc;
    cout << "Ingrese el primer numero: "; cin >> num1;
    cout << "Ingrese el segundo numero: "; cin >> num2;

    cout<<"Seleccione una opción: "<<endl;
    cout<<"1. Sumar"<<endl;
    cout<<"2. Restar"<<endl;
    cout<<"3. Multiplicar"<<endl;
    cout<<"4. Dividir"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<"Opcion: "; cin>>opc;

    switch(opc){
        case 1:
        cout << "Resultado: " << sumar(num1, num2) << endl;
            break;
        case 2:
        cout << "Resultado: " << restar(num1, num2) << endl;
            break;
        case 3:
        cout << "Resultado: " << multiplicar(num1, num2)<< endl;
            break;
        case 4:
        cout << "Resultado: " << dividir(num1, num2) << endl;
            break;
        default:
            cout<<"Opcion erronea :( ";
            break;
    }
}