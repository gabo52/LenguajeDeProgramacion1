/* 
 * File:   FunNumeros.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de octubre de 2022, 11:22 PM
 */

#ifndef FUNNUMEROS_H
#define FUNNUMEROS_H
#include <fstream>
using namespace std;
void *leenumero(ifstream &arch);
int cmpnumero(void *dt1,void *dt2);
void imprimenumero(void *dt,ofstream &arch,void *&nl);

#endif /* FUNNUMEROS_H */

