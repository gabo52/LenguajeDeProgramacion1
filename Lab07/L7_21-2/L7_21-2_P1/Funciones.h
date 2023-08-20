
/* 
 * File:   Funciones.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 8 de junio de 2023, 01:46 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Usuario.h"
#include "Libro.h"
#include "LibroPrestado.h"

void cargarUsuarios(Usuario *arr);
void cargarLibros(Libro *arr);
void cargarActualizarPrestamos(LibroPrestado *arr, Libro *lib, Usuario *usu); 
int buscarLibro(char *codigo, Libro *lib);
void imprimirUsuarios(Usuario *arr);
int buscarUsuario(int carne, Usuario *usu);
void imprimirLibros(Libro *arr);
void determinarDeudas(int fecha, Usuario *arr); 

#endif /* FUNCIONES_H */

