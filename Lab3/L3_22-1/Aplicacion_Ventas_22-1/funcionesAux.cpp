/*
 * File:   funcionesAux.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "BibliotecaFunc.h"
#include "funcionesAux.h"
using namespace std;

void leerClientes(struct Estructura_ClienteRegistrado *c){
    ifstream archClien;
    int i=0;
    AperturaDeUnArchivoDeTextosParaLeer(archClien,"Clientes.txt");
    c[0].dni=0;
    while(1){
        archClien>>c[i];
        if(archClien.eof()){
            c[i].dni=0;
            return;
        }
        i++;
    }
}

/*  DOB245   LECHE_LALA_SEMI_DESLACTOSADA_1LT  1.78  16.98    71378466  26/10/2020
    QBL949     YOGHURT_NATURAL_LIGHT_LALA_1KG   %4.7      5.54  25.86   32821689   19/04/2020
*/
void cargarClientesProductos(struct Estructura_ClienteRegistrado *c,
        struct Estructura_ProductosEnAlmacen *p){
    strcpy(p[0].codigo,"X");
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.txt");
    int DNI,dd,mm,aa,fecha;
    char codigo[7],descripcion[80],dato;
    double cant,precio,porcentaje=0;
    while(1){
        archPed>>codigo;
        if(archPed.eof())break;
        porcentaje=0;
        archPed>>descripcion>>cant;
        if(archPed.fail()){
            archPed.clear();
            archPed>>dato>>porcentaje>>cant;
        }
        archPed>>precio>>DNI>>dd>>dato>>mm>>dato>>aa;
        fecha=aa*10000+mm*100+dd;
        llenarClientesAlmacen(c,p,codigo,descripcion,porcentaje,cant,precio,DNI,fecha);
    }
}

void llenarClientesAlmacen(struct Estructura_ClienteRegistrado *c,
        struct Estructura_ProductosEnAlmacen *p,char *codigo,char *descripcion,
        double porcentaje,double cant,double precio,int DNI,int fecha){
    int i;
    //Llenamos el almacen de productos
    struct Estructura_ProductosEnAlmacen prod;
    struct Estructura_PedidoRealizado ped;
    strcpy(prod.codigo,codigo);
    strcpy(prod.descripcion,descripcion);
    prod.descuento=porcentaje;
    prod.precioUnitario=precio;
    p+=prod;
    for(i=0;c[i].dni;i++){
        if(c[i].dni==DNI){
            cargaPedidoCliente(c[i],codigo,cant,fecha);
            return;
        }
    }
    cout<<"ERRROR, no se encontró el cliente con DNI: "<<DNI;;
}

void cargaPedidoCliente(struct Estructura_ClienteRegistrado &c,
                    char *codigo,double cant,int fecha){
    struct Estructura_PedidoRealizado aux;
    aux.cantidad=cant;
    aux.fecha=fecha;
    strcpy(aux.codigo,codigo);
    c+=aux;
}
void imprimirReporte(struct Estructura_ClienteRegistrado *c,
        struct Estructura_ProductosEnAlmacen *p){
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"Reporte.txt");
    archRep<<p;
    for(int i=0;c[i].dni;i++){
        archRep<<c[i];
    }
}

