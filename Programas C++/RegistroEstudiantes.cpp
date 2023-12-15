/*

Estructura Estudiante: Define una estructura para almacenar información sobre 
los estudiantes, que incluye el nombre y un vector de calificaciones (ahora de 
tipo double para aceptar calificaciones decimales).

Función agregarEstudiante: Agrega un nuevo estudiante al sistema. 
Solicita el nombre al usuario, crea un nuevo estudiante y lo añade 
al vector de estudiantes.

Función asignarCalificaciones: Permite al usuario ingresar calificaciones 
para un estudiante específico. Verifica que las calificaciones estén en el 
rango de 0.0 a 5.0 y las almacena en el vector de calificaciones del estudiante.

Función mostrarPromedio: Muestra el promedio de calificaciones para un 
estudiante. Calcula el promedio de las calificaciones almacenadas y lo
muestra con dos decimales.

Función main: El programa principal permite al usuario registrar estudiantes 
y asignar calificaciones. Termina cuando el usuario ingresa "fin". Luego, 
muestra el promedio de calificaciones para cada estudiante registrado.

*/

#include <iostream>
#include <vector>
#include <iomanip> // Para formatear la salida

using namespace std;

// Definir una estructura para los estudiantes
struct Estudiante {
    string nombre;
    vector<double> calificaciones; // Cambiado a double para aceptar calificaciones decimales
};

// Función para agregar un nuevo estudiante al sistema
void agregarEstudiante(vector<Estudiante>& estudiantes, const string& nombre) {
    Estudiante nuevoEstudiante;
    nuevoEstudiante.nombre = nombre;
    estudiantes.push_back(nuevoEstudiante);
    cout << "Estudiante agregado: " << nombre << endl;
}

// Función para asignar calificaciones a un estudiante
void asignarCalificaciones(Estudiante& estudiante) {
    cout << "Ingrese las calificaciones para " << estudiante.nombre << " (separadas por espacios): ";

    double calificacion;
    while (cin >> calificacion) {
        // Verificar que la calificación esté en el rango válido
        if (calificacion >= 0.0 && calificacion <= 5.0) {
            estudiante.calificaciones.push_back(calificacion);
        } else {
            cout << "Error: La calificación debe estar entre 0.0 y 5.0. Intente nuevamente." << endl;
        }

        // Romper el bucle si el usuario ingresa un carácter no numérico
        if (cin.peek() == '\n') {
            break;
        }
    }
}

// Función para mostrar el promedio de calificaciones de un estudiante
void mostrarPromedio(const Estudiante& estudiante) {
    if (estudiante.calificaciones.empty()) {
        cout << "El estudiante " << estudiante.nombre << " no tiene calificaciones." << endl;
    } else {
        double suma = 0.0;
        for (double calificacion : estudiante.calificaciones) {
            suma += calificacion;
        }

        double promedio = suma / estudiante.calificaciones.size();

        // Mostrar el promedio con dos decimales
        cout << fixed << setprecision(2);
        cout << "Promedio de " << estudiante.nombre << ": " << promedio << endl;
    }
}

int main() {
    vector<Estudiante> estudiantes;

    // Permitir al usuario registrar estudiantes
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

    // Mostrar el promedio para cada estudiante
    for (const Estudiante& estudiante : estudiantes) {
        mostrarPromedio(estudiante);
    }

    return 0;
}
