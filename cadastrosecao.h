#ifndef CADASTROSECAO_H
#define CADASTROSECAO_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>


class CadastroSecao : public QObject
{
    Q_OBJECT
public:
    explicit CadastroSecao(QObject *parent = nullptr);
   // CadastroSecao();
    int getIdSecao() const;

    QString getDescricaoSecao() const;
    bool inserirDescricaoSecao(const QString &value);
    int BuscaIdPelaDescricaoDaSecao (const QString &RetornaIdPelaDescricaoDaSecao);

private:
    int idSecao;
    QString descricao;
    QString RetornaIdPelaDescricaoDaSecao;

};

#endif // CADASTROSECAO_H
