/* 
 * File:   Registro.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:54 PM
 */

#ifndef REGISTRO_HPP
#define REGISTRO_HPP

#include "Utils.hpp"
#include "Nota.hpp"

class Registro {
public:
    Registro();
    Registro(const Registro& orig);
    virtual ~Registro();
    void carga(void);
    void procesa(void);
    void muestra(void);

private:
    std::vector<Nota> vregistro;
    static bool ordenarRegistro(class Nota &a, class Nota &b);

};

#endif /* REGISTRO_HPP */

