#include "filial.h"

Filial::Filial(QObject *parent) : QObject(parent)
{
}

long long Filial::getIdFilial() const
{
    return idFilial;
}

void Filial::setIdFilial(long long value)
{
    idFilial = value;
}

QString Filial::getDescFilial() const
{
    return descFilial;
}

void Filial::setDescFilial(const QString &value)
{
    descFilial = value;
}
