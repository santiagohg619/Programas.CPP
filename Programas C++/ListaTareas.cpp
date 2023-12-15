/*
Estructura Tarea: Define una estructura para representar una tarea, que 
tiene una descripción y un estado de completado (bool).

Funciones agregarTarea, marcarComoCompletada y mostrarLista: Estas 
funciones realizan las operaciones específicas de agregar una tarea, 
marcar una tarea como completada y mostrar la lista de tareas, respectivamente.

Función main: La función principal del programa, que maneja la interacción 
con el usuario y llama a las funciones correspondientes según la opción 
seleccionada. El programa continuará ejecutándose hasta que el usuario elija salir (0).

*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Definición de una estructura llamada 'Tarea'
struct Tarea {
    string descripcion;
    bool completada;
};

// Función para agregar una nueva tarea a la lista
void agregarTarea(vector<Tarea>& listaTareas, const string& descripcion) {
    // Crear una nueva tarea con la descripción proporcionada y establecer su estado como no completada
    Tarea nuevaTarea = {descripcion, false};
    // Agregar la nueva tarea al final de la lista de tareas
    listaTareas.push_back(nuevaTarea);
    // Informar al usuario que la tarea ha sido agregada
    cout << "Tarea agregada: " << descripcion << endl;
}

// Función para marcar una tarea como completada
void marcarComoCompletada(vector<Tarea>& listaTareas, int indice) {
    // Verificar que el índice proporcionado esté dentro del rango de la lista de tareas
    if (indice >= 0 && indice < static_cast<int>(listaTareas.size())) {
        // Marcar la tarea en la posición indicada como completada
        listaTareas[indice].completada = true;
        // Informar al usuario que la tarea ha sido marcada como completada
        cout << "Tarea marcada como completada: " << listaTareas[indice].descripcion << endl;
    } else {
        // Informar al usuario que el índice no es válido
        cout << "Índice no válido." << endl;
    }
}

// Función para mostrar la lista de tareas
void mostrarLista(const vector<Tarea>& listaTareas) {
    // Imprimir el encabezado de la lista de tareas
    cout << "Lista de Tareas:" << endl;
    // Iterar a través de la lista de tareas e imprimir cada tarea con su estado
    for (size_t i = 0; i < listaTareas.size(); ++i) {
        cout << "[" << i + 1 << "] "; // Índice de la tarea
        cout << (listaTareas[i].completada ? "[X] " : "[ ] "); // Estado de la tarea
        cout << listaTareas[i].descripcion << endl; // Descripción de la tarea
    }
}

// Función principal (main) del programa
int main() {
    vector<Tarea> listaTareas; // Crear una lista de tareas vacía
    int opcion; // Variable para almacenar la opción seleccionada por el usuario

    // Bucle principal del programa
    do {
        cout << "\nSeleccione una opción:" << endl;
        cout << "1. Agregar Tarea\n2. Marcar como Completada\n3. Mostrar Lista\n0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        // Switch para manejar las diferentes opciones seleccionadas por el usuario
        switch (opcion) {
            case 1: {
                // Opción para agregar una nueva tarea
                cout << "Ingrese la descripción de la tarea: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el búfer
                string nuevaDescripcion;
                getline(cin, nuevaDescripcion); // Leer la descripción de la nueva tarea
                agregarTarea(listaTareas, nuevaDescripcion); // Llamar a la función para agregar la tarea
                break;
            }
            case 2: {
                // Opción para marcar una tarea como completada
                cout << "Ingrese el índice de la tarea a marcar como completada: ";
                int indice;
                cin >> indice; // Leer el índice de la tarea a marcar como completada
                marcarComoCompletada(listaTareas, indice - 1); // Llamar a la función para marcar la tarea como completada
                break;
            }
            case 3:
                // Opción para mostrar la lista de tareas
                mostrarLista(listaTareas);
                break;
            case 0:
                // Opción para salir del programa
                cout << "Saliendo del programa." << endl;
                break;
            default:
                // Opción no válida
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 0); // Continuar el bucle mientras la opción seleccionada no sea 0

    return 0; // Devolver 0 para indicar una ejecución exitosa del programa
}
