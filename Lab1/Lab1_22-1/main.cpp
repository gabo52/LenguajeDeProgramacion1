/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 13 de abril de 2023, 04:02 PM
 */

#include <iostream>
#include <iomanip>
#define MAX_CAR 150

using namespace std;

void copiarcadena(char *cad1, char *cad2){
    int i = 0; 
    while(cad1[i] != '\0') i++;
    
    for(int j=0;j<i;j++) cad2[j] = cad1[j];
    
    cad2[i] = '\0';
}

int compararcadenas(char *cad1, char *cad2){
    int i = 0; 
    while(cad1[i] != '\0') i++;
    
    for(int j=0;j<i;j++){
        if(cad1[j] != cad2[j]) return 1;
    }
    
    return 0;
}

char formatoycategoria (char *nombre){
    char categoria; 
    int n, i = 0, j = 0; 
    
    while(nombre[i] != '\0') i++;
   
    if(nombre[i-2] == '-'){
        categoria = nombre[i-1];
        i = i-2; 
    }else{
        categoria = '-'; 
    } 
    
    n = i; 
    
    for(i=0;i<n;i++){
        if(nombre[i] == '/' || nombre[i] == '-') nombre[i] = ' '; 
    }
    nombre[n] = '\0';
    
    return categoria; 
}
    
void imprimelinea(char car, int n){
    for(int i=0;i<n;i++) cout << car;
    cout << endl; 
}

int main(int argc, char** argv) {
    int flag = 0, dni, telefono, aa, mm, dd, id; 
    char prodVer[10], cliMayorDesc[100], nombre[100], codProd[10], descripcion[100], car, categoria, descVer[100];
    double apagar, descuentoTotal, mayorDesc = 0, totalIngresado = 0, descAdicional, descuento, descuentoA, descuentoB, descuentoC, cant, precioUnitario;
    cin >> car >> descuentoA >> car >> car >> descuentoB >> car >> car >> descuentoC >> car >> prodVer; 
    
    cout << setw(60) << " " << "EMPRESA COMERCIALIZADORA DE ABARROTES" << endl;
    imprimelinea('=', MAX_CAR); 
    cout << "GASTOS DE LOS CLIENTES REGISTRADOS: " << endl;
    
    cout.precision(2);
    cout << fixed;
    
    while(1){
        cin >> dni; 
        if(cin.eof()){
            imprimelinea('-', MAX_CAR); 
            cout << "     TOTAL:" << setw(96) << " " << setw(7) << apagar << "    " << setw(7) << descuentoTotal << endl;
            imprimelinea('=', MAX_CAR); 
            cout << "CLIENTE QUE RECIBIO MAS DESCUENTO: " << cliMayorDesc << "    DESCUENTO TOTAL: " << mayorDesc << endl;
            cout << "PRODUCTO A VERIFICAR: " << descVer << " [" << prodVer << "]   TOTAL INGRESADO POR EL PRODUCTO: " << totalIngresado << endl;
            break;
        }
        if(cin.fail()){
            cin.clear();
            cin >> codProd >> descripcion;
            cin >> cant; 
            if(cin.fail()){
                cin.clear();
                cin >> car >> descAdicional >> cant; 
            }else{
                descAdicional = 0; 
            }
            cin >> precioUnitario >> dd >> car >> mm >> car >> aa;
            cout << " " << setw(2) << id << "  " << codProd << "  " << left << setw(40) << descripcion << right << "     " << setw(6) << precioUnitario << "     " << setw(5) << cant << setw(5) << "     " << setw(7) << cant*precioUnitario;
            if(descAdicional == 0) 
                cout << setw(13) << "-.--"; 
            else 
                cout << setw(13) << descAdicional; 
            cout << "|" << setw(5) << descuento << "  " << setw(7) << cant*precioUnitario - ((double)((descAdicional + descuento)/100) * (cant*precioUnitario)) << "     " << setw(6) << ((double)((descAdicional + descuento)/100) * (cant*precioUnitario)) << setw(4) << "  " << setfill('0') << setw(2) << dd << "/" << setw(2) << mm << "/" << aa << setfill(' ') << endl; 
            if(!compararcadenas(codProd, prodVer)){
                copiarcadena(descripcion, descVer); 
                totalIngresado = totalIngresado + cant*precioUnitario - ((double)((descAdicional + descuento)/100) * (cant*precioUnitario));
            }
            apagar = apagar + cant*precioUnitario - ((double)((descAdicional + descuento)/100) * (cant*precioUnitario));
            descuentoTotal = descuentoTotal + ((double)((descAdicional + descuento)/100) * (cant*precioUnitario)); 
            id++; 
        }else{
            if(flag == 1){
                imprimelinea('-', MAX_CAR); 
                cout << "     TOTAL:" << setw(96) << " " << setw(7) << apagar << "    " << setw(7) << descuentoTotal << endl;
            }
            flag = 1; 
            if(descuentoTotal > mayorDesc){
                mayorDesc = descuentoTotal; 
                copiarcadena(nombre, cliMayorDesc); 
            }
            
            cin >> nombre >> telefono; 
            categoria = formatoycategoria(nombre); 
            id = 1; 
            apagar = 0;
            descuentoTotal = 0; 
            imprimelinea('=', MAX_CAR); 
            cout << "DNI" << setw(15) << " " << "Nombre" << setw(49) << " " << "Telefono" 
                 << setw(19) << " " << "Categoria" << setw(10) << " " << "Descuento" << endl; 
            
            cout << dni << setw(10) << " " << left << setw(50) << nombre << right << setw(5) 
                    << " "  << left << setw(11) << telefono << right << setw(20) << " " << categoria << setw(15) << " "; 
            if(categoria != 'A' && categoria != 'B' && categoria != 'C') 
                cout << setw(5) << "-.--%";
            else{
                if(categoria == 'A') descuento = descuentoA; 
                if(categoria == 'B') descuento = descuentoB; 
                if(categoria == 'C') descuento = descuentoC; 
                cout << setw(5) << descuento << "%";
            }
                           
            cout << endl;   
          
            imprimelinea('-', MAX_CAR); 
            cout << "PRODUCTOS ADQUIRIDOS:" << endl;
            imprimelinea('-', MAX_CAR); 
            cout << "     Codigo  Descripcion" << setw(36) << " " << "P.U     Cantidad     Total         Descuentos %  A Pagar  Descuento    Fecha" << endl;
            imprimelinea('-', MAX_CAR); 
        }
    }
    return 0;
}

