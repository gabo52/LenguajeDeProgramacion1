/* 
 * File:   ListaDoble.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 12:00 AM
 */

#include "ListaDoble.hpp"

ListaDoble::ListaDoble() {
    inicio = nullptr;
    fin = nullptr;
}

ListaDoble::ListaDoble(const ListaDoble& orig) {
}

ListaDoble::~ListaDoble() {
    if (inicio != nullptr) delete inicio;
    if (fin != nullptr) delete fin;
}

bool ListaDoble::existeAlumno(class Alumno &alumno) {
    if (this->inicio == nullptr) return false; //primer alumno que se inserta
    Nodo *recorrido = this->inicio;
    Nodo *anterior = nullptr;
    while (recorrido != nullptr) {
        anterior = recorrido;
        if (anterior->dato.esAlumno(alumno)) return true;
        recorrido = recorrido->siguiente;
    }
    return false;
}

void ListaDoble::insertarOrdenado(class Nodo *&nodo) {
    Nodo *recorrido = this->inicio;
    Nodo *anterior = nullptr;
    while (recorrido != nullptr) {
        anterior = recorrido;
        if (nodo->dato < recorrido->dato) {
            break;
        }
        recorrido = recorrido->siguiente;
    }
    if (anterior == nullptr) {// estamos insertando el primer nodo
        this->inicio = nodo;
        this->fin = nodo;
        nodo->siguiente = nullptr;
        nodo->anterior = nullptr;
    } else {
        if (anterior == this->fin) {//el nuevo nodo va al final
            anterior->siguiente = nodo;
            nodo->anterior = anterior;
            nodo->siguiente = nullptr;
            this->fin = nodo;
        } else {
            if (anterior == this->inicio) {
                nodo->siguiente = anterior;
                anterior->anterior = nodo;
                nodo->anterior = nullptr;
                this->inicio = nodo;
            } else {
                nodo->siguiente = recorrido;
                nodo->anterior = anterior;
                anterior->siguiente = nodo;
                recorrido->anterior = nodo;
            }

        }
    }
}

void ListaDoble::insertarNota(int codigo_alumno, class Nota &nota) {
    Nodo *recorrido = this->inicio;
    Nodo *anterior = nullptr;
    while (recorrido != nullptr) {
        anterior = recorrido;
        if (anterior->dato.esALumno(codigo_alumno))break;
        recorrido = recorrido->siguiente;
    }
    anterior->insertarNota(nota);
}

void ListaDoble::imprimirReporte(std::ofstream &archReporte) {
    Nodo* recorrido = this->inicio;
    while (recorrido != nullptr) {
        recorrido->dato.imprimirAlumno(archReporte);
        recorrido = recorrido->siguiente;
    }
}

