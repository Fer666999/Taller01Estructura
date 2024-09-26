#include "Revista.h"
#include <iostream>

Revista::Revista(std::string nombre, std::string isbn, std::string autor, int numeroEdicion, std::string mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {}

void Revista::mostrarInformacion() const {
    std::cout << "Revista: " << nombre << "\nISBN: " << isbn << "\nAutor: " << autor
              << "\nNúmero de Edición: " << numeroEdicion << "\nMes de Publicación: " << mesPublicacion
              << "\nPrestado: " << (prestado ? "Sí" : "No") << std::endl;
}
