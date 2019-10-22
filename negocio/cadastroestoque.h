#ifndef CADASTROESTOQUE_H
#define CADASTROESTOQUE_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include "dominio/estoque.h"
#include "negocio/filtro.h"



class CadastroEstoque : public QObject
{
    Q_OBJECT
public:
    explicit CadastroEstoque(QObject *parent = nullptr);
    //CadastroEstoque();

    int getIdProdutoEstoque() const;
    QList<Estoque*> getInformacoesEstoque(QString sfilial, QString sproduto);

    int getIdFilialEstoque() const;
    double getBasedoProdutoEstoque(int idProduto, int idFilial) const;
    bool defineBasedoProdutoEstoque(double value);

    QList<Estoque*> recuperarEstoques(Filtro* filtro);

    QSqlDatabase db;

private:
    int idProduto;
    int idFilial;
    double base;
};

#endif // CADASTROESTOQUE_H
