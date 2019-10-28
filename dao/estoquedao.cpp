#include "estoquedao.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <negocio/filtro.h>


EstoqueDAO::EstoqueDAO(QObject *parent) : QObject(parent)
{

}

QList<Estoque *> EstoqueDAO::recuperEstoque(Filtro* filtro)
{
    QString sQuery = "select estoque.base, estoque.id_produto, "
            "estoque.id_filial, "
            "filial.descricao, "
            "produto.id_categoria, "
            "produto.produto, "
            "produto.valor, "
            "categoria.categoria, "
            "categoria.id_secao, "
            "secao.secao, "
            "secao.id_departamento, "
            "departamento.descricao "
     "from estoque "
          "left join filial on estoque.id_filial = filial.id "
          "left join produto on estoque.id_produto = produto.id_produto "
          "left join categoria on produto.id_categoria = categoria.id_categoria "
          "left join secao on categoria.id_secao = secao.id_secao "
          "left join departamento on secao.id_departamento = departamento.id_departamento "
          " where 1=1 ";
    QSqlQuery query;

    if (filtro->getFilial() > 0){
        sQuery += " and filial.id = :idFilial ";
        sQuery.replace(":idFilial", QString::number(filtro->getFilial()));
    }

    if (filtro->getDepartamento() > 0){
        sQuery += " and departamento.id_departamento = (:idDepartamento) ";
        sQuery.replace("(:idDepartamento)", QString::number(filtro->getDepartamento()));
    }

    if (filtro->getSecao() > 0){
        sQuery += " and secao.id_secao = (:idSecao) ";
        sQuery.replace("(:idSecao)", QString::number(filtro->getSecao()));
    }

    if (filtro->getCategoria() > 0){
        sQuery += " and categoria.id_categoria = (:idCategoria) ";
        sQuery.replace("(:idCategoria)", QString::number(filtro->getCategoria()));
    }
    if (filtro->getProduto() > 0){
        sQuery += " and produto.id_produto = (:idProduto) ";
        sQuery.replace("(:idProduto)", QString::number(filtro->getProduto()));
    }
    query.prepare(sQuery);
    query.exec();
    qDebug() << "Erro: " << query.lastError().text();
    qDebug() << "qyert: " << query.executedQuery();

    QList<Estoque*> estoques;
    while(query.next()){
        qDebug() << "id filial: " << query.value("id_filial").toLongLong() << endl;
        qDebug() << "descricao filial: " << query.value("descricao").toString() << endl;

        qDebug() << "id produto: " << query.value("id_produto").toLongLong() << endl;
        qDebug() << "descricao produto: " << query.value("produto").toString() << endl;

        qDebug() << "id categoria: " << query.value("id_categoria").toLongLong() << endl;
        qDebug() << "descricao categoria: " << query.value("categoria").toString() << endl;

        Estoque* estoque = new Estoque;

        Filial* filial = new Filial;
        filial->setIdFilial(query.value("id_filial").toLongLong());
        filial->setDescFilial(query.value("descricao").toString());

        estoque->setFilial(filial);

        Produto* produto = new Produto;
        produto->setIdProduto(query.value("id_produto").toLongLong());
        produto->setDescProduto(query.value("produto").toString());
        produto->setValorProduto(query.value("valor").toDouble());

        Categoria* categoria = new Categoria;
        categoria->setIdCategoria(query.value("id_categoria").toLongLong());
        categoria->setDescCategoria(query.value("categoria").toString());

        Secao* secao = new Secao;
        secao->setIdSecao(query.value("id_secao").toLongLong());
        secao->setDescSecao(query.value("secao").toString());

        Departamento* departamento = new Departamento;
        departamento->setIdDepartamento(query.value("id_departamento").toLongLong());
        departamento->setDescDepartamento(query.value("descricao").toString());

        produto->setCategoria(categoria);
        produto->setSecao(secao);
        produto->setDepartamento(departamento);

        estoque->setProduto(produto);
        estoque->setBasedoProduto(query.value("base").toDouble());

       estoques << estoque;
    }

    return estoques;
}
