/* 
 * File:   FuncionesAuxiliares.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 10:12 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
#include "Usuario.h"
#include "Libro.h"
#include "LibroPrestado.h"
#include "FuncionesLecturaEscritura.h"
using namespace std;

void imprimirUsuarios(Usuario *usuarios);
void imprimirLibros(Libro *libros);
void cargarLibrosPrestados(Usuario *usuarios,Libro *libros);
void leerLibros(Libro *libros);
void leerUsuarios(Usuario *usuarios);


#endif /* FUNCIONESAUXILIARES_H */

