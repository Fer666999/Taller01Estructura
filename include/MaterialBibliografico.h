#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H

#include <string>

class MaterialBibliografico {
protected:
    std::string nombre;
    std::string isbn;
    std::string autor;
    bool prestado;

public:
    MaterialBibliografico(std::string nombre, std::string isbn, std::string autor, bool prestado = false);
    virtual ~MaterialBibliografico() = default;

    virtual void mostrarInformacion() const = 0;
    bool estaPrestado() const;
    void setPrestado(bool estado);
    std::string getNombre() const;
    std::string getAutor() const;
};

#endif
