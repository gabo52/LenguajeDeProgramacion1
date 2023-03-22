/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medico.h
 * Author: Gabo
 *
 * Created on 17 de noviembre de 2022, 10:01 PM
 */

#ifndef MEDICO_H
#define MEDICO_H
#include <fstream>
using namespace std;
class medico {
public:
    medico();
    virtual ~medico();
    void SetEspecialidad(char* especialidad);
    void GetEspecialidad(char* cad) const;
    void SetNombre(char* nombre);
    void GetNombre(char* cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leer(ifstream &arch);
private:
    int codigo;
    char *nombre;
    char *especialidad;
};

#endif /* MEDICO_H */

