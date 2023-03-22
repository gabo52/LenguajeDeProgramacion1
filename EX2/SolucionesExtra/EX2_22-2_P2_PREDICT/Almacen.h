/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 06:10 PM
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include "Cola.h"
#include "Arbol.h"
#include <fstream>
#include "marca.h"
#include "generico.h"
using namespace std;

class Almacen {
public:
    void carga();
    void actualiza();
    void imprime();
private:
    Arbol arbolito;
    Cola cola;
    
};

#endif /* ALMACEN_H */

