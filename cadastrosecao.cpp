#include "cadastrosecao.h"
#include <QSqlQuery>
#include <QVariant>

CadastroSecao::CadastroSecao(QObject* parent) : QObject(parent)
{

}

int CadastroSecao::getIdSecao() const
{
    QSqlQuery query;
    query.prepare("SELECT id_secao FROM secao;"); //resolver id depois;
    query.exec();
   // return idSecao;
}

QString CadastroSecao::getDescricaoSecao() const
{
    QSqlQuery query;
    query.prepare("SELECT secao FROM secao;"); //resolver id depois
    query.exec();
    //return descricao;
}

bool CadastroSecao::inserirDescricaoSecao(const QString &value)
{
    QSqlQuery query;
    query.prepare("INSERT INTO secao(secao) VALUES ('" + value + "');");
    if (!query.exec()){
        return false;
    } else {
        return true;
    }
}

int CadastroSecao::BuscaIdPelaDescricaoDaSecao(const QString &RetornaIdPelaDescricaoDaSecao)
{
    QSqlQuery query;
    query.prepare("SELECT id_secao FROM secao WHERE secao = '" + RetornaIdPelaDescricaoDaSecao + "';" );
    query.exec();

    int id;
    if(query.next())
        id = query.value("id_secao").toInt();

    return id;
}
