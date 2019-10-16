#ifndef CADASTROPRODUTO_H
#define CADASTROPRODUTO_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>


class CadastroProduto : public QObject
{
    Q_OBJECT
public:
    explicit CadastroProduto(QObject *parent = nullptr);
    //CadastroProduto();
    int getIdProduto() const;

    QString getDescricaoProduto(int id) const;
    bool inserirDescricaoProduto(const QString &value);

    QSqlDatabase db;

    double getValorProduto() const;
    bool defineValorProduto(QString preco);

    int RetornaIdDoProdutoPelaDescricao (const QString &UsadaParaBuscarIdDoProduto);

private:
    int id;
    QString descricao;
    QString preco;
    QString UsadaParaBuscarIdDoProduto;

};

#endif // CADASTROPRODUTO_H
