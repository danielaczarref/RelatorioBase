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

//void CadastroCategoria::setDescricao(const QString &value)
//{
//    QSqlQuery query;
//    query.prepare("INSERT INTO categoria(categoria) values ('" + value + "');");
//    query.exec();
//    descricao = value;
//}

int CadastroCategoria::getIdCategoria() const
{
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
