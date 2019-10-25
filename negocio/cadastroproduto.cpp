#include "negocio/cadastroproduto.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

CadastroProduto::CadastroProduto(QObject* parent) : QObject(parent)
{

}

int CadastroProduto::getIdProduto() const
{
    return id;
}

QString CadastroProduto::getDescricaoProduto(int id) const
{
    QSqlQuery query;
    query.prepare("SELECT produto FROM produto where id_produto = (:identificacao);"); //lidar com id depois
    query.bindValue(":identificacao", id);
    query.exec();
    QString descricaoProduto;
    if (query.next()){
        descricaoProduto = query.value("produto").toString();
    }
    return descricaoProduto;
}

bool CadastroProduto::inserirDescricaoProduto(const QString &value)
{
    QSqlQuery query;
    query.prepare("INSERT INTO produto(produto) values ('" + value + "');");
    if (!query.exec()){
        return false;
    } else {
        return true;
    }
    //descricao = value;
}

QList<Produto *> CadastroProduto::getInformacoesProduto()
{
    QList<Produto*> produtos;
    QSqlQuery query;
    query.prepare("select produto.id_produto, produto.produto, produto.valor,"
                  " produto.id_categoria, categoria.categoria "
                  "from produto, categoria "
                  "where produto.id_categoria = categoria.id_categoria;");
    query.exec();
    while(query.next())
    {
        Produto* produto = new Produto;
        produto->setIdProduto(query.value("id_produto").toLongLong());
        produto->setDescProduto(query.value("produto").toString());
        produto->setValorProduto(query.value("valor").toDouble());

        Categoria* categoria = new Categoria;
        categoria->setIdCategoria(query.value("id_categoria").toLongLong());
        categoria->setDescCategoria(query.value("categoria").toString());

        produto->setCategoria(categoria);

//        produto->setCategoria(categoria);

        produtos << produto;
    }


//    foreach (Produto* prod, produtos) {
//        qDebug() << prod->getCategoria()->idCategoria();
//    }

    return produtos;
}

bool CadastroProduto::verificaSeExiste(QString texto)
{
    QSqlQuery query;
    query.prepare("select id_produto, produto from produto "
                  "where cast(id_produto as varchar) like '%" + texto +"%' or produto like '%" + texto + "%';");
    query.exec();
    if (!query.next()){
        return false;
    } else {
        return true;
    }
}

double CadastroProduto::getValorProduto(int idProduto) const
{
    QSqlQuery query;
    query.prepare("SELECT valor FROM produto where id_produto = (:idProduto);");
    query.bindValue(":idProduto", idProduto);
    query.exec();

    double valor;
    if(query.next())
        valor = query.value("valor").toDouble();

    return valor;
    //return valor;
}

bool CadastroProduto::defineValorProduto(double preco)
{
    QSqlQuery query;
    query.prepare("INSERT INTO produto(valor) values (:preco);");
    query.bindValue(":preco", preco);
    query.exec();

    if (!query.exec()){
        return false;
    }
    return true;
//    double valor = preco.toDouble();
//    QSqlQuery query;
//    query.prepare("INSERT INTO produto(valor) values (:preco);");
//    query.bindValue(":preco",valor);
//    //query.exec();
//    if (!query.exec()){
//        return false;
//    } else {
//        return true;
//    }
    return true;
}

int CadastroProduto::RetornaIdDoProdutoPelaDescricao(const QString &UsadaParaBuscarIdDoProduto)
{
    QSqlQuery query;
    query.prepare("SELECT id_produto FROM produto where produto = '" + UsadaParaBuscarIdDoProduto + "';");
    query.exec();
    int id;
    if(query.next())
        id = query.value("id_produto").toInt();

    return id;
}
