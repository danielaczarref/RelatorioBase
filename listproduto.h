#ifndef LISTPRODUTO_H
#define LISTPRODUTO_H

#include <QDialog>
#include <QTableWidgetItem>
#include "dominio/produto.h"

namespace Ui {
class ListProduto;
}

class ListProduto : public QDialog
{
    Q_OBJECT

public:
    explicit ListProduto(QWidget *parent = 0);
    ~ListProduto();

    void configuracaoInicial();
    void preencherRelatorioProdutos();
    void setConnects();
    QString getId();

private:
    Ui::ListProduto *ui;
    QString _idProduto;

private slots:
    void clicouProdutoSelecionado(QTableWidgetItem* item);
};

#endif // LISTPRODUTO_H
