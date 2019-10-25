#include "negocio/cadastrocategoria.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

CadastroCategoria::CadastroCategoria(QObject* parent) : QObject(parent)
{

}

QString CadastroCategoria::getDescricaoCategoria(int id) const
{
    QSqlQuery query;
    query.prepare("SELECT categoria FROM categoria where id_categoria = (:identificacao);"); //id depois
    query.bindValue(":identificacao", id);
    query.exec();
    QString descricaoCategoria;
    if (query.next()){
        descricaoCategoria = query.value("categoria").toString();
    }
    return descricaoCategoria;
}

bool CadastroCategoria::salvarDescricaoCategoria(QString descricao)
{
    QSqlQuery query;
    query.prepare("INSERT INTO categoria(categoria) values ('" + descricao + "');");

    if(!query.exec())
        return false;

    return true;
}

QList<Categoria*> CadastroCategoria::getInformacoesCategoria()
{
    QList<Categoria*> categorias;
    QSqlQuery query;
    query.prepare("select categoria.id_categoria, categoria.categoria, "
                  "categoria.id_secao, secao.secao from categoria, "
                  "secao where categoria.id_secao = secao.id_secao;");
    query.exec();
    while(query.next())
    {
        Categoria* categoria = new Categoria;
        categoria->setIdCategoria(query.value("id_categoria").toLongLong());
        categoria->setDescCategoria(query.value("categoria").toString());
        categoria->setIdSecao(query.value("id_secao").toLongLong());
        categoria->setDescSecao(query.value("secao").toString());
        categorias << categoria;
    }
    return categorias;
}

bool CadastroCategoria::verificaSeExiste(QString texto)
{
    QSqlQuery query;
    query.prepare("select id_categoria, categoria from categoria "
                  "where cast(id_categoria as varchar) like '%" + texto +"%' or categoria like '%" + texto + "%';");
    query.exec();
    if (!query.next()){
        return false;
    } else {
        return true;
    }
}
int CadastroCategoria::getIdCategoria(int idProduto) const
{
    QSqlQuery query;
    query.prepare("SELECT categoria.id_categoria, produto.id_categoria FROM categoria, produto"
                  "where categoria.id_categoria = (:idproduto);");
    query.bindValue(":idproduto", idProduto);
    query.exec();
//                  "where categoria.id_categoria = produto.id_categoria;");
//    query.exec();
    int id;
    if (query.next()){
        id = query.value("id_categoria").toInt();
    }
    return id;
}

int CadastroCategoria::RetornaIdAtravesdaDescricao(const QString &UsadaParaBuscarIdPelaDescricao)
{
    QSqlQuery query;
    query.prepare("SELECT id_categoria FROM categoria WHERE categoria = '" + UsadaParaBuscarIdPelaDescricao + "';");
    query.exec();

    int id;
    if(query.next())
        id = query.value("id_categoria").toInt();

    return id;
}

//QString CadastroCategoria::getDescSecao() const
//{
//    QSqlQuery query;
//    query.prepare("SELECT secao FROM secao;");
//    query.exec();
//    QString descSecao;
//    while (query.next()){
//        Categoria* categoria = new Categoria;
//        descSecao = query.value("secao").toString();
//    }
//    //qDebug() << descSecao;
//    return descSecao;
//}



