#include "cadastrobase.h"

CadastroBase::CadastroBase(QObject *parent) : QObject(parent)
{
}

long long CadastroBase::id() const
{
    return _id;
}

void CadastroBase::setId(long long id)
{
    _id = id;
}

QString CadastroBase::categoria() const
{
    return _categoria;
}

void CadastroBase::setCategoria(const QString &categoria)
{
    _categoria = categoria;
}

QString CadastroBase::produto() const
{
    return _produto;
}

void CadastroBase::setProduto(const QString &produto)
{
    _produto = produto;
}

QString CadastroBase::base() const
{
    return _base;
}

void CadastroBase::setBase(const QString &base)
{
    _base = base;
}
