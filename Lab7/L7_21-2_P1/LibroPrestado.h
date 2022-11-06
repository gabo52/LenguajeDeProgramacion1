/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LibroPrestado.h
 * Author: Gabo
 *
 * Created on 2 de noviembre de 2022, 11:41 PM
 */

#ifndef LIBROPRESTADO_H
#define LIBROPRESTADO_H

class LibroPrestado {
public:
    LibroPrestado();
    virtual ~LibroPrestado();
    void SetDeuda(int deuda);
    int GetDeuda() const;
    void SetFechaDeRetiro(int fechaDeRetiro);
    int GetFechaDeRetiro() const;
    void SetCodigoLib(const char* codigoLib);
    void GetCodigoLib(char *) const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCarne(int carne);
    int GetCarne() const;
    void copia(const LibroPrestado &c);
private:
    int carne;
    char tipo;
    char *codigoLib;
    int fechaDeRetiro;
    int deuda;
};

#endif /* LIBROPRESTADO_H */

