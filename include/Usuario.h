#ifndef USUARIO_H
#define USUARIO_H

#include "MaterialBibliografico.h"
#include <string>
#include <iostream>

class Usuario {
private:
    std::string nombre;
    std::string id;
    MaterialBibliografico* materialesPrestados[5];
    int cantidadPrestados;

public:
    Usuario(std::string nombre, std::string id);
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(MaterialBibliografico* material);
    void mostrarMaterialesPrestados() const;
    // Métodos Getters
    std::string getNombre() const;
    std::string getID() const;
};

#endif
