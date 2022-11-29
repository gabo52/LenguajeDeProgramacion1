/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: Gabo
 *
 * Created on 26 de noviembre de 2022, 08:41 PM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <list>
#include <iterator>
#include <vector>
#include "ColaSol.h"
#include "Libro.h"
#include "NUsuario.h"
using namespace std;
class Procesa {
public:
    void Carga();
    void Atiende();
    void Imprime();
    void CargaLibros(const char *nomb);
    void CargaUsuarios(const char *nomb);
    void LeeSolicitudes(const char *nomb);
    void actualiza(char *cad,int carne);
    void ImprimeLibros();
    void ImprimeCola();
    void imprimeUsuario(int carne,ofstream &arch);
private:
    list<class Libro>llibros;
    ColaSol cola;
    vector<class NUsuario>vusuarios;
};

#endif /* PROCESA_H */

