/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.h
 * Author: Gabo
 *
 * Created on 1 de noviembre de 2022, 10:25 PM
 */

#ifndef INFRACCION_H
#define INFRACCION_H

class Infraccion {
public:
    Infraccion();
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(char* gravedad);
    char* GetGravedad() const;
    void SetDescripcion(char* descripcion);
    char* GetDescripcion() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void copia(const Infraccion &c);
private:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;
};

#endif /* INFRACCION_H */

