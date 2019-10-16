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

private slots:
    void onbtFilialclicked();
    void onbtDepartamentoclicked();
    void onbtCategoriaclicked();
    void onbtProdutoclicked();
    void onbtBaseclicked();
    void onbtSalvarclicked();
    void onbtLimparclicked();
    void onlnFilialinformed();
    void onlnDepartamentoinformed();
    void onlnCategoriainformed();
    void onlnProdutoinformed();
    void chamaBase();
    void onlnBaseinformed();
    bool validaString(QString s);
//    bool validaDouble (QString s);
    bool VerificaSeENumero (QString s);

private:
    Ui::Cadastro *ui;
    void configuracaoInicial();

    void setConnects();
};

#endif // CADASTRO_H
