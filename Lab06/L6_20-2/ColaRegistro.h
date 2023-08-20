
/* 
 * File:   ColaRegistro.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 25 de mayo de 2023, 08:58 PM
 */

#ifndef COLAREGISTRO_H
#define COLAREGISTRO_H
using namespace std;

void *leeRegistro(ifstream &arch);
int hallarprioridadreg(void *dato);
void imprimeReg(void *dt,ofstream &arch); 

#endif /* COLAREGISTRO_H */

