/* 
 * File:   Falta.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 06:43 PM
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

