/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medico.h
 * Author: cueva
 *
 * Created on 11 de junio de 2023, 11:29 AM
 */

#include <fstream>

using namespace std;

#ifndef MEDICO_H
#define MEDICO_H

class medico {
public:
    medico();
    medico(const medico& orig);
    virtual ~medico();
    void SetEspecialidad(char*);
    void GetEspecialidad(char*) const;
    void SetNombre(char* );
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leemedico(ifstream &);
private:
    int codigo;
    char *nombre;
    char *especialidad;
};

#endif /* MEDICO_H */

