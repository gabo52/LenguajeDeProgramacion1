/* 
 * File:   ALibro.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 09:41 PM
 */

#ifndef ALIBRO_H
#define ALIBRO_H
#include "Libro.h"
#include "NLibro.h"
#include <fstream>
using namespace std;
class ALibro {
public:
    ALibro();
    virtual ~ALibro();
    void insertar(Libro &lib);
    void imprimir(ofstream &arch);
    void actualiza(char *cod);
private:
    void imprimeArbol(class NLibro *NLibro,ofstream &arch);
    void insertarArbol(class NLibro *&arbol,Libro &lib);
    void actualizaArbol(NLibro *arbol,char *cod);
    class NLibro *Raiz;
};

#endif /* ALIBRO_H */

