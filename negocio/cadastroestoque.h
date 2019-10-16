#ifndef CADASTROESTOQUE_H
#define CADASTROESTOQUE_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>



class CadastroEstoque : public QObject
{
    Q_OBJECT
public:
    explicit CadastroEstoque(QObject *parent = nullptr);
    //CadastroEstoque();

    int getIdProdutoEstoque() const;
    int getIdFilialEstoque() const;
    QString getBasedoProdutoEstoque(QString descProduto, QString descFilial) const;
    bool defineBasedoProdutoEstoque(double value);
    QSqlDatabase db;

private:
    int idProduto;
    int idFilial;
    double base;
};

#endif // CADASTROESTOQUE_H
