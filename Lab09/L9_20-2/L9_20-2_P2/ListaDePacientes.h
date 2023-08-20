/* 
 * File:   ListaDePacientes.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 15 de noviembre de 2022, 12:52 PM
 */

#ifndef LISTADEPACIENTES_H
#define LISTADEPACIENTES_H

#include "Nodo.h"
#include "Ambulatorio.h"
#include "Emergencia.h"
#include "Urgencia.h"

class ListaDePacientes {
public:
    ListaDePacientes();
    virtual ~ListaDePacientes();
    void CreaLista(const char *nomb);
    void imprimeLista(const char *nomb);
    void insertar(Paciente *&pac);
private:
    class Nodo *lista;
};
void AbrirArchivo(const char *nomb, ifstream &arch);
void AbrirArchivo(const char *nomb, ofstream &arch);
void imprimeLinea(ofstream &arch,int cant,char c);
#endif /* LISTADEPACIENTES_H */

