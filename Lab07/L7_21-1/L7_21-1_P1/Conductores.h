/* 
 * File:   Conductores.h
 * Author: Gabriel Omar Duran Ruiz
 * Codigo: 20203371
 * Created on 1 de noviembre de 2022, 10:22 PM
 */

#ifndef CONDUCTORES_H
#define CONDUCTORES_H
#include "FaltaCond.h"
#include "Infraccion.h"
#include "Falta.h"
class Conductores {
public:
    Conductores();
    virtual ~Conductores();
    void SetMontoTotal(double montoTotal);
    double GetMontoTotal() const;
    void SetNumFaltas(int numFaltas);
    int GetNumFaltas() const;
    void SetLfaltas(FaltaCond* lfaltas,int n);
    FaltaCond* GetLfaltas(int n) const;
    void SetNombre(char* nombre);
    char* GetNombre() const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    void copia(const Conductores &c);
    void operator + (const Falta &f);
    void operator + (const Infraccion &f);
    double operator ++ ();
    void operator * (int fecha);
private:
    int licencia;
    char *nombre;
    FaltaCond lfaltas[100];
    int numFaltas;
    double montoTotal;
};

#endif /* CONDUCTORES_H */

