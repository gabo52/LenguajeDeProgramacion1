/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NArbol.cpp
 * Author: Gabo
 * 
 * Created on 27 de noviembre de 2022, 06:08 PM
 */

#include "NArbol.h"

NArbol::NArbol() {
    der=nullptr;
    izq=nullptr;
    med=nullptr;
}

NArbol::~NArbol() {
    //delete &med;
}

