#include "listproduto.h"
#include "ui_listproduto.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "negocio/cadastroproduto.h"
#include "dominio/produto.h"

ListProduto::ListProduto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListProduto)
{
    ui->setupUi(this);
    QTableWidget* tableWidget = new QTableWidget;
   // tableWidget->show();

    QList<Produto*> listaProdutos;
    CadastroProduto* cadastroProduto = new CadastroProduto;

    listaProdutos = cadastroProduto->getInformacoesProduto();

    int linha = 0;

    foreach (Produto* produto, listaProdutos){
        ui->tableWidget->insertRow(linha);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString("%1").arg(produto->getIdProduto()));
        ui->tableWidget->setItem(linha, 0, item);

        item = new QTableWidgetItem;
        item->setText(produto->getDescProduto());
        ui->tableWidget->setItem(linha, 1, item);

        item = new QTableWidgetItem;
        item->setText("R$ " +QString("%1").arg(produto->getValorProduto()));
        ui->tableWidget->setItem(linha, 2, item);

        item = new QTableWidgetItem;
        item->setText(QString("%1").arg(produto->getCategoria()->getIdCategoria()));
        ui->tableWidget->setItem(linha, 3, item);

        item = new QTableWidgetItem;
        item->setText(produto->getCategoria()->getDescCategoria());
        ui->tableWidget->setItem(linha, 4, item);
        linha++;
    }
}

ListProduto::~ListProduto()
{
    delete ui;
}
