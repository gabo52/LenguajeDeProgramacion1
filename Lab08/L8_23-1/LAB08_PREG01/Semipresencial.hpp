#ifndef LAB08_PREG01_SEMIPRESENCIAL_HPP
#define LAB08_PREG01_SEMIPRESENCIAL_HPP

#include "Alumno.hpp"
#include "Utils.hpp"

class Semipresencial:public Alumno {
private:
    double descuento;
    double total;
public:
    Semipresencial();

    double getDescuento() const;

    void setDescuento(double descuento);

    double getTotal1() const;

    void setTotal1(double total);
};


#endif //LAB08_PREG01_SEMIPRESENCIAL_HPP
