/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobreCargaFunc.h
 * Author: Gabo
 *
 * Created on 13 de septiembre de 2022, 10:15 PM
 */

#ifndef SOBRECARGAFUNC_H
#define SOBRECARGAFUNC_H

ostream & operator <<(ostream &, const struct Persona &);
istream & operator >>(istream &, struct Persona &);
double operator *= (struct Persona &, double);
bool operator !(const struct Persona &per);
#endif /* SOBRECARGAFUNC_H */

