#ifndef CADASTROPRODUTO_H
#define CADASTROPRODUTO_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include "dominio/produto.h"


class CadastroProduto : public QObject
{
    Q_OBJECT
public:
    explicit CadastroProduto(QObject *parent = nullptr);
    //CadastroProduto();
    int getIdProduto() const;

    QString getDescricaoProduto(int id) const;
    bool inserirDescricaoProduto(const QString &value);
    QList<Produto*> getInformacoesProduto();


    QSqlDatabase db;

    double getValorProduto(int idProduto) const;
    bool defineValorProduto(double preco);

    int RetornaIdDoProdutoPelaDescricao (const QString &UsadaParaBuscarIdDoProduto);

private:
    int id;
    QString descricao;
    double preco;
    QString UsadaParaBuscarIdDoProduto;

};

#endif // CADASTROPRODUTO_H
