//Primer código C++
#include <iostream>

using namespace std;

int isPar(){
    int n;
    cout << "Ingrese un número: ";
    cin >> n;
    if (n % 2 == 0){
        cout << "El número es par" << endl;
    } else {
        cout << "El número es impar" << endl;
    }
    return 0;
}


int main() {
    cout << "Hola Mundo" << endl;
    isPar();
    return 0;
}