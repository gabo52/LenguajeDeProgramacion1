/* 
 * File:   Cliente.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 10:43 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include "Pedido.h"
#include <fstream>
using namespace std;

class Cliente {
public:
    Cliente();
    virtual ~Cliente();
    void SetTotal(double total);
    double GetTotal() const;
    void SetNumped(int numped);
    int GetNumped() const;
    void SetNombre(const char* cad);
    void GetNombre(char *cad) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void operator = (const Cliente &c);
    void imprimePedidos(ofstream &arch);
    void operator =(const Pedido& c);
    void eliminar();
    void operator -=(const Pedido& c);
    void operator / (double desc);
private:
    int dni;
    char categoria;
    char *nombre;
    Pedido lped[100];
    int numped;
    double total;
};

#endif /* CLIENTE_H */

