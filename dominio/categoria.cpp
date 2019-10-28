#include "categoria.h"

Categoria::Categoria(QObject *parent) : QObject(parent)
{
}

long long Categoria::getIdCategoria() const
{
    return idCategoria;
}

void Categoria::setIdCategoria(long long value)
{
    idCategoria = value;
}

QString Categoria::getDescCategoria() const
{
    return descCategoria;
}

void Categoria::setDescCategoria(const QString &value)
{
    descCategoria = value;
}

QString Categoria::getDescSecao() const
{
    return descSecao;
}

void Categoria::setDescSecao(const QString &value)
{
    descSecao = value;
}

long long Categoria::getIdSecao() const
{
    return idSecao;
}

void Categoria::setIdSecao(long long value)
{
    idSecao = value;
}
