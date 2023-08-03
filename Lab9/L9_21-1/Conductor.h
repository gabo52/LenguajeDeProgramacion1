

/* 
 * File:   Conductor.h
 * Author: USER
 *
 * Created on 20 de junio de 2023, 03:24 PM
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H

class Conductor {
public:
    Conductor();
    Conductor(const Conductor& orig);
    virtual ~Conductor();
    void SetLicencia(int licencia);
    int GetLicencia() const;
    void SetNombre(char *cad);
    void GetNombre(char *cad) const;
private:
    int licencia;
    char *nombre; 
};

#endif /* CONDUCTOR_H */

