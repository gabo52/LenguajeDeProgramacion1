/* 
 * File:   Paper.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 11:09 PM
 */

#include "Paper.h"
#include <cstring>
Paper::Paper() {
    id=0;
    author_name=nullptr;
    title=nullptr;
}



Paper::~Paper() {
    if(author_name)delete author_name;
    if(title)delete title;
}

void Paper::SetPublication_year(int publication_year) {
    this->publication_year = publication_year;
}

int Paper::GetPublication_year() const {
    return publication_year;
}

void Paper::SetAuthor_name(char* cad) {
    if(author_name)delete author_name;
    author_name = new char [strlen(cad)+1];
    strcpy(author_name,cad);
}

void Paper::GetAuthor_name(char* cad) const {
    if(author_name)strcpy(cad,author_name);
    else cad[0]=0;
}

void Paper::SetTitle(char* cad) {
    if(title)delete title;
    title = new char [strlen(cad)+1];
    strcpy(title,cad);
}

void Paper::GetTitle(char* cad) const {
    if(title)strcpy(cad,title);
    else cad[0]=0;
}

void Paper::SetId(int id) {
    this->id = id;
}

int Paper::GetId() const {
    return id;
}

