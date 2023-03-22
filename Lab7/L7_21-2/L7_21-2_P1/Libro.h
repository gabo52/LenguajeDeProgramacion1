/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: Gabo
 *
 * Created on 2 de noviembre de 2022, 11:42 PM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include "LibroPrestado.h"
class Libro {
public:
    Libro();
    virtual ~Libro();
    void SetCantAdm(int cantAdm);
    int GetCantAdm() const;
    void SetCantDoc(int cantDoc);
    int GetCantDoc() const;
    void SetCantEst(int cantEst);
    int GetCantEst() const;
    void SetPrestados(int prestados);
    int GetPrestados() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetAutor(const char* autor);
    void GetAutor(char *) const;
    void SetTitulo(const char* titulo);
    void GetTitulo(char *) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
    void copia(const Libro &c);
    void operator += (const LibroPrestado &prest);
private:
    char *codigo;
    char *titulo;
    char *autor;
    int stock;
    double precio;
    int prestados;
    int cantEst;
    int cantDoc;
    int cantAdm;
};

#endif /* LIBRO_H */

