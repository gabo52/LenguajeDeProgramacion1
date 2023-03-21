/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gabri
 *
 * Created on 16 de agosto de 2022, 11:34 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    double precio=2.5;
    int dato;
    cout << setw(50)<<left<<"pipipi"<<endl;
    cout << "Quiero un chijaukay"<<endl;
    cout << setprecision(3)<<fixed<<precio<<endl;
    cin  >> dato;
    cout << "Este es el dato: "<<dato<<endl;
    return 0;
}

