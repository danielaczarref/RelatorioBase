#ifndef CADASTRODEPARTAMENTO_H
#define CADASTRODEPARTAMENTO_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include "dominio/departamento.h"

class CadastroDepartamento : public QObject
{
    Q_OBJECT
public:
    explicit CadastroDepartamento(QObject *parent = nullptr);
    //CadastroDepartamento();

    int getIdDepartamento() const;

    QString getDescricaoDepartamento(int id) const;
    bool defineDescricaoDepartamento(const QString &value);
    int buscaIdDoDepartamento (const QString &StringParaBuscarIdDepartamento);

    QList<Departamento*> getInformacoesDepartamento();

    QSqlDatabase db;


private:
    int id;
    QString descricao;
    QString StringParaBuscarIdDepartamento;
};

#endif // CADASTRODEPARTAMENTO_H
