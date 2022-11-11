/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: Gabo
 *
 * Created on 9 de noviembre de 2022, 05:26 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
public:
    Cliente();
    virtual ~Cliente();
    void SetNombre(char* nombre);
    void GetNombre(char* cad) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void operator = (const Cliente &c);
private:
    int dni;
    char categoria;
    char *nombre;
};

#endif /* CLIENTE_H */

