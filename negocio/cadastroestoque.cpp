#include "negocio/cadastroestoque.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

CadastroEstoque::CadastroEstoque(QObject* parent) : QObject(parent)
{

}

int CadastroEstoque::getIdProdutoEstoque() const
{
    QSqlQuery query;
    query.prepare("SELECT id_produto FROM estoque"); //vai ter alguma mudança nisso dps
    query.exec();
    return idProduto;
}

int CadastroEstoque::getIdFilialEstoque() const
{
    QSqlQuery query;
    query.prepare("SELECT id_filial FROM estoque");
    query.exec();
    return idFilial;
}

QString CadastroEstoque::getBasedoProdutoEstoque(QString descProduto, QString descFilial) const
{
    QSqlQuery query;
    query.prepare("SELECT base FROM estoque where id_produto = (select id_produto from produto where produto = '" + descProduto + "') and id_filial = (select id from filial where descricao = '" + descFilial + "');");
    query.exec();

    double id;
    if(query.next())
        id = query.value("base").toDouble();
    return QString::number(id);
}
