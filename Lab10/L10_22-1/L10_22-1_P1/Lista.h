/* 
 * File:   Lista.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de noviembre de 2022, 05:03 PM
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
class Lista {
public:
    Lista();
    virtual ~Lista();
    void insertar(Pedido *ped);
    void imprimir(ofstream &arch);
    void actualizaLista(int cod,int fec);
private:
    void imprimeLista(Nodo *lini,ofstream &arch);
    Nodo *lini;
    Nodo *lfin;
};

#endif /* LISTA_H */

