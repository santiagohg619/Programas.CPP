#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Estructura para las calificaciones de una materia
struct MateriaCalificaciones {
    string nombreMateria;
    vector<double> calificaciones;
};

// Estructura para los estudiantes
struct Estudiante {
    string nombre;
    vector<MateriaCalificaciones> materiasCalificaciones;
};

// Función para agregar un nuevo estudiante al sistema
void agregarEstudiante(vector<Estudiante>& estudiantes, const string& nombre) {
    Estudiante nuevoEstudiante;
    nuevoEstudiante.nombre = nombre;
    estudiantes.push_back(nuevoEstudiante);
}

// Función para asignar calificaciones a un estudiante para una materia específica
void asignarCalificaciones(Estudiante& estudiante, const string& materia) {
    MateriaCalificaciones materiaCalif;
    materiaCalif.nombreMateria = materia;

    cout << "Ingrese las calificaciones para " << materia << " del estudiante " << estudiante.nombre << " (separadas por espacios): ";

    double calificacion;
    while (cin >> calificacion) {
        // Verificar que la calificación esté en el rango válido
        if (calificacion >= 0.0 && calificacion <= 5.0) {
            materiaCalif.calificaciones.push_back(calificacion);
        } else {
            cout << "Error: La calificación debe estar entre 0.0 y 5.0. Intente nuevamente." << endl;
        }

        // Romper el bucle si el usuario ingresa un carácter no numérico
        if (cin.peek() == '\n') {
            break;
        }
    }

    estudiante.materiasCalificaciones.push_back(materiaCalif);
}

// Función para mostrar el promedio de calificaciones de un estudiante en cada materia
void mostrarPromedioEstudiante(const Estudiante& estudiante, const vector<string>& materias) {
    cout << setw(15) << left << estudiante.nombre << " | ";
    for (const string& materia : materias) {
        for (const MateriaCalificaciones& materiaCalif : estudiante.materiasCalificaciones) {
            if (materiaCalif.nombreMateria == materia) {
                double suma = 0.0;
                size_t totalCalificaciones = materiaCalif.calificaciones.size();

                // Sumar todas las calificaciones para la materia específica
                for (const double& calificacion : materiaCalif.calificaciones) {
                    suma += calificacion;
                }

                // Calcular y mostrar el promedio con dos decimales
                if (totalCalificaciones > 0) {
                    double promedio = suma / totalCalificaciones;
                    cout << setw(10) << fixed << setprecision(2) << promedio << " | ";
                }
            }
        }
    }
    cout << endl;
}

// Función para mostrar el promedio de calificaciones de cada materia
void mostrarPromedioMaterias(const vector<Estudiante>& estudiantes, const vector<string>& materias) {
    cout << setw(15) << left << "Materia" << " | ";
    for (const string& materia : materias) {
        double suma = 0.0;
        size_t totalCalificaciones = 0;

        // Sumar todas las calificaciones para la materia específica
        for (const Estudiante& estudiante : estudiantes) {
            for (const MateriaCalificaciones& materiaCalif : estudiante.materiasCalificaciones) {
                if (materiaCalif.nombreMateria == materia) {
                    for (const double& calificacion : materiaCalif.calificaciones) {
                        suma += calificacion;
                        ++totalCalificaciones;
                    }
                }
            }
        }

        // Calcular y mostrar el promedio con dos decimales
        if (totalCalificaciones > 0) {
            double promedio = suma / totalCalificaciones;
            cout << setw(10) << fixed << setprecision(2) << promedio << " | ";
        }
    }
    cout << endl;
}

int main() {
    vector<Estudiante> estudiantes;
    vector<string> materias;

    // Permitir al usuario registrar materias
    cout << "Ingrese la cantidad de materias: ";
    int cantidadMaterias;
    cin >> cantidadMaterias;

    for (int i = 0; i < cantidadMaterias; ++i) {
        cout << "Ingrese el nombre de la materia " << i + 1 << ": ";
        string materia;
        cin >> materia;
        materias.push_back(materia);
    }

    // Permitir al usuario registrar estudiantes
    while (true) {
        cout << "Ingrese el nombre del estudiante (o 'fin' para terminar): ";
        string nombre;
        cin >> nombre;

        if (nombre == "fin") {
            break;
        }

        agregarEstudiante(estudiantes, nombre);

        // Asignar calificaciones para cada materia
        for (const string& materia : materias) {
            asignarCalificaciones(estudiantes.back(), materia);
        }
    }

    // Mostrar la información en formato de tabla
    cout << endl;
    cout << setw(15) << left << "Estudiante" << " | ";
    for (const string& materia : materias) {
        cout << setw(10) << materia << " | ";
    }
    cout << endl;
    cout << string(15 + 15 * materias.size(), '-') << endl;

    // Mostrar el promedio para cada estudiante en cada materia
    for (const Estudiante& estudiante : estudiantes) {
        mostrarPromedioEstudiante(estudiante, materias);
    }

    // Mostrar el promedio para cada materia
    mostrarPromedioMaterias(estudiantes, materias);

    return 0;
}
