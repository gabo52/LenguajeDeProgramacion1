/* 
 * File:   NodoCola.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 08:39 PM
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "ColaSol.h"

class NodoCola {
public:
    NodoCola();
    void SetCarne(int carne);
    int GetCarne() const;
    void SetLibsol(char* libsol);
    void GetLibsol(char* cad) const;
    friend class ColaSol;
    virtual ~NodoCola();
private:
    char *libsol;
    int carne;
    NodoCola *sig;
};

#endif /* NODOCOLA_H */

