
/* 
 * File:   Usuario.h
 * Author: USER
 *
 * Created on 7 de junio de 2023, 10:17 AM
 */

#ifndef USUARIO_H
#define USUARIO_H
#include "LibroPrestado.h"

class Usuario {
public:
    Usuario();
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    void SetCondicion(int condicion);
    int GetCondicion() const;
    void SetLibPrest(LibroPrestado *libPrest);
    LibroPrestado* GetLibPrest() const;
    void SetNombre(char* nombre);
    char* GetNombre() const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCarne(int carne);
    int GetCarne() const;
    void copia(const Usuario &c);
    void operator += (const LibroPrestado &c);
    void operator * (int fecha);
private:
    int carne;
    char tipo;
    char *nombre; 
    class LibroPrestado libPrest[20];
    int condicion; 
};

#endif /* USUARIO_H */

