#include <iostream>
#include <vector>
#include <algorithm> // Para usar la función sort
#include <map>       // Para usar la estructura de mapa

using namespace std;

// Función para obtener datos del usuario
vector<double> obtenerDatosUsuario() {
    cout << "Ingrese un conjunto de números separados por espacios (finalice con un carácter no numérico): ";
    
    vector<double> datos;
    double numero;

    while (cin >> numero) {
        datos.push_back(numero);
    }

    return datos;
}

// Función para calcular la media de un conjunto de números
double calcularMedia(const vector<double>& datos) {
    if (datos.empty()) {
        return 0.0;
    }

    double suma = 0.0;
    for (double dato : datos) {
        suma += dato;
    }

    return suma / datos.size();
}

// Función para calcular la mediana de un conjunto de números
double calcularMediana(vector<double> datos) {
    if (datos.empty()) {
        return 0.0;
    }

    sort(datos.begin(), datos.end());

    size_t tamano = datos.size();

    if (tamano % 2 == 0) {
        // Si el tamaño es par, calcular el promedio de los dos valores centrales
        return (datos[tamano / 2 - 1] + datos[tamano / 2]) / 2.0;
    } else {
        // Si el tamaño es impar, devolver el valor central
        return datos[tamano / 2];
    }
}

// Función para calcular la moda de un conjunto de números
vector<double> calcularModa(const vector<double>& datos) {
    map<double, int> frecuencias;

    for (double dato : datos) {
        frecuencias[dato]++;
    }

    int maxFrecuencia = 0;

    for (const auto& par : frecuencias) {
        if (par.second > maxFrecuencia) {
            maxFrecuencia = par.second;
        }
    }

    vector<double> moda;

    for (const auto& par : frecuencias) {
        if (par.second == maxFrecuencia) {
            moda.push_back(par.first);
        }
    }

    return moda;
}

int main() {
    // Obtener datos del usuario
    vector<double> datos = obtenerDatosUsuario();

    // Calcular y mostrar estadísticas
    cout << "Media: " << calcularMedia(datos) << endl;
    cout << "Mediana: " << calcularMediana(datos) << endl;

    vector<double> moda = calcularModa(datos);
    cout << "Moda: ";
    for (double valor : moda) {
        cout << valor << " ";
    }
    cout << endl;

    return 0;
}
