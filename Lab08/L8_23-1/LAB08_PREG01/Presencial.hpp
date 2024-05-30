#ifndef LAB08_PREG01_PRESENCIAL_HPP
#define LAB08_PREG01_PRESENCIAL_HPP

#include "Utils.hpp"
#include "Alumno.hpp"

class Presencial:public Alumno{
private:
    double recargar;
    double total;
public:
    Presencial();
    virtual ~Presencial();
    double getRecargar() const;

    void setRecargar(double recargar);

    double getTotal() const;

    void setTotal(double total);
};


#endif //LAB08_PREG01_PRESENCIAL_HPP
