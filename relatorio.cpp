#include "relatorio.h"
#include "ui_relatorio.h"
#include <qdebug.h>
#include <cadastro.h>
#include "QTableWidgetItem"
#include "cadastrobase.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "negocio/cadastroestoque.h"
#include "dominio/estoque.h"
#include "negocio/filtro.h"
#include "cadastroparacada.h"

const int COLUNA_ID = 0;

Relatorio::Relatorio(QWidget *parent) : QWidget(parent),    ui(new Ui::Relatorio)
{
    ui->setupUi(this);
    configuracaoInicial();
    ui->pbVoltar->setVisible(false);

}


Relatorio::~Relatorio()
{
    delete ui;
}

void Relatorio::preencherRelatorio(Filtro *filtro)
{
    filtroCorreto = filtro;

    QList<Estoque*> listaEstoque;
    CadastroEstoque* cadastroEstoque = new CadastroEstoque;

    listaEstoque = cadastroEstoque->recuperarEstoques(filtroCorreto);

    int linha = 0;

    foreach (Estoque* estoque, listaEstoque)
    {
        ui->tableWidget->insertRow(linha);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString("%1").arg(estoque->getFilial()->getIdFilial()));
        qDebug() << "print id filial: " << item;
        ui->tableWidget->setItem(linha, 0, item);

        item = new QTableWidgetItem;
        item->setText(estoque->getFilial()->getDescFilial());
        item->setData(QTableWidgetItem::UserType, QVariant(QMetaType::QObjectStar, &estoque));
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

void Relatorio::onCadastrarProdutoClicked()
{
    CadastroParaCada* cad = new CadastroParaCada;
    ui->pbVoltar->setVisible(true);
    ui->stCadastro->setCurrentIndex(2);
    qDebug() << "Log: usuário editou pesquisa de relatório";
}

void Relatorio::onFiltrarClicked()
{
    ui->stCadastro->setCurrentIndex(1);
    ui->pbVoltar->setVisible(true);

    qDebug() << "Log: usuário filtrou pesquisa de relatório";
}

void Relatorio::montarTw()
{
}

void Relatorio::onVoltarClicked()
{
    ui->stCadastro->setCurrentIndex(0);
    ui->pbVoltar->setVisible(false);

}


void Relatorio::configuracaoInicial()
{
     setConnects();
     Cadastro* cadastro = new Cadastro();
     ui->stCadastro->addWidget(cadastro);
     CadastroParaCada* cad = new CadastroParaCada;
     ui->stCadastro->addWidget(cad);

     montarTw();
}

void Relatorio::setConnects()
{
    connect(ui->pbCadastrar, SIGNAL(clicked()), this, SLOT(onCadastrarProdutoClicked()));
    connect(ui->pbFiltrar, SIGNAL(clicked()), this, SLOT(onFiltrarClicked()));
    connect(ui->pbVoltar, SIGNAL(clicked()), this, SLOT(onVoltarClicked()));
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(clicouProdutoSelecionado(QTableWidgetItem*)));


}

void Relatorio::clicouProdutoSelecionado(QTableWidgetItem *item)
{
    qDebug() << "printando pra ver se chegou aqui" ;
    Estoque* estoque;

    QVariant value = item->data(QTableWidgetItem::UserType);
    if (!value.isNull())
        estoque = qobject_cast<Estoque*>(qvariant_cast<QObject*>(value));

    qDebug() << "print daniel: " << estoque->getFilial()->getDescFilial();
}
