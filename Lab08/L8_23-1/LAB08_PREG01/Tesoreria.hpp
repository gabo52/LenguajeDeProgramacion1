#ifndef LAB08_PREG01_TESORERIA_HPP
#define LAB08_PREG01_TESORERIA_HPP

#include "Utils.hpp"
#include "Presencial.hpp"
#include "Semipresencial.hpp"
#include "Virtual.hpp"
#include "Utils.hpp"

class Tesoreria {
public:
    Tesoreria();

    virtual ~Tesoreria();

private:
    class Presencial lpresencial[100];
    class Semipresencial lsemipresencial[100];
    class Virtual lvirtual[100];
    class Escala lescala[100];
};


#endif //LAB08_PREG01_TESORERIA_HPP
