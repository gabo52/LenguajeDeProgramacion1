/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estructuras.h
 * Author: Gabo
 *
 * Created on 15 de septiembre de 2022, 09:30 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


typedef struct{
    int codigo;
    char descripcion[200];
    double precio;
}Medicinas;


typedef struct{
    char nombre[70];
    char codMed[10];
    int fecha;
    int cantMedicamentos;
    int DNI;
    Medicinas medicinas[30];
}Consulta;

typedef struct{
    char codigo[10];
    char nombre[100];
    Consulta citas[40];
    int cantCitas;
    char especialidad[50];
}Medico;


typedef struct{
    int DNI;
    char nombre[70];
}Paciente;




#endif /* ESTRUCTURAS_H */

