#include "../include/MaterialBibliografico.h"
#include <iostream>

MaterialBibliografico::MaterialBibliografico(std::string nombre, std::string isbn, std::string autor, bool prestado): 
    nombre(nombre), isbn(isbn), autor(autor), prestado(prestado) {}

bool MaterialBibliografico::estaPrestado() const {
    return prestado;
}

void MaterialBibliografico::setPrestado(bool estado) {
    prestado = estado;
}

std::string MaterialBibliografico::getNombre() const {
    return nombre;
}

std::string MaterialBibliografico::getAutor() const {
    return autor;
}
