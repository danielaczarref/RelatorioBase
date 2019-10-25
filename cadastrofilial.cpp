#include "cadastrofilial.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "listfilial.h"
#include "dominio/filial.h"

CadastroFilial::CadastroFilial(QObject* parent) : QObject(parent)
{

}

QString CadastroFilial::getDescricaoFilial(int identificacao) const
{
    QSqlQuery query;
    query.prepare("SELECT descricao FROM filial where id = (:identificacao);"); //colocar id dps
    query.bindValue(":identificacao", identificacao);
    query.exec();
    QString descricaoFilial;
    if (query.next()){
        descricaoFilial = query.value("descricao").toString();
    }
    return descricaoFilial;
}

void CadastroFilial::inserirDescricaoFilial(const QString &value)
{
    QSqlQuery query;
    query.prepare("INSERT INTO filial(descricao) values ('" + value + "');");
    query.exec();
    descricao = value;
}

int CadastroFilial::getIdFilial() const
{
    return id;
}

QList<Filial*> CadastroFilial::getInformacoesFilial()
{
    QList<Filial*> filiais;
    QSqlQuery query;
    query.prepare("select id,descricao from filial;");
    query.exec();
    while(query.next())
    {
        Filial* filial = new Filial;
        filial->setIdFilial(query.value("id").toLongLong());
        filial->setDescFilial(query.value("descricao").toString());
        filiais << filial;
    }
    return filiais;
}

QList<QString> CadastroFilial::leDescricaoFilial()
{
    QList<QString> descricao;
    QSqlQuery query;
    query.prepare("select descricao from filial;");
    query.exec();
    while (query.next()){
        descricao << query.value("descricao").toString();
    }
    return descricao;
}

int CadastroFilial::RetornaIdDaFilial(const QString &BuscaIdDaFilialPelaDescricao)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM filial WHERE descricao = '" + BuscaIdDaFilialPelaDescricao + "';" );
    query.exec();
    int id;

    if(query.next()){
        id = query.value("id").toInt();
    }

    return id;
}

bool CadastroFilial::verificaSeExiste(QString texto)
{
    QSqlQuery query;
    query.prepare("select id, descricao from filial "
                  "where cast(id as varchar) like '%" + texto +"%' or descricao like '%" + texto + "%';");
    query.exec();
    if (!query.next()){
        return false;
    } else {
        return true;
    }
}


