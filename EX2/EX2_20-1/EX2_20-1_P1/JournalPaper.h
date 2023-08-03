/* 
 * File:   JournalPaper.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 11:10 PM
 */

#ifndef JOURNALPAPER_H
#define JOURNALPAPER_H

#include "Paper.h"


class JournalPaper : public Paper{
public:
    JournalPaper();
    virtual ~JournalPaper();
    void SetJournalPaper(char *journal,int vol,int id,char *title, char *author,int year);
    void SetVolume(int volume);
    int GetVolume() const;
    void SetJournal_name(char* cad);
    void GetJournal_name(char* cad) const;
    void leerDatos(ifstream &arch);
    void citar(ofstream &arch);
private:
    char *journal_name;
    int volume;
};

#endif /* JOURNALPAPER_H */

