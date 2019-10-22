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

QList<Secao *> CadastroSecao::getInformacoesSecao()
{
    QList<Secao*> secoes;
    QSqlQuery query;
    //CadastroSecao* cadSecao = new CadastroSecao;
    query.prepare("select secao.id_secao,secao.secao, secao.id_departamento,"
                  "departamento.descricao from secao, departamento"
                  "where secao.id_departamento = departamento.id_departamento;");
    query.exec();
    while(query.next())
    {
        Secao* secao = new Secao;
        secao->setIdSecao(query.value("id_secao").toLongLong());
        secao->setDescSecao(query.value("secao").toString());
        secao->setIdDepartamento(query.value("id_departamento").toLongLong());
        secao->setDescDepartamento(query.value("descricao").toString());
        secoes << secao;
    }
    return secoes;
}

QString CadastroSecao::getDescricaoSecao(int id) const
{
    QSqlQuery query;
        query.prepare("SELECT secao FROM secao where id_secao = (:identificacao);"); //colocar id dps
        query.bindValue(":identificacao", id);
        query.exec();
        QString descricaoSecao;
        if (query.next()){
            descricaoSecao = query.value("secao").toString();
        }
        return descricaoSecao;
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

