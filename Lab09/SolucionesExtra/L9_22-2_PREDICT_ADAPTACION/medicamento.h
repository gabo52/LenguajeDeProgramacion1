/* 
 * File:   medicamento.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 10:05 PM
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
class medicamento {
public:
    medicamento();
    virtual ~medicamento();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void GetNombreMedicamento(char* cad)const;
    void SetNombreMedicamento(char* cad);
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void asignar(int medicamento,char *nombMedicamento,int cant,double precio,
                int fecha,int codmed,char *esp,int dni,char *nombPac)=0;
    virtual void imprime(ofstream &arch)=0;
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int fecha;
};

#endif /* MEDICAMENTO_H */

