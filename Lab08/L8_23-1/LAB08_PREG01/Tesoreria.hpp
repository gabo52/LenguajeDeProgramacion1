#ifndef LAB08_PREG01_TESORERIA_HPP
#define LAB08_PREG01_TESORERIA_HPP

#include "Utils.hpp"
#include "Presencial.hpp"
#include "Semipresencial.hpp"
#include "Virtual.hpp"
#include "Utils.hpp"
#include "Escala.hpp"

class Tesoreria {
public:
    Tesoreria();
    virtual ~Tesoreria();
    /////////////
    void cargaescalas(void);
    void leeEscala(std::ifstream &file, Escala &aux_escala);
    /////////////
    void cargaalumnos(void);
    void leerAlumnoPresencial(std::ifstream &file, Presencial & presencial);
    void leerAlumnoVirtual(std::ifstream &file, Virtual & avirtual);
    void leerAlumnoSemiPresencial(std::ifstream &file, Semipresencial & semi);
    /////////////
    void actualiza(int);
    /////////////
    void imprime(void);
    void imprimirCabecera(std::ofstream &file);

private:
    class Presencial lpresencial[100]{};
    class Semipresencial lsemipresencial[100]{};
    class Virtual lvirtual[100]{};
    class Escala lescala[10]{};
};


#endif //LAB08_PREG01_TESORERIA_HPP
