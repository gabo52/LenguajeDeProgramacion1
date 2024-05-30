#ifndef LAB08_PREG01_ESCALA_HPP
#define LAB08_PREG01_ESCALA_HPP

#include "Utils.hpp"

class Escala {
private:
    int codigo;
    double precio;
public:
    Escala();
    virtual ~Escala();
    int getCodigo() const;

    void setCodigo(int codigo);

    double getPrecio() const;

    void setPrecio(double precio);
};


#endif //LAB08_PREG01_ESCALA_HPP
