/* 
 * File:   FunPedidos.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de octubre de 2022, 11:22 PM
 */

#ifndef FUNPEDIDOS_H
#define FUNPEDIDOS_H
#include <fstream>
using namespace std;

void *leepedido(ifstream &arch);
int cmppedido(void *dt1,void *dt2);
void imprimepedido(void *dt,ofstream &arch,void *&d2);

#endif /* FUNPEDIDOS_H */

