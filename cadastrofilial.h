#ifndef CADASTROFILIAL_H
#define CADASTROFILIAL_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QList>
#include "listfilial.h"
#include "dominio/filial.h"

class CadastroFilial : public QObject
{
    Q_OBJECT
public:
    explicit CadastroFilial(QObject *parent = nullptr);
    //CadastroFilial();
    //long long id() const;
    QString getDescricaoFilial(int identificacao) const;
    void inserirDescricaoFilial(const QString &value);
    int getIdFilial() const;
    QList<Filial*> getInformacoesFilial();
    QList<QString> leDescricaoFilial();
    int RetornaIdDaFilial(const QString &BuscaIdDaFilialPelaDescricao);
    bool verificaSeExiste(QString texto);

    QSqlDatabase db;

private:
    //long long _id;
    //QList<long long> leRespostas();
    QString descricao;
    QString BuscaIdDaFilialPelaDescricao;
    int id;
};

#endif // CADASTROFILIAL_H
