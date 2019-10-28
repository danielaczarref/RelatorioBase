#ifndef CADASTROSECAO_H
#define CADASTROSECAO_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QList>
#include "listsecao.h"
#include "dominio/secao.h"


class CadastroSecao : public QObject
{
    Q_OBJECT
public:
    explicit CadastroSecao(QObject *parent = nullptr);
   // CadastroSecao();
    int getIdSecao() const;
    QList<Secao*> getInformacoesSecao();

    QString getDescricaoSecao(int id) const;
    bool inserirDescricaoSecao(const QString &value);
    int BuscaIdPelaDescricaoDaSecao (const QString &RetornaIdPelaDescricaoDaSecao);
    bool verificaSeExiste(QString texto);

    QList<QString> getDescDepartamento() const;

private:
    int idSecao;
    QString descricao;
    QString RetornaIdPelaDescricaoDaSecao;
    QList<QString> descDepartamento;

};

#endif // CADASTROSECAO_H
