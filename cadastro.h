#ifndef CADASTRO_H
#define CADASTRO_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Cadastro;
}

class Cadastro : public QWidget
{
    Q_OBJECT

public:
    explicit Cadastro(QWidget *parent = 0);
    ~Cadastro();
    QSqlDatabase db;


    int idFilial       = 0;
    int idDepartamento = 0;
    int idSecao        = 0;
    int idCategoria    = 0;
    int idProduto      = 0;

    QString getRetornalnFilial() const;

    QString getRetornalnProduto() const;

private slots:
    void onbtFilialclicked();
    void onbtDepartamentoclicked();
    void onbtCategoriaclicked();
    void onbtProdutoclicked();
    void onbtSalvarclicked();
    void onbtLimparclicked();
    void onlnFilialinformed();
    void onlnDepartamentoinformed();
    void onlnCategoriainformed();
    void onlnProdutoinformed();
    bool validaString(QString s);
//    bool validaDouble (QString s);
    bool VerificaSeENumero (QString s);
    bool verificaCampos();

    void onlnSecaoInformed();

    bool isFilialEmpty();
    bool isDepartamentoEmpty();
    bool isSecaoEmpty();
    bool isCategoriaEmpty();
    bool isProdutoEmpty();


private:
    Ui::Cadastro *ui;
    void configuracaoInicial();
    QString RetornalnFilial;
    QString RetornalnProduto;

    void setConnects();

};

#endif // CADASTRO_H
