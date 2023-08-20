
/* 
 * File:   Paciente.h
 * Author: USER
 *
 * Created on 8 de junio de 2023, 03:39 PM
 */

#ifndef PACIENTE_H
#define PACIENTE_H

class Paciente {
public:
    Paciente();
    Paciente(const Paciente& orig);
    virtual ~Paciente();
    void SetEstado(char estado);
    char GetEstado() const;
    void SetPrima(double prima);
    double GetPrima() const;
    void SetNombre(char *cad);
    char GetNombre(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    int copia(const Paciente &p);
private:
    int fecha;
    int codigo;
    char *nombre;
    double prima;
    char estado;
};

#endif /* PACIENTE_H */

