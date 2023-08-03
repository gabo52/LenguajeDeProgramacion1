/* 
 * File:   Paper.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 11:09 PM
 */

#ifndef PAPER_H
#define PAPER_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Paper {
public:
    Paper();
    virtual ~Paper();
    void SetPublication_year(int publication_year);
    int GetPublication_year() const;
    void SetAuthor_name(char* author_name);
    void GetAuthor_name(char* cad) const;
    void SetTitle(char* title);
    void GetTitle(char* cad) const;
    void SetId(int id);
    int GetId() const;
    virtual void leerDatos(ifstream &arch)=0;
    virtual void citar(ofstream &arch)=0;
private:
    int id;
    char *title;
    char *author_name;
    int publication_year;
};

#endif /* PAPER_H */

