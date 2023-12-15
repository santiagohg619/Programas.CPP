#include <iostream>
#include <vector>
#include <algorithm> // Para usar la función sort

using namespace std;

// Definir una estructura para los libros
struct Libro {
    string titulo;
    string autor;
    int anioPublicacion;
};

// Función para agregar un nuevo libro a la lista
void agregarLibro(vector<Libro>& listaLibros, const Libro& nuevoLibro) {
    listaLibros.push_back(nuevoLibro);
    cout << "Libro agregado: " << nuevoLibro.titulo << " de " << nuevoLibro.autor << " (" << nuevoLibro.anioPublicacion << ")" << endl;
}

// Función para buscar libros por autor
void buscarLibrosPorAutor(const vector<Libro>& listaLibros, const string& autor) {
    cout << "Libros de " << autor << ":" << endl;
    for (const Libro& libro : listaLibros) {
        if (libro.autor == autor) {
            cout << " - " << libro.titulo << " (" << libro.anioPublicacion << ")" << endl;
        }
    }
}

// Función para mostrar la lista de libros
void mostrarListaLibros(const vector<Libro>& listaLibros) {
    cout << "Lista de Libros:" << endl;
    for (const Libro& libro : listaLibros) {
        cout << " - " << libro.titulo << " de " << libro.autor << " (" << libro.anioPublicacion << ")" << endl;
    }
}

// Función para obtener detalles de un libro desde el usuario
Libro obtenerDetallesLibroDesdeUsuario() {
    Libro nuevoLibro;
    cout << "Ingrese el título del libro: ";
    getline(cin, nuevoLibro.titulo);

    cout << "Ingrese el nombre del autor: ";
    getline(cin, nuevoLibro.autor);

    cout << "Ingrese el año de publicación: ";
    cin >> nuevoLibro.anioPublicacion;

    return nuevoLibro;
}

int main() {
    vector<Libro> listaLibros;

    // Permitir al usuario ingresar detalles de libros
    char continuar;
    do {
        Libro nuevoLibro = obtenerDetallesLibroDesdeUsuario();
        agregarLibro(listaLibros, nuevoLibro);
        cout << "¿Desea ingresar otro libro? (S/N): ";
        cin >> continuar;
        // Limpiar el buffer del teclado
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (continuar == 'S' || continuar == 's');

    // Buscar libros por autor
    string autorBusqueda;
    cout << "Ingrese el nombre del autor para buscar libros: ";
    getline(cin, autorBusqueda);
    buscarLibrosPorAutor(listaLibros, autorBusqueda);
    // Mostrar la lista de libros
    mostrarListaLibros(listaLibros);

    return 0;
}
