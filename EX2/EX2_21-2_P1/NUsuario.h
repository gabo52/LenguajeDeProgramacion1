/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NUsuario.h
 * Author: Gabo
 *
 * Created on 26 de noviembre de 2022, 08:37 PM
 */

#ifndef NUSUARIO_H
#define NUSUARIO_H

#include "Usuario.h"
#include "Administrativo.h"
#include "Estudiante.h"
#include "Docentes.h"

class NUsuario {
public:
    NUsuario();
    virtual ~NUsuario();
    void leer(ifstream &arch);
    int carne();
    void imprime(ofstream &arch);
private:
    Usuario *pusuario;
    
};

#endif /* NUSUARIO_H */

