#ifndef LAB08_PREG01_VIRTUAL_HPP
#define LAB08_PREG01_VIRTUAL_HPP

#include "Alumno.hpp"
#include "Utils.hpp"

class Virtual: public Alumno {
public:
    Virtual();

    virtual ~Virtual();

    void getLicencia(char *licencia) const;

    void setLicencia(char *licencia);

    double getTotal() const;

    void setTotal(double total);

private:
    char *licencia;
    double total;
};


#endif //LAB08_PREG01_VIRTUAL_HPP
