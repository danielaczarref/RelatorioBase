#include "produto.h"

Produto::Produto(QObject *parent) : QObject(parent)
{

}

long long Produto::getIdProduto() const
{
    return idProduto;
}

void Produto::setIdProduto(long long value)
{
    idProduto = value;
}

QString Produto::getDescProduto() const
{
    return descProduto;
}

void Produto::setDescProduto(const QString &value)
{
    descProduto = value;
}

double Produto::getValorProduto() const
{
    return valorProduto;
}

void Produto::setValorProduto(double value)
{
    valorProduto = value;
}

Categoria *Produto::getCategoria() const
{
    return _categoria;
}

void Produto::setCategoria(Categoria *categoria)
{
    _categoria = categoria;
}

Secao *Produto::getSecao() const
{
    return _secao;
}

void Produto::setSecao(Secao *secao)
{
    _secao = secao;
}

Departamento *Produto::getDepartamento() const
{
    return _departamento;
}

void Produto::setDepartamento(Departamento *departamento)
{
    _departamento = departamento;
}
