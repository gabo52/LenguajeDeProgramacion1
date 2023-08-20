/* 
 * File:   Curso.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 31 de octubre de 2022, 10:43 AM
 */

#ifndef CURSO_H
#define CURSO_H

class Curso {
public:
    Curso();
    virtual ~Curso();
    void SetCredito(double credito);
    double GetCredito() const;
    void SetNota(int nota);
    int GetNota() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCcurso(char* ccurso);
    char* GetCcurso() const;
    void copia(const Curso &c);
    void asignar(const Curso &c);
    void operator = (const Curso &c);
    int compare(const Curso &c);
    int operator == (const Curso &c);
    void operator - (const Curso &c);
private:
    char *ccurso;
    int ciclo;
    int nota;
    double credito;
};

#endif /* CURSO_H */

