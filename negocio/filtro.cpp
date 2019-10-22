#include "filtro.h"
#include <QObject>

Filtro::Filtro(QObject* parent) : QObject(parent)
{

}

int Filtro::getFilial() const
{
    return filial;
}

void Filtro::setFilial(int value)
{
    filial = value;
}

int Filtro::getDepartamento() const
{
    return departamento;
}

void Filtro::setDepartamento(int value)
{
    departamento = value;
}

int Filtro::getSecao() const
{
    return secao;
}

void Filtro::setSecao(int value)
{
    secao = value;
}

int Filtro::getCategoria() const
{
    return categoria;
}

void Filtro::setCategoria(int value)
{
    categoria = value;
}

int Filtro::getProduto() const
{
    return produto;
}

void Filtro::setProduto(int value)
{
    produto = value;
}
