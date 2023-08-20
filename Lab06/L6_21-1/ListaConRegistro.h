/* 
 * File:   ListaConRegistro.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 25 de octubre de 2022, 06:17 PM
 */

#ifndef LISTACONREGISTRO_H
#define LISTACONREGISTRO_H
#include <fstream>
using namespace std;
void *leeregistro(ifstream &arch);
int cmpregistro(void *dt1,void *dt2);
void imprimeregistro(void *dt,ofstream &arch,void *&cabecera);


#endif /* LISTACONREGISTRO_H */

