
/* 
 * File:   Infraccion.h
 * Author: USER
 *
 * Created on 20 de junio de 2023, 03:28 PM
 */

#ifndef INFRACCION_H
#define INFRACCION_H

class Infraccion {
public:
    Infraccion();
    Infraccion(const Infraccion& orig);
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(char *cad);
    void GetGravedad(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    char *gravedad;
    double multa; 
};

#endif /* INFRACCION_H */

