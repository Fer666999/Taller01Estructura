#include <iostream>
#include <string>
#include <vector>
#include "../include/Libro.h"
#include "../include/Revista.h"
#include "../include/Usuario.h"

const int MAX_MATERIALES = 100;

int main() {
    // Biblioteca y usuarios
    MaterialBibliografico* biblioteca[MAX_MATERIALES];
    int cantidadMateriales = 0;

    std::vector<Usuario> listaUsuarios;
    // Usuario de ejemplo
    listaUsuarios.push_back(Usuario("Fernando Aranda", "001")); 
    // Libros de ejemplo
    if (cantidadMateriales < MAX_MATERIALES) {
        biblioteca[cantidadMateriales++] = new Libro("Cien años de soledad", "978-3-16-148410-0", "Gabriel García Márquez", "1967", "La historia de la familia Buendía.");
        biblioteca[cantidadMateriales++] = new Libro("Don Quijote de la Mancha", "978-0-7432-7356-5", "Miguel de Cervantes", "1605", "Las aventuras de un caballero loco.");
    }

    // Revistas de ejemplo
    if (cantidadMateriales < MAX_MATERIALES) {
        biblioteca[cantidadMateriales++] = new Revista("National Geographic", "978-0-1234-5678-9", "John Doe", 152, "Enero");
        biblioteca[cantidadMateriales++] = new Revista("Scientific American", "978-1-2345-6789-0", "Jane Roe", 248, "Febrero");
    }

    Usuario* usuarioActivo = nullptr;

    // Selección inicial del usuario activo
    std::string nombreUsuario, idUsuario;
    std::cout << "----- Iniciar Sesion -----\n";
    std::cout << "Ingrese su nombre: ";
    std::cin.ignore(); // Ignorar el carácter de nueva línea residual
    std::getline(std::cin, nombreUsuario); // Leer nombre completo del usuario
    std::cout << "Ingrese su ID: ";
    std::getline(std::cin, idUsuario); // Leer ID completo del usuario

    // Verificar si el usuario existe, si no, se agrega a la lista
    bool usuarioEncontrado = false;
    for (auto& usuario : listaUsuarios) {
        if (usuario.getNombre() == nombreUsuario && usuario.getID() == idUsuario) {
            usuarioActivo = &usuario;
            usuarioEncontrado = true;
            break;
        }
    }

    if (!usuarioEncontrado) {
        listaUsuarios.push_back(Usuario(nombreUsuario, idUsuario));
        usuarioActivo = &listaUsuarios.back();
        std::cout << "Nuevo usuario agregado.\n";
    }

    int opcion;
    do {
        std::cout << "\n----- Menu de Biblioteca Digital -----\n";
        std::cout << "Usuario activo: " << usuarioActivo->getNombre() << " (" << usuarioActivo->getID() << ")\n";
        std::cout << "1. Agregar Libro\n";
        std::cout << "2. Agregar Revista\n";
        std::cout << "3. Prestar Material\n";
        std::cout << "4. Devolver Material\n";
        std::cout << "5. Mostrar Materiales Prestados\n";
        std::cout << "6. Cambiar Usuario\n";
        std::cout << "7. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombre, isbn, autor, fecha, resumen;
                std::cout << "Ingrese el nombre del libro: ";
                std::cin >> nombre;
                std::cout << "Ingrese el ISBN: ";
                std::cin >> isbn;
                std::cout << "Ingrese el autor: ";
                std::cin >> autor;
                std::cout << "Ingrese la fecha de publicacion: ";
                std::cin >> fecha;
                std::cout << "Ingrese el resumen: ";
                std::cin >> resumen;

                if (cantidadMateriales < MAX_MATERIALES) {
                    biblioteca[cantidadMateriales] = new Libro(nombre, isbn, autor, fecha, resumen);
                    cantidadMateriales++;
                    std::cout << "Libro agregado con exito.\n";
                } else {
                    std::cout << "La biblioteca esta llena.\n";
                }
                break;
            }
            case 2: {
                std::string nombre, isbn, autor, mes;
                int edicion;
                std::cout << "Ingrese el nombre de la revista: ";
                std::cin >> nombre;
                std::cout << "Ingrese el ISBN: ";
                std::cin >> isbn;
                std::cout << "Ingrese el autor: ";
                std::cin >> autor;
                std::cout << "Ingrese el mes de publicacion: ";
                std::cin >> mes;
                std::cout << "Ingrese el numero de edicion: ";
                std::cin >> edicion;

                if (cantidadMateriales < MAX_MATERIALES) {
                    biblioteca[cantidadMateriales] = new Revista(nombre, isbn, autor, edicion, mes);
                    cantidadMateriales++;
                    std::cout << "Revista agregada con exito.\n";
                } else {
                    std::cout << "La biblioteca esta llena.\n";
                }
                break;
            }
            case 3: {
                std::string nombreMaterial;
                std::cout << "Ingrese el nombre del material a prestar: ";
                std::cin >> nombreMaterial;

                bool encontrado = false;
                for (int i = 0; i < cantidadMateriales; i++) {
                    if (biblioteca[i]->getNombre() == nombreMaterial && !biblioteca[i]->estaPrestado()) {
                        usuarioActivo->prestarMaterial(biblioteca[i]);
                        encontrado = true;
                        std::cout << "Material prestado con exito.\n";
                        break;
                    }
                }
                if (!encontrado) {
                    std::cout << "Material no encontrado o ya prestado.\n";
                }
                break;
            }
            case 4: {
                std::string nombreMaterial;
                std::cout << "Ingrese el nombre del material a devolver: ";
                std::cin >> nombreMaterial;

                bool encontrado = false;
                for (int i = 0; i < cantidadMateriales; i++) {
                    if (biblioteca[i]->getNombre() == nombreMaterial && biblioteca[i]->estaPrestado()) {
                        usuarioActivo->devolverMaterial(biblioteca[i]);
                        encontrado = true;
                        std::cout << "Material devuelto con exito.\n";
                        break;
                    }
                }
                if (!encontrado) {
                    std::cout << "Material no encontrado o no prestado.\n";
                }
                break;
            }
            case 5: {
                usuarioActivo->mostrarMaterialesPrestados();
                break;
            }
            case 6: {
                std::cout << "----- Cambiar Usuario -----\n";
                std::cout << "Ingrese su nombre: ";
                std::cin.ignore(); // Ignorar el carácter de nueva línea residual
                std::getline(std::cin, nombreUsuario); // Leer nombre completo del usuario
                std::cout << "Ingrese su ID: ";
                std::getline(std::cin, idUsuario); // Leer ID completo del usuario

                usuarioEncontrado = false;
                for (auto& usuario : listaUsuarios) {
                    if (usuario.getNombre() == nombreUsuario && usuario.getID() == idUsuario) {
                        usuarioActivo = &usuario;
                        usuarioEncontrado = true;
                        std::cout << "Usuario cambiado con exito.\n";
                        break;
                    }
                }

                if (!usuarioEncontrado) {
                    listaUsuarios.push_back(Usuario(nombreUsuario, idUsuario));
                    usuarioActivo = &listaUsuarios.back();
                    std::cout << "Nuevo usuario agregado.\n";
                }
                break;
            }
            case 7:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
        }
    } while (opcion != 7);

    // Liberar memoria al final
    for (int i = 0; i < cantidadMateriales; i++) {
        delete biblioteca[i];
    }

    return 0;
}
