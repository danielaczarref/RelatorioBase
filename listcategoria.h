#ifndef LISTCATEGORIA_H
#define LISTCATEGORIA_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class ListCategoria;
}

class ListCategoria : public QDialog
{
    Q_OBJECT

public:
    explicit ListCategoria(QWidget *parent = 0);
    ~ListCategoria();

    void clicouNoBotaoOk();
    void configuracaoInicial();
    void preencherRelatorioDeCategorias();
    void setConnects();
    QString getId();

private:
    Ui::ListCategoria *ui;

    QString _id;

private slots:
     void clicouProdutoSelecionado(QTableWidgetItem* item);
};

#endif // LISTCATEGORIA_H
