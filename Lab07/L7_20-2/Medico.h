
/* 
 * File:   Medico.h
 * Author: USER
 *
 * Created on 8 de junio de 2023, 03:36 PM
 */

#ifndef MEDICO_H
#define MEDICO_H

class Medico {
public:
    Medico();
    Medico(const Medico& orig);
    virtual ~Medico();
    void SetIngresosS(double ingresosS);
    double GetIngresosS() const;
    void SetIngresosP(double ingresosP);
    double GetIngresosP() const;
    void SetNumPac(int numPac);
    int GetNumPac() const;
    void SetEstado(char* estado);
    char* GetEstado() const;
    void SetPrima(double* prima);
    double* GetPrima() const;
    void SetPacientes(int* pacientes);
    int* GetPacientes() const;
    void SetFechas(int* fechas);
    int* GetFechas() const;
    void SetTarifa(double tarifa);
    double GetTarifa() const;
    void SetEspecialidad(char *cad);
    void GetEspecialidad(char *cad) const;
    void SetNombre(char *cad);
    void GetNombre(char *cad) const;
    void SetCodigo(char *cad);
    void GetCodigo(char *cad) const;
    void copia(const Medico &c);
private:
    char *codigo;
    char *nombre;
    char *especialidad;
    double tarifa; 
    int fechas[100];
    int pacientes[100]; 
    double prima[100]; 
    char estado[100];
    int numPac;
    double ingresosP; 
    double ingresosS;
};

#endif /* MEDICO_H */

