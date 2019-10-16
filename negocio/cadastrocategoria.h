#ifndef CADASTROCATEGORIA_H
#define CADASTROCATEGORIA_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>


class CadastroCategoria : public QObject
{
    Q_OBJECT
public:
    explicit CadastroCategoria(QObject *parent = nullptr);
    //CadastroCategoria();

    QString getDescricaoCategoria(int id) const;
//    void setDescricao(const QString &value);
    bool salvarDescricaoCategoria(QString descricao);

    int getIdCategoria() const;
    QSqlDatabase db;

    int RetornaIdAtravesdaDescricao (const QString &UsadaParaBuscarIdPelaDescricao);

private:
    int id;
    QString descricao;
    QString UsadaParaBuscarIdPelaDescricao;
};

#endif // CADASTROCATEGORIA_H
