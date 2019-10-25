#include "listproduto.h"
#include "ui_listproduto.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "negocio/cadastroproduto.h"
#include "dominio/produto.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "dominio/estoque.h"
#include "dominio/filial.h"
#include <QDebug>

ListProduto::ListProduto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListProduto)
{
    ui->setupUi(this);
    configuracaoInicial();
}

ListProduto::~ListProduto()
{
    delete ui;
}

void ListProduto::configuracaoInicial()
{
    preencherRelatorioProdutos();
    setConnects();
}

void ListProduto::preencherRelatorioProdutos()
{
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
        item->setData(QTableWidgetItem::UserType, QVariant(QMetaType::QObjectStar, &produto));

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

        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();
    }
}

void ListProduto::setConnects()
{
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(clicouProdutoSelecionado(QTableWidgetItem*)));
}

QString ListProduto::getId()
{
    return _idProduto;
}

void ListProduto::clicouProdutoSelecionado(QTableWidgetItem *item)
{
    if(item == nullptr)
        return;

    qDebug() << item->row();

    QTableWidgetItem* itemId = ui->tableWidget->item(item->row(), 0);

    if(itemId == nullptr)
        return;

    _idProduto = itemId->text();

    qDebug() << "printando pra ver se chegou aqui" ;
    CadastroProduto* cadastroProduto;

    QVariant value = item->data(QTableWidgetItem::UserType);
    if (!value.isNull()){
        qDebug() << "entrou aqui johnnys";
        cadastroProduto = qobject_cast<CadastroProduto*>(qvariant_cast<QObject*>(value));
        if (cadastroProduto != nullptr) {
            qDebug() << "entrou aqui johnnys 2";

        }
    }

    this->accept();
}
