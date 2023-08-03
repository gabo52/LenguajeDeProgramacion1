/* 
 * File:   Pedido.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 09:49 AM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;
class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void lee(ifstream &archPed);
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
};

#endif /* PEDIDO_H */

