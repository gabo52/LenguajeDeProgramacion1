/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClienteC.h
 * Author: Gabo
 *
 * Created on 16 de noviembre de 2022, 09:48 AM
 */

#ifndef CLIENTEC_H
#define CLIENTEC_H

#include "Cliente.h"


class ClienteC : public Cliente{
public:
    //ClienteC(const ClienteC& orig);
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    double flete;
};

#endif /* CLIENTEC_H */

