#include "estoque.h"

Estoque::Estoque(QObject *parent) : QObject(parent)
{
}

double Estoque::getBasedoProduto() const
{
    return BasedoProduto;
}

void Estoque::setBasedoProduto(double value)
{
    BasedoProduto = value;
}

Categoria *Estoque::getCategoria() const
{
    return _categoria;
}

void Estoque::setCategoria(Categoria *categoria)
{
    _categoria = categoria;
}

Produto *Estoque::getProduto() const
{
    return _produto;
}

void Estoque::setProduto(Produto *produto)
{
    _produto = produto;
}

Filial *Estoque::getFilial() const
{
    return _filial;
}

void Estoque::setFilial(Filial *filial)
{
    _filial = filial;
}
