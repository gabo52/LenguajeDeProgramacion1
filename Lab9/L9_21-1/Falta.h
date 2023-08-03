

/* 
 * File:   Falta.h
 * Author: USER
 *
 * Created on 20 de junio de 2023, 03:31 PM
 */

#ifndef FALTA_H
#define FALTA_H

class Falta {
public:
    Falta();
    Falta(const Falta& orig);
    virtual ~Falta();
    void SetPlaca(char* placa);
    char* GetPlaca() const;
    void SetFecha(int fecha);
    int GetFecha() const;
private:
    int fecha;
    char *placa;
};

#endif /* FALTA_H */

