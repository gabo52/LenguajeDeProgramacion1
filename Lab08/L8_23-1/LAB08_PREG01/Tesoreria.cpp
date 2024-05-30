#include "Tesoreria.hpp"
#include "Escala.hpp"

using namespace std;

Tesoreria::Tesoreria() {
}

Tesoreria::~Tesoreria() {

}

void Tesoreria::cargaescalas(void) {
    ifstream file("escalas.csv", ios::in);
    if (not file.is_open()) {
        cout << "ERROR: No se puedo abrir el archivo escalas.csv" << endl;
        exit(1);
    }
    Escala aux_escala;
    int n = 0;
    while (true) {
        leeEscala(file, aux_escala);
        if (file.eof()) break;
        this->lescala[aux_escala.getCodigo() - 1] = aux_escala;
    }
    file.close();
}

//5,666.90

void Tesoreria::leeEscala(ifstream &file, Escala &escala) {
    int codigo;
    double precio;
    file >> codigo;
    if (file.eof()) return;
    file.get();
    file >> precio;
    escala.setCodigo(codigo);
    escala.setPrecio(precio);
}

void Tesoreria::cargaalumnos(void) {
    ifstream file("Alumnos.csv", ios::in);
    if (not file.is_open()) {
        cout << "ERROR: No se puedo abrir el archivo Alumnos.csv" << endl;
        exit(1);
    }
    int cnt_virtual = 0, cnt_presencial = 0, cnt_semipresencial = 0;
    char tipo, c;
    Presencial presencial;
    Virtual avirtual;
    Semipresencial semipresencial;
    while (true) {
        file >> tipo >> c;
        if (file.eof()) break;
        if (tipo == 'P') { // presencial
            leerAlumnoPresencial(file, presencial);
            lpresencial[cnt_presencial++] = presencial;
        } else if (tipo == 'V') {//virtual
            leerAlumnoVirtual(file, avirtual);
            lvirtual[cnt_virtual++] = avirtual;
        } else {//semipresencial
            leerAlumnoSemiPresencial(file, semipresencial);
            lsemipresencial[cnt_semipresencial++] = semipresencial;
        }
    }
    file.close();
}
//P,202119153,MENDOZA/ARIAS/HENRY,10,4

void Tesoreria::leerAlumnoPresencial(ifstream &file, Presencial & presencial) {
    int codigo, escala;
    char nombre[50], c;
    double recargar;
    file >> codigo >> c;
    file.getline(nombre, 50, ',');
    file >> recargar >> c >> escala;
    file.get(); //salto de linea
    presencial.setCodigo(codigo);
    presencial.setNombre(nombre);
    presencial.setRecargar(recargar);
    presencial.setEscala(escala);
}

//V,202318072,RIVERA/MONTERO/GLORIA-OFELIA,323R33-2,3

void Tesoreria::leerAlumnoVirtual(ifstream &file, Virtual & avirtual) {
    int codigo, escala;
    char nombre[50], licencia[50], c;
    file >> codigo >> c;
    file.getline(nombre, 50, ','); //nombre
    file.getline(licencia, 50, ','); //licencia
    file >> escala;
    file.get(); //salto de linea
    avirtual.setCodigo(codigo);
    avirtual.setNombre(nombre);
    avirtual.setLicencia(licencia);
    avirtual.setEscala(escala);
}
//S,202123703,GAMARRA/TABORI/PAUL-RONAL,30,5

void Tesoreria::leerAlumnoSemiPresencial(ifstream &file, Semipresencial & semi) {
    int codigo, escala;
    char nombre[50], c;
    double descuento;
    file >> codigo >> c;
    file.getline(nombre, 50, ','); //nombre
    file >> descuento >> c >> escala;
    file.get(); //salto de linea
    semi.setCodigo(codigo);
    semi.setNombre(nombre);
    semi.setDescuento(descuento);
    semi.setEscala(escala);
}
//leerAlumnoVirtual(file, avirtual);
//leerAlumnoSemiPresencial(file, semipresencial);

void Tesoreria::actualiza(int creditos) {
    int i = 0, j = 0, k = 0;
    while (this->lpresencial[i].getEscala() != 0) {
        double precio = lescala[lpresencial[i].getEscala() - 1].getPrecio();
        double total = precio * creditos;
        double recargo = total * (lpresencial[i].getRecargar() / 100);
        lpresencial[i].setTotal(total);
        lpresencial[i].Alumno::setTotal(total + recargo);
        i++;
    }
    while (this->lsemipresencial[j].getEscala() != 0) {
        double precio = lescala[lsemipresencial[j].getEscala() - 1].getPrecio();
        double total = precio * creditos;
        double descuento = total * (lsemipresencial[j].getDescuento() / 100);
        lsemipresencial[j].setTotal(total);
        lsemipresencial[j].Alumno::setTotal(total - descuento);
        j++;
    }
    while (this->lvirtual[k].getEscala() != 0) {
        double precio = lescala[lvirtual[k].getEscala() - 1].getPrecio();
        double total = precio * creditos;
        lvirtual[k].setTotal(total);
        lvirtual[k].Alumno::setTotal(total + 100);
        k++;
    }
}

void Tesoreria::imprime(void) {
    ofstream file("reporte.txt", ios::out);
    if (not file.is_open()) {
        cout << "ERROR: No se puede abrtir el archivo reporte.txt" << endl;
        exit(1);
    }
    imprimirCabecera(file);
    file << fixed << setprecision(2);
    for (int i = 0; i < lpresencial[i].getCodigo() != 0; i++) {
        char nombre[50];
        lpresencial[i].getNombre(nombre);
        file << setw(15) << lpresencial[i].getCodigo()
                << setw(50) << nombre
                << setw(10) << lpresencial[i].getEscala()
                << setw(20) << " " << lpresencial[i].Alumno::getTotal() << endl;
    }
    for (int i = 0; i < lvirtual[i].getCodigo() != 0; i++) {
        char nombre[50], licencia[50];
        lvirtual[i].getNombre(nombre);
        lvirtual[i].getLicencia(licencia);
        file << setw(15) << lvirtual[i].getCodigo()
                << setw(50) << nombre
                << setw(10) << lvirtual[i].getEscala()
                << setw(20) << licencia << lvirtual[i].Alumno::getTotal() << endl;
    }
    for (int i = 0; i < lsemipresencial[i].getCodigo() != 0; i++) {
        char nombre[50];
        lsemipresencial[i].getNombre(nombre);
        file << setw(15) << lsemipresencial[i].getCodigo()
                << setw(50) << nombre
                << setw(10) << lsemipresencial[i].getEscala()
                << setw(20) << " " << lsemipresencial[i].Alumno::getTotal() << endl;
    }
    file.close();
}

void Tesoreria::imprimirCabecera(ofstream &file) {
    file << setfill('=') << setw(120) << "=" << setfill(' ') << endl;
    file << left;
    file << setw(15) << "Codigo" << setw(50) << "Nombre" << setw(10) << "Escala" << setw(20) << "Licencia" << "Total" << endl;
    file << setfill('=') << setw(120) << "=" << setfill(' ') << endl;
}

