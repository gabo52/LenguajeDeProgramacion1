

/* 
 * File:   Libro.h
 * Author: USER
 *
 * Created on 21 de junio de 2023, 06:42 PM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std; 

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetAutor(char *cad);
    void GetAutor(char *cad) const;
    void SetTitulo(char *cad);
    void GetTitulo(char *cad) const;
    void SetCodigo(char *cad);
    void GetCodigo(char *cad) const;
    virtual void cargadatos(char *codlib, char *tit, char *aut, int cant, double prec, int zone) = 0;
    virtual void actualiza(int, int, double) = 0; 
    virtual void imprimir(ofstream &arch);
private:
    char *codigo;
    char *titulo; 
    char *autor;
    int cantidad;
    int anho;
    double precio; 
};

#endif /* LIBRO_H */

