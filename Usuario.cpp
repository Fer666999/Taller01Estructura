#include "Usuario.h"
#include <iostream>

Usuario::Usuario(std::string nombre, std::string id) : nombre(nombre), id(id), cantidadPrestados(0) {
    for (int i = 0; i < 5; i++) {
        materialesPrestados[i] = nullptr;
    }
}

void Usuario::prestarMaterial(MaterialBibliografico* material) {
    if (cantidadPrestados < 5 && !material->estaPrestado()) {
        materialesPrestados[cantidadPrestados] = material;
        material->setPrestado(true);
        cantidadPrestados++;
        std::cout << "Material prestado con éxito." << std::endl;
    } else if (cantidadPrestados >= 5) {
        std::cout << "No puedes prestar más de 5 materiales." << std::endl;
    } else {
        std::cout << "El material ya está prestado." << std::endl;
    }
}

void Usuario::devolverMaterial(MaterialBibliografico* material) {
    for (int i = 0; i < 5; i++) {
        if (materialesPrestados[i] == material) {
            materialesPrestados[i] = nullptr;
            material->setPrestado(false);
            cantidadPrestados--;
            std::cout << "Material devuelto con éxito." << std::endl;
            return;
        }
    }
    std::cout << "No se encontró el material prestado." << std::endl;
}

void Usuario::mostrarMaterialesPrestados() const {
    std::cout << "Materiales prestados por " << nombre << ":\n";
    for (int i = 0; i < 5; i++) {
        if (materialesPrestados[i] != nullptr) {
            materialesPrestados[i]->mostrarInformacion();
        }
    }
}
