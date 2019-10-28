#include "cadastrosecao.h"
#include <QSqlQuery>
#include <QVariant>
#include "dominio/secao.h"
#include "listsecao.h"

CadastroSecao::CadastroSecao(QObject* parent) : QObject(parent)
{

}

int CadastroSecao::getIdSecao() const
{
    QSqlQuery query;
    query.prepare("SELECT id_secao FROM secao;");
    query.exec();
}

QList<Secao *> CadastroSecao::getInformacoesSecao()
{
    QList<Secao*> secoes;
    QSqlQuery query;
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
        query.prepare("SELECT secao FROM secao where id_secao = (:identificacao);");
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

bool CadastroSecao::verificaSeExiste(QString texto)
{
    QSqlQuery query;
    query.prepare("select id_secao, secao from secao "
                  "where cast(id_secao as varchar) like '%" + texto +"%' or secao like '%" + texto + "%';");
    query.exec();
    if (!query.next()){
        return false;
    } else {
        return true;
    }
}

