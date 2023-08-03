
/* 
 * File:   Sobrecargas.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 7 de junio de 2023, 11:23 AM
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H
#include <fstream>
#include "Libro.h"
#include "Usuario.h"
#include "LibroPrestado.h"
using namespace std; 

ifstream & operator >> (ifstream &arch, Libro &c);
ifstream & operator >> (ifstream &arch, Usuario &c); 
ifstream & operator >> (ifstream &arch, LibroPrestado &f);
ofstream & operator << (ofstream &arch, LibroPrestado &f);
ofstream & operator << (ofstream &arch, Usuario &u);
ofstream & operator << (ofstream &arch, Libro &l); 

#endif /* SOBRECARGAS_H */

