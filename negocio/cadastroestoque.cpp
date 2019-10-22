#include "negocio/cadastroestoque.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "cadastro.h"
#include "cadastrofilial.h"
#include "negocio/cadastroproduto.h"
#include <stdio.h>
#include <string.h>
#include "negocio/cadastrocategoria.h"
#include "dao/estoquedao.h"
#include <QDebug>

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

QList<Estoque *> CadastroEstoque::getInformacoesEstoque(QString sfilial, QString sproduto)
{
    //QRegExp rx("(\\ |\\,|\\.|\\-|\\t)");

    QStringList listFilial = sfilial.split("-");
    QStringList listProduto = sproduto.split("-");
    QString IdFilial, IdProduto;

    int sizeFilialList = listFilial.length();
    int sizeProdutoList = listProduto.length();

    for (int i = 0; i < sizeFilialList; i++) {
        IdFilial = listFilial.at(0);
    }

    for (int i=0; i < sizeProdutoList; i++){
        IdProduto = listProduto.at(0);
    }

    int iFilial = IdFilial.toInt();
    int iProduto = IdProduto.toInt();

    CadastroFilial* cadF = new CadastroFilial;
    QString descFilial = cadF->getDescricaoFilial(iFilial);
    int identificaFilial = cadF->RetornaIdDaFilial(descFilial);

    CadastroProduto* cadP = new CadastroProduto;
    QString descProd = cadP->getDescricaoProduto(iProduto);
    int identificaProduto = cadP->RetornaIdDoProdutoPelaDescricao(descProd);
    double valorProduto = cadP->getValorProduto(identificaProduto);

    CadastroCategoria* cadCat = new CadastroCategoria;
    int idCategoria = cadCat->getIdCategoria(identificaProduto);
    QString descCategoria = cadCat->getDescricaoCategoria(idCategoria);

    double baseProduto = this->getBasedoProdutoEstoque(identificaProduto, identificaFilial);

    QList<Estoque*> dadosEstoque;
    Filial* filial = new Filial;
    filial->setIdFilial((long long) identificaFilial);
    filial->setDescFilial(descFilial);

    Produto* produto = new Produto;
    produto->setIdProduto((long long) identificaProduto);
    produto->setDescProduto(descProd);
    produto->setValorProduto(valorProduto);

    Estoque* estoque = new Estoque;
    estoque->setBasedoProduto(baseProduto);

    Categoria* categoria = new Categoria;
    categoria->setIdCategoria((long long) idCategoria);
    categoria->setDescCategoria(descCategoria);

    estoque->setFilial(filial);
    estoque->setProduto(produto);
    estoque->setCategoria(categoria);
    //categoria->setDescCategoria(query.value("categoria").toString());
    dadosEstoque << estoque;

    return dadosEstoque;
}

int CadastroEstoque::getIdFilialEstoque() const
{
    QSqlQuery query;
    query.prepare("SELECT id_filial FROM estoque");
    query.exec();
    return idFilial;
}

double CadastroEstoque::getBasedoProdutoEstoque(int idProduto, int idFilial) const
{
    QSqlQuery query;
    query.prepare("select base from estoque where id_produto = (:idProduto) and id_filial = (:idFilial);");
    query.bindValue(":idProduto", idProduto);
    query.bindValue(":idFilial", idFilial);
   // query.prepare("SELECT base FROM estoque where id_produto = (select id_produto from produto where produto = '" + descProduto + "') and id_filial = (select id from filial where descricao = '" + descFilial + "');");
    query.exec();

    double base;
    if(query.next())
        base = query.value("base").toDouble();
    return base;
}

QList<Estoque *> CadastroEstoque::recuperarEstoques(Filtro* filtro)
{
    long long sfilial = filtro->getFilial();
    int sproduto = filtro->getProduto();
    qDebug() << "string filial: " << sfilial << endl;
    qDebug() << "string produto: " << sproduto << endl;

//    QStringList listFilial = sfilial.split(" - ");
//    QStringList listProduto = sproduto.split(" - ");
//    QString IdFilial, IdProduto;

//    int sizeFilialList = listFilial.length();
//    int sizeProdutoList = listProduto.length();

//    for (int i = 0; i < sizeFilialList; i++) {
//        IdFilial = listFilial.at(0);
//    }

//    qDebug() << "id filial, primeira posição:" << IdFilial << endl;

//    for (int i=0; i < sizeProdutoList; i++){
//        IdProduto = listProduto.at(0);
//    }

//    qDebug() << "id produto, primeira posição:" << IdProduto << endl;


    long long iFilial = sfilial;
    long long iProduto = sproduto;

    qDebug() << "id filial eh: " << iFilial << endl;
    qDebug() << "id produto eh: " << iProduto << endl;

//    if(idFilial <= 0)
//        erro aqui

    EstoqueDAO estoqueDAO;
    QList<Estoque *> list = estoqueDAO.recuperEstoque(filtro);

    return list;
}
