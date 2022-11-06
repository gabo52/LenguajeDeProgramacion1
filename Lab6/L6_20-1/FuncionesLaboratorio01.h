/* 
 * File:   FuncionesLaboratorio01.h
 * Author: Gabo
 * Codigo: 20203371
 * Created on 20 de octubre de 2022, 04:38 PM
 */

#ifndef FUNCIONESLABORATORIO01_H
#define FUNCIONESLABORATORIO01_H
char *leerCadena(ifstream &arch,char c);
void *leenumero(ifstream &arch);
void imprimenumero(ofstream &arch,void *dat);
int hallaHoras(int &hor,int &seg,int &min,int tiempo);

#endif /* FUNCIONESLABORATORIO01_H */

