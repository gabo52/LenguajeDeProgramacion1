
/* 
 * File:   LibroPrestado.h
 * Author: USER
 *
 * Created on 7 de junio de 2023, 10:20 AM
 */

#ifndef LIBROPRESTADO_H
#define LIBROPRESTADO_H

class LibroPrestado {
public:
    LibroPrestado();
    LibroPrestado(const LibroPrestado& orig);
    virtual ~LibroPrestado();
    void SetDeuda(int deuda);
    int GetDeuda() const;
    void SetFechaDeRetiro(int fechaDeRetiro);
    int GetFechaDeRetiro() const;
    void SetCodigoLib(char* cad);
    char* GetCodigoLib() const;
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

