#ifndef PRODUTO_H
#define PRODUTO_H

#include <QObject>
#include "dominio/categoria.h"
#include "dominio/secao.h"
#include "dominio/departamento.h"

class Produto : public QObject
{
    Q_OBJECT
public:
    explicit Produto(QObject *parent = 0);
   // Produto();

    long long getIdProduto() const;
    void setIdProduto(long long value);

    QString getDescProduto() const;
    void setDescProduto(const QString &value);

    double getValorProduto() const;
    void setValorProduto(double value);

    Categoria *getCategoria() const;
    void setCategoria(Categoria *categoria);

    Secao *getSecao() const;
    void setSecao(Secao *secao);

    Departamento *getDepartamento() const;
    void setDepartamento(Departamento *departamento);

private:
    long long idProduto;
    QString descProduto;
    double valorProduto;
    Categoria* _categoria = nullptr;
    Secao* _secao = nullptr;
    Departamento* _departamento = nullptr;

//    long long idCategoria;
//    QString descCategoria;
};

#endif // PRODUTO_H
