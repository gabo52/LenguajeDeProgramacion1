

/* 
 * File:   Libro.h
 * Author: USER
 *
 * Created on 7 de junio de 2023, 10:21 AM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include "LibroPrestado.h"

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
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
    void SetAutor(char* cad);
    char* GetAutor() const;
    void SetTitulo(char* cad);
    char* GetTitulo() const;
    void SetCodigo(char* cad);
    char* GetCodigo() const;
    void copia(const Libro &c);
    void operator += (const LibroPrestado &c);
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

