#include "Libro.h"
#include <iostream>

Libro::Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPublicacion, std::string resumen): 
    MaterialBibliografico(nombre, isbn, autor), fechaPublicacion(fechaPublicacion), resumen(resumen) {}

void Libro::mostrarInformacion() const {
    std::cout << "Libro: " << nombre << "\nISBN: " << isbn << "\nAutor: " << autor
              << "\nFecha de Publicacion: " << fechaPublicacion << "\nResumen: " << resumen
              << "\nPrestado: " << (prestado ? "Sí" : "No") << std::endl;
}
