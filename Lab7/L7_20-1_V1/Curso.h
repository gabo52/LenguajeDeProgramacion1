/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.h
 * Author: Gabo
 *
 * Created on 30 de octubre de 2022, 10:25 PM
 */

#ifndef CURSO_H
#define CURSO_H

class Curso {
private:
    char *ccurso;
    int ciclo;
    int nota;
    int credito;
public:
    Curso();
    void inicializar();
    void copia(const Curso &c);
    virtual ~Curso();
    void asignar(const Curso &c);
    void operator = (const Curso &c);
    int compare(const Curso &c);
    int operator == (const Curso &c);
    void setCredito(int credito);
    int getCredito() const;
    void setNota(int nota);
    int getNota() const;
    void setCiclo(int ciclo);
    int getCiclo() const;
    void setCcurso(char* ccurso);
    char* getCcurso() const;
};

#endif /* CURSO_H */

