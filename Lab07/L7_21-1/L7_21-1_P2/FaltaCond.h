/* 
 * File:   FaltaCond.h
 * Author: Gabriel Omar Duran Ruiz
 * Codigo: 20203371
 * Created on 1 de noviembre de 2022, 10:23 PM
 */

#ifndef FALTACOND_H
#define FALTACOND_H

class FaltaCond {
public:
    FaltaCond();
    virtual ~FaltaCond();
    void SetGravedad(char* gravedad);
    char* GetGravedad() const;
    void SetMulta(double multa);
    double GetMulta() const;
    void SetCodInf(int codInf);
    int GetCodInf() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPlaca(char* placa);
    char* GetPlaca() const;
    void copia(const FaltaCond &c);
private:
    char *placa;
    int fecha;
    int codInf;
    double multa;
    char *gravedad;
};

#endif /* FALTACOND_H */

