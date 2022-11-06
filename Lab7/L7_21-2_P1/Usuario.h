/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.h
 * Author: Gabo
 *
 * Created on 2 de noviembre de 2022, 11:39 PM
 */

#ifndef USUARIO_H
#define USUARIO_H
#include "LibroPrestado.h"
#include <fstream>
using namespace std;
class Usuario {
public:
    Usuario();
    virtual ~Usuario();
    void SetCondicion(int condicion);
    int GetCondicion() const;
    void SetNumLibPrest(int numLibPrest);
    int GetNumLibPrest() const;
    void SetNombre(char* nombre);
    void GetNombre(char *cad) const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCarne(int carne);
    int GetCarne() const;
    void copia(const Usuario &c);
    void operator += (const LibroPrestado &prest);
    void operator * (int fecha);
    void imprimeLibros (ofstream &arch);
private:
    int carne;
    char tipo;
    char *nombre;
    LibroPrestado libPrest[100];
    int numLibPrest;
    int condicion;
};

#endif /* USUARIO_H */

