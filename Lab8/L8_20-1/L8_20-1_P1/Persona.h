/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: Gabo
 *
 * Created on 6 de noviembre de 2022, 09:45 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

class Persona {
public:
    Persona();
    virtual ~Persona();
    void SetDistrito(char* distrito);
    void GetDistrito(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetNombre(char* nombre);
    void GetNombre(char *cad) const;
    void operator = (const Persona &c);
private:
    char *nombre;
    int codigo;
    char *distrito;

};

#endif /* PERSONA_H */

