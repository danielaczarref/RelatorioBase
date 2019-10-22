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

const int COLUNA_ID = 0;

Relatorio::Relatorio(QWidget *parent) : QWidget(parent),    ui(new Ui::Relatorio)
{
    ui->setupUi(this);
    configuracaoInicial();
    ui->pbVoltar->setVisible(false);

    QTableWidget* tableWidget = new QTableWidget;

    QList<Estoque*> listaEstoque;
    CadastroEstoque* cadastroEstoque = new CadastroEstoque;

    //listaEstoque = cadastroEstoque->getInformacoesEstoque();

    int linha = 0;

    foreach (Estoque* estoque, listaEstoque){
        ui->tableWidget->insertRow(linha);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString("%1").arg(estoque->getFilial()->getIdFilial()));
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
        item->setText(QString("%1").arg(estoque->getCategoria()->getIdCategoria()));
        ui->tableWidget->setItem(linha, 6, item);

        item = new QTableWidgetItem;
        item->setText(estoque->getCategoria()->getDescCategoria());
        ui->tableWidget->setItem(linha, 7, item);

        linha++;
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();

}

Relatorio::~Relatorio()
{
    delete ui;
}

void Relatorio::onCadastrarProdutoClicked()
{
    //ui->stCadastro->setCurrentIndex(0);
    ui->pbVoltar->setVisible(false);


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
//    QList<CadastroBase*> list;

//    CadastroBase* cad1 = new CadastroBase;

////    QString a = cad1->categoria();
//    cad1->setCategoria("Cad1");
//    cad1->setProduto("Prod1");
//    cad1->setBase("1");

//    list << cad1;

//    CadastroBase* cad2 = new CadastroBase;
//    cad2->setCategoria("Cad2");
//    cad2->setProduto("Prod2");
//    cad2->setBase("2");

//    list << cad2;

//    CadastroBase* cad3 = new CadastroBase;
//    cad3->setCategoria("Cad3");
//    cad3->setProduto("Prod3");
//    cad3->setBase("3");

//    list << cad3;

//    int linha=0;
//    foreach (CadastroBase* cad, list) {
//        ui->tableWidget->insertRow(linha);

//        QTableWidgetItem* item = new QTableWidgetItem;
//        item->setText(cad->categoria());
//        ui->tableWidget->setItem(linha, 0, item);
//        QTableWidgetItem* item1 = new QTableWidgetItem;
//        item1->setText(cad->produto());
//        ui->tableWidget->setItem(linha,1,item1);
//        QTableWidgetItem* item2 = new QTableWidgetItem;
//        item2->setText(cad->base() + "%");
//        ui->tableWidget->setItem(linha, 2, item2);

//        linha++;
//    }

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
     montarTw();
}

void Relatorio::setConnects()
{
    connect(ui->pbCadastrar, SIGNAL(clicked()), this, SLOT(onCadastrarProdutoClicked()));
    connect(ui->pbFiltrar, SIGNAL(clicked()), this, SLOT(onFiltrarClicked()));
    connect(ui->pbVoltar, SIGNAL(clicked()), this, SLOT(onVoltarClicked()));

}
