#include "cadastrodepartamento.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

CadastroDepartamento::CadastroDepartamento(QObject* parent) : QObject(parent)
{

}

int CadastroDepartamento::getIdDepartamento() const
{
    return id;
}

QString CadastroDepartamento::getDescricaoDepartamento(int id) const
{
    QSqlQuery query;
    query.prepare("SELECT descricao FROM departamento where id_departamento = (:identificacao);"); //colocar id dps
    query.bindValue(":identificacao", id);
    query.exec();
    QString descricaoDepartamento;
    if (query.next()){
        descricaoDepartamento = query.value("descricao").toString();
    }
    return descricaoDepartamento;
}

bool CadastroDepartamento::defineDescricaoDepartamento(const QString &value)
{
    QSqlQuery query;
    query.prepare("INSERT INTO departamento(descricao) values ('" + value + "');");
    if (!query.exec()){
        return false;
    } else {
        return true;
    }
    // descricao = value;
}

int CadastroDepartamento::buscaIdDoDepartamento(const QString &StringParaBuscarIdDepartamento)
{
    QSqlQuery query;
    query.prepare("SELECT id_departamento FROM departamento WHERE descricao =  '" + StringParaBuscarIdDepartamento + "';");
    query.exec();
    int id;
    if(query.next())
        id = query.value("id_departamento").toInt();

    return id;
}

bool CadastroDepartamento::verificaSeExiste(QString texto)
{
    QSqlQuery query;
    query.prepare("select id_departamento, descricao from departamento "
                  "where cast(id_departamento as varchar) like '%" + texto +"%' or descricao like '%" + texto + "%';");
    query.exec();
    if (!query.next()){
        return false;
    } else {
        return true;
    }
}

QList<Departamento *> CadastroDepartamento::getInformacoesDepartamento()
{
    QList<Departamento*> departamentos;
    QSqlQuery query;
    query.prepare("select id_departamento,descricao from departamento;");
    query.exec();
    while(query.next())
    {
        Departamento* departamento = new Departamento;
        departamento->setIdDepartamento(query.value("id_departamento").toLongLong());
        departamento->setDescDepartamento(query.value("descricao").toString());
        departamentos << departamento;
    }
    return departamentos;
}
