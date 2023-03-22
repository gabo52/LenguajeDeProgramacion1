/* 
 * File:   ColaBanco-Clientes.h
 * Author: Gabo
 * Codigo: 20203371
 * Created on 20 de octubre de 2022, 06:30 PM
 */

#ifndef COLABANCO_CLIENTES_H
#define COLABANCO_CLIENTES_H
void AbrirArchivo(ifstream &arch,const char *nomb);
void AbrirArchivo(ofstream &arch,const char *nomb);
char *leerCadena(ifstream &arch,char c);
void *leenumero(ifstream &arch);
void imprimenumero(ofstream &arch,void *dat);
int hallaHoras(int &hor,int &seg,int &min,int tiempo);
void imprimirHora(ofstream &arch,int horaLleg);
int obtieneTiempo(void *dato);
#endif /* COLABANCO_CLIENTES_H */

