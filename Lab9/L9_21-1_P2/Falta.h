/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.h
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 06:26 PM
 */

#ifndef FALTA_H
#define FALTA_H

class Falta {
public:
    Falta();
    virtual ~Falta();
    void SetPlaca(char* placa);
    void GetPlaca(char* cad) const;
    void SetFecha(int fecha);
    int GetFecha() const;
private:
    int fecha;
    char *placa;
};

#endif /* FALTA_H */

