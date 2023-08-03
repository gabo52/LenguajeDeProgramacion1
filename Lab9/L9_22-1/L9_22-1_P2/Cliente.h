/* 
 * File:   Cliente.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 09:44 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Pedido.h"
using namespace std;
class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetTotalped(double totalped);
    double GetTotalped() const;
    void SetCantped(int cantped);
    int GetCantped() const;
    void SetNombre(const char* nombre);
    void GetNombre(char* cad) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    virtual void lee(ifstream &arch)=0;
    virtual void imprime(ofstream &arch)=0;
    virtual void actualiza(double monto,int cantPed)=0;
private:
    int dni;
    char categoria;
    char *nombre;
    int cantped;
    double totalped;
};
void imprimeLinea(ofstream &arch,int cant,char c);
#endif /* CLIENTE_H */

