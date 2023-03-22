/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente.h
 * Author: alulab14
 *
 * Created on 7 de noviembre de 2022, 10:36 AM
 */

#ifndef PACIENTE_H
#define PACIENTE_H

class Paciente {
public:
    Paciente();
    virtual ~Paciente();
    void SetCodMed(char* codMed);
    void GetCodMed(char *cad) const;
    void SetNombre(char* nombre);
    void GetNombre(char *cad) const;
    void SetDni(int dni);
    int GetDni() const;
private:
    int dni;
    char *nombre;
    char *codMed;
};

#endif /* PACIENTE_H */

