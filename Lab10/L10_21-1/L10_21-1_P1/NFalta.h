/* 
 * File:   NFalta.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:39 PM
 */

#ifndef NFALTA_H
#define NFALTA_H

#include "Infraccion.h"
#include "LFalta.h"
#include "Falta.h"
class NFalta {
public:
    NFalta();
    friend class LFalta;
private:
    NFalta *sig;
    Infraccion *pfalta;
    Falta dfalta;
};

#endif /* NFALTA_H */

