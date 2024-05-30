#ifndef LAB08_PREG01_ALUMNO_HPP
#define LAB08_PREG01_ALUMNO_HPP

#include "Utils.hpp"

class Alumno {
private:
    int escala;
    double total;
    int codigo;
    char *nombre;
public:
    Alumno();
    virtual ~Alumno();
    int getCodigo() const;

    void setCodigo(int codigo);

    void getNombre(char *nombre) const;

    void setNombre(const char *nombre);

    int getEscala() const;

    void setEscala(int escala);

    double getTotal() const;

    void setTotal(double total);

};


#endif //LAB08_PREG01_ALUMNO_HPP
