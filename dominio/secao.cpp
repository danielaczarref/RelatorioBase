#include "secao.h"

Secao::Secao(QObject *parent) : QObject(parent)
{
}

long long Secao::getIdSecao() const
{
    return idSecao;
}

void Secao::setIdSecao(long long value)
{
    idSecao = value;
}

QString Secao::getDescSecao() const
{
    return descSecao;
}

void Secao::setDescSecao(const QString &value)
{
    descSecao = value;
}

long long Secao::getIdDepartamento() const
{
    return idDepartamento;
}

void Secao::setIdDepartamento(long long value)
{
    idDepartamento = value;
}

QString Secao::getDescDepartamento() const
{
    return descDepartamento;
}

void Secao::setDescDepartamento(const QString &value)
{
    descDepartamento = value;
}
