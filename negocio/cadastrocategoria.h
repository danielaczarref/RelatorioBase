#ifndef CADASTROCATEGORIA_H
#define CADASTROCATEGORIA_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include "dominio/categoria.h"


class CadastroCategoria : public QObject
{
    Q_OBJECT
public:
    explicit CadastroCategoria(QObject *parent = nullptr);
    //CadastroCategoria();

    QString getDescricaoCategoria(int id) const;
//    void setDescricao(const QString &value);
    bool salvarDescricaoCategoria(QString descricao);
    QList<Categoria*> getInformacoesCategoria();
    bool verificaSeExiste(QString texto);


    int getIdCategoria(int idProduto) const;
    QSqlDatabase db;

    int RetornaIdAtravesdaDescricao (const QString &UsadaParaBuscarIdPelaDescricao);

    QString getDescSecao() const;

private:
    int id;
    QString descricao;
    QString UsadaParaBuscarIdPelaDescricao;
    QString descSecao;
};

#endif // CADASTROCATEGORIA_H
