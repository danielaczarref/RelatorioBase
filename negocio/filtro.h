#ifndef FILTRO_H
#define FILTRO_H
#include <QWidget>

class Filtro : public QObject
{
    Q_OBJECT
public:
    explicit Filtro(QObject *parent = 0);

    int getFilial() const;
    void setFilial(int value);

    int getDepartamento() const;
    void setDepartamento(int value);

    int getSecao() const;
    void setSecao(int value);

    int getCategoria() const;
    void setCategoria(int value);

    int getProduto() const;
    void setProduto(int value);

private:
    int filial;
    int departamento;
    int secao;
    int categoria;
    int produto;
};

#endif // FILTRO_H
