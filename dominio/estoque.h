#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <QObject>
#include "dominio/categoria.h"
#include "dominio/filial.h"
#include "dominio/produto.h"

class Estoque : public QObject
{
    Q_OBJECT

public:
    explicit Estoque(QObject *parent = 0);
    //Estoque();
    double getBasedoProduto() const;
    void setBasedoProduto(double value);

    Categoria *getCategoria() const;
    void setCategoria(Categoria *categoria);

    Produto *getProduto() const;
    void setProduto(Produto *produto);

    Filial *getFilial() const;
    void setFilial(Filial *filial);

private:
    double BasedoProduto;
    Categoria* _categoria = nullptr;
    Produto* _produto = nullptr;
    Filial* _filial = nullptr;
};

#endif // ESTOQUE_H
