/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programa.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 03:14 PM
 */

#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <vector>
#include <iterator>
#include <fstream>
#include "Lista.h"
#include "NProductos.h"
using namespace std;

class Programa {
public:
    void carga();
    void actualiza();
    void muestra();
    void CargaProductos();
    void CargaLista();
    void ImprimeProductos();
    void ImprimeLista();
private:
    Lista lpedidos;
    vector<NProductos>vproductos;
};

#endif /* PROGRAMA_H */

