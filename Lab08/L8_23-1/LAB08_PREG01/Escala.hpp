#ifndef LAB08_PREG01_ESCALA_HPP
#define LAB08_PREG01_ESCALA_HPP


class Escala {
public:
    Escala();
    virtual ~Escala();

private:
    int codigo;
    double precio;
public:
    int getCodigo() const;

    void setCodigo(int codigo);

    double getPrecio() const;

    void setPrecio(double precio);
};


#endif //LAB08_PREG01_ESCALA_HPP
