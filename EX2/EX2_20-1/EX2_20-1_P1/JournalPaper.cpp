/* 
 * File:   JournalPaper.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 11:10 PM
 */


#include <cstring>

#include "JournalPaper.h"

JournalPaper::JournalPaper() {
    journal_name=nullptr;
    volume =0;
    
}


JournalPaper::~JournalPaper() {
    if(journal_name)delete journal_name;
}

void JournalPaper::SetJournalPaper(char *journal,int vol,int id,char *title, char *author,int year){
    SetJournal_name(journal);
    SetVolume(vol);
    SetAuthor_name(author);
    SetId(id);
    SetTitle(title);
    SetPublication_year(year);
}

void JournalPaper::SetVolume(int volume) {
    this->volume = volume;
}

int JournalPaper::GetVolume() const {
    return volume;
}

void JournalPaper::SetJournal_name(char* cad) {
    if(journal_name)delete journal_name;
    journal_name = new char [strlen(cad)+1];
    strcpy(journal_name,cad);
}

void JournalPaper::GetJournal_name(char* cad) const {
    if(journal_name)strcpy(cad,journal_name);
    else cad[0]=0;
}


void JournalPaper::leerDatos(ifstream &arch){
    int id,aa,vol;
    char nomb[80],titulo[200],c,nombRev[200];
    arch>>id>>c;
    if(arch.eof())return;
    arch.getline(nomb,80,';');
    arch>>aa>>c;
    arch.getline(titulo,200,';');
    arch.getline(nombRev,200,';');
    arch>>vol;
    arch.get();
    SetJournalPaper(nombRev,vol,id,titulo,nomb,aa);
}

void JournalPaper::citar(ofstream &arch){
    char cad[200];
    GetAuthor_name(cad);
    arch<<left<<cad<<" ("<<GetPublication_year()<<").";
    GetTitle(cad);
    arch<<left<<cad<<". ";
    GetJournal_name(cad);
    arch<<left<<cad<<", ";
    arch<<GetVolume()<<"."<<endl;
}
