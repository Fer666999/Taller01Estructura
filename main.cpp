#include <iostream>
#include <string>
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"

const int MAX_MATERIALES = 100;

int main() {
    MaterialBibliografico* biblioteca[MAX_MATERIALES];
    int cantidadMateriales = 0;

    Usuario usuario1("Fernando Aranda", "001"); // Usuario de ejemplo

    int opcion;
    do {
        std::cout << "\n----- Menu de Biblioteca Digital -----\n";
        std::cout << "1. Agregar Libro\n";
        std::cout << "2. Agregar Revista\n";
        std::cout << "3. Prestar Material\n";
        std::cout << "4. Devolver Material\n";
        std::cout << "5. Mostrar Materiales Prestados\n";
        std::cout << "6. Salir\n";
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
                    std::cout << "La biblioteca está llena.\n";
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
                        usuario1.prestarMaterial(biblioteca[i]);
                        encontrado = true;
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
                        usuario1.devolverMaterial(biblioteca[i]);
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    std::cout << "Material no encontrado o no prestado.\n";
                }
                break;
            }
            case 5: {
                usuario1.mostrarMaterialesPrestados();
                break;
            }
            case 6:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
        }
    } while (opcion != 6);

    // Liberar memoria al final
    for (int i = 0; i < cantidadMateriales; i++) {
        delete biblioteca[i];
    }

    return 0;
}
