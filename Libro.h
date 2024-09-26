#ifndef LIBRO_H
#define LIBRO_H

#include "MaterialBibliografico.h"
#include <string>

class Libro : public MaterialBibliografico {
private:
    std::string fechaPublicacion;
    std::string resumen;

public:
    Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPublicacion, std::string resumen);
    void mostrarInformacion() const override;
};

#endif
