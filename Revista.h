#ifndef REVISTA_H
#define REVISTA_H

#include "MaterialBibliografico.h"
#include <string>

class Revista : public MaterialBibliografico {
private:
    int numeroEdicion;
    std::string mesPublicacion;

public:
    Revista(std::string nombre, std::string isbn, std::string autor, int numeroEdicion, std::string mesPublicacion);
    void mostrarInformacion() const override;
};

#endif
