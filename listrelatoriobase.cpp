#include "listrelatoriobase.h"
#include "ui_listrelatoriobase.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "negocio/cadastroestoque.h"
#include "dominio/estoque.h"
#include "cadastro.h"
#include <QDebug>

ListRelatorioBase::ListRelatorioBase(Filtro* filtro,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListRelatorioBase)
{
    ui->setupUi(this);
    QTableWidget* tableWidget = new QTableWidget;

    QList<Estoque*> listaEstoque;
    CadastroEstoque* cadastroEstoque = new CadastroEstoque;

    listaEstoque = cadastroEstoque->recuperarEstoques(filtro);

    int linha = 0;

    foreach (Estoque* estoque, listaEstoque){
        ui->tableWidget->insertRow(linha);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString("%1").arg(estoque->getFilial()->getIdFilial()));
        qDebug() << "print id filial: " << item;
        ui->tableWidget->setItem(linha, 0, item);

        item = new QTableWidgetItem;
        item->setText(estoque->getFilial()->getDescFilial());
        ui->tableWidget->setItem(linha, 1, item);

        item = new QTableWidgetItem;
        item->setText(QString("%1").arg(estoque->getProduto()->getIdProduto()));
        ui->tableWidget->setItem(linha, 2, item);

        item = new QTableWidgetItem;
        item->setText(estoque->getProduto()->getDescProduto());
        ui->tableWidget->setItem(linha, 3, item);

        item = new QTableWidgetItem;
        item->setText("R$ " + QString("%1").arg(estoque->getProduto()->getValorProduto()));
        ui->tableWidget->setItem(linha, 4, item);

        item = new QTableWidgetItem;
        item->setText(QString("%1").arg(estoque->getBasedoProduto()) + " %");
        ui->tableWidget->setItem(linha, 5, item);

        item = new QTableWidgetItem;
        item->setText(QString("%1").arg(estoque->getProduto()->getCategoria()->getIdCategoria()));
        ui->tableWidget->setItem(linha, 6, item);

        item = new QTableWidgetItem;
        item->setText(estoque->getProduto()->getCategoria()->getDescCategoria());
        ui->tableWidget->setItem(linha, 7, item);

        item = new QTableWidgetItem;
        item->setText(QString("%1").arg(estoque->getProduto()->getSecao()->getIdSecao()));
        ui->tableWidget->setItem(linha, 8, item);

        item = new QTableWidgetItem;
        item->setText(estoque->getProduto()->getSecao()->getDescSecao());
        ui->tableWidget->setItem(linha, 9, item);

        item = new QTableWidgetItem;
        item->setText(QString("%1").arg(estoque->getProduto()->getDepartamento()->getIdDepartamento()));
        ui->tableWidget->setItem(linha, 10, item);

        item = new QTableWidgetItem;
        item->setText(estoque->getProduto()->getDepartamento()->getDescDepartamento());
        ui->tableWidget->setItem(linha, 11, item);

        linha++;
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

ListRelatorioBase::~ListRelatorioBase()
{
    delete ui;
}
