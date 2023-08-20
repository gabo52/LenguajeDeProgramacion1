/* 
 * File:   Conductor.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 06:33 PM
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H

class Conductor {
public:
    Conductor();
    virtual ~Conductor();
    void SetNombre(char* cad);
    void GetNombre(char *cad) const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    void operator = (const Conductor &c);
private:
    int licencia;
    char *nombre;
};

#endif /* CONDUCTOR_H */

