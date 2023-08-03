/* 
 * File:   ConferencePaper.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 11:10 PM
 */

#include <cstring>

#include "ConferencePaper.h"

ConferencePaper::ConferencePaper() {
    conference_name = nullptr;
    host_country = nullptr;
}


ConferencePaper::~ConferencePaper() {
    if(conference_name)delete conference_name;
    if(host_country)delete host_country;
}

void ConferencePaper::SetHost_country(char* cad) {
    if(host_country)delete host_country;
    host_country = new char [strlen(cad)+1];
    strcpy(host_country,cad);
}

void ConferencePaper::GetHost_country(char* cad) const {
    if(host_country)strcpy(cad,host_country);
    else cad[0]=0;
}

void ConferencePaper::SetConference_name(char* cad) {
    if(conference_name)delete conference_name;
    conference_name = new char [strlen(cad)+1];
    strcpy(conference_name,cad);
}

void ConferencePaper::GetConference_name(char* cad) const {
    if(conference_name)strcpy(cad,conference_name);
    else cad[0]=0;
}

void ConferencePaper::SetConferencePaper(char *name,char *country,int id,char *title, char *author,int year){
    SetConference_name(name);
    SetHost_country(country);
    SetAuthor_name(author);
    SetId(id);
    SetTitle(title);
    SetPublication_year(year);
}


void ConferencePaper::leerDatos(ifstream &arch){
    int id,aa;
    char nomb[80],titulo[200],c,conference[200],country[30];
    arch>>id>>c;
    if(arch.eof())return;
    arch.getline(nomb,80,';');
    arch>>aa>>c;
    arch.getline(titulo,200,';');
    arch.getline(conference,200,';');
    arch.getline(country,30,'\n');
    SetConferencePaper(conference,country,id,titulo,nomb,aa);
}


void ConferencePaper::citar(ofstream &arch){
    char cad[200];
    GetAuthor_name(cad);
    arch<<left<<cad<<" ("<<GetPublication_year()<<").";
    GetTitle(cad);
    arch<<left<<cad<<". ";
    GetConference_name(cad);
    arch<<left<<cad<<". ";
    GetHost_country(cad);
    arch<<left<<cad<<"."<<endl;
}