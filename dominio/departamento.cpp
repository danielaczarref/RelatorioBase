#include "departamento.h"

Departamento::Departamento(QObject *parent) : QObject(parent)
{

}

long long Departamento::getIdDepartamento() const
{
    return idDepartamento;
}

void Departamento::setIdDepartamento(long long value)
{
    idDepartamento = value;
}

QString Departamento::getDescDepartamento() const
{
    return descDepartamento;
}

void Departamento::setDescDepartamento(const QString &value)
{
    descDepartamento = value;
}
