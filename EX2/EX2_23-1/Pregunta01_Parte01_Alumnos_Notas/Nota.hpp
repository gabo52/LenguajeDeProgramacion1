/* 
 * File:   Nota.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 7 de julio de 2024, 11:52 PM
 */

#ifndef NOTA_HPP
#define NOTA_HPP

#include "Utils.hpp"

class Nota {
public:
    Nota();
    Nota(const Nota& orig);
    virtual ~Nota();
    void SetVez(int vez);
    int GetVez() const;
    void SetCalificacion(int calificacion);
    int GetCalificacion() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetCodigo_curso(const char* codigo_curso);
    void GetCodigo_curso(char *codigo_curso) const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    // funciones
    void imprimeNota(std::ofstream &file);
    Nota & operator=(const Nota &nota);
private:
    int ciclo;
    char* codigo_curso;
    double creditos;
    int calificacion;
    int vez;
};

bool operator>>(std::ifstream &file, Nota &nota);


#endif /* NOTA_HPP */

