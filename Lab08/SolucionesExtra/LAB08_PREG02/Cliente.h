/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Alumna: Sun Ji Sánchez
 * Código: 20180454
 * Created on 17 de junio de 2022, 08:04 AM
 */

#include <fstream>
using namespace std;
#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
private:
    int dni;
    char categoria;
    char *nombre;

public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetNombre(char*);
    void GetNombre(char *) const;
    void leeCliente(ifstream &);

};

#endif /* CLIENTE_H */

