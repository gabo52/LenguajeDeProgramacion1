/* 
 * File:   Acurso.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 31 de octubre de 2022, 10:43 AM
 */

#ifndef ACURSO_H
#define ACURSO_H
#include "Curso.h"
#include <fstream>
using namespace std;
class Acurso {
public:
    Acurso();
    virtual ~Acurso();
    void SetOperacion(char operacion);
    char GetOperacion() const;
    void SetClcurso(Curso &clcurso);
    Curso GetClcurso() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void copia(const Acurso &c);
private:
    int codigo;
    class Curso clcurso;
    char operacion;
};

#endif /* ACURSO_H */

