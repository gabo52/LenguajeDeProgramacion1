/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medico.h
 * Author: Gabo
 *
 * Created on 3 de noviembre de 2022, 09:34 PM
 */

#ifndef MEDICO_H
#define MEDICO_H
#include <cstring>
#include <fstream>
using namespace std;
class Medico {
public:
    Medico();
    virtual ~Medico();
    void SetEspecialidad(const char* especialidad);
    void GetEspecialidad(char *cad) const;
    void SetTarifaxconsulta(double tarifaxconsulta);
    double GetTarifaxconsulta() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator = (const Medico &c);
private:
    int codigo;
    char *nombre;
    double tarifaxconsulta;
    char *especialidad;
};

#endif /* MEDICO_H */

