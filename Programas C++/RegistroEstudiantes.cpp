#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Estudiante {
    string nombre;
    vector<double> calificaciones;
};

void agregarEstudiante(vector<Estudiante>& estudiantes, const string& nombre) {
    Estudiante nuevoEstudiante;
    nuevoEstudiante.nombre = nombre;
    estudiantes.push_back(nuevoEstudiante);
    cout << "Estudiante agregado: " << nombre << endl;
}

void asignarCalificaciones(Estudiante& estudiante) {
    cout << "Ingrese las calificaciones para " << estudiante.nombre << " (separadas por espacios): ";

    double calificacion;
    while (cin >> calificacion) {
        if (calificacion >= 0.0 && calificacion <= 5.0) {
            estudiante.calificaciones.push_back(calificacion);
        } else {
            cerr << "Error: La calificación debe estar entre 0.0 y 5.0. Intente nuevamente." << endl;
        }

        if (cin.peek() == '\n') {
            break;
        }
    }
}

void mostrarPromedio(const Estudiante& estudiante) {
    if (estudiante.calificaciones.empty()) {
        cout << "El estudiante " << estudiante.nombre << " no tiene calificaciones." << endl;
    } else {
        double suma = 0.0;
        for (double calificacion : estudiante.calificaciones) {
            suma += calificacion;
        }

        double promedio = suma / estudiante.calificaciones.size();
        cout << fixed << setprecision(2);
        cout << "Promedio de " << estudiante.nombre << ": " << promedio << endl;
    }
}

int main() {
    vector<Estudiante> estudiantes;

    while (true) {
        cout << "Ingrese el nombre del estudiante (o 'fin' para terminar): ";
        string nombre;
        cin >> nombre;

        if (nombre == "fin") {
            break;
        }

        agregarEstudiante(estudiantes, nombre);
        asignarCalificaciones(estudiantes.back());
    }

    for (const Estudiante& estudiante : estudiantes) {
        mostrarPromedio(estudiante);
    }

    return 0;
}
