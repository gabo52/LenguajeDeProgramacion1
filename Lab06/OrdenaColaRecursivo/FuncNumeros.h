/* 
 * File:   FuncNumeros.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de octubre de 2022, 05:12 PM
 */

#ifndef FUNCNUMEROS_H
#define FUNCNUMEROS_H
#include <fstream>
using namespace std;

void *leenum(ifstream &arch);
int cmpnum(void *dt1,void *dt2);
void imprimenum(ofstream &arch,void *dato,void *&condicion);


#endif /* FUNCNUMEROS_H */

