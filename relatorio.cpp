#include "relatorio.h"
#include "ui_relatorio.h"
#include <qdebug.h>
#include <cadastro.h>
#include "QTableWidgetItem"
#include "cadastrobase.h"

const int COLUNA_ID = 0;

Relatorio::Relatorio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Relatorio)
{
    ui->setupUi(this);
    configuracaoInicial();

}

Relatorio::~Relatorio()
{
    delete ui;
}

void Relatorio::onEditarClicked()
{
    ui->stCadastro->setCurrentIndex(1);
    ui->pbLimpar->setVisible(false);

    qDebug() << "Log: usuário editou pesquisa de relatório";

}

void Relatorio::onFiltrarClicked()
{
    ui->stCadastro->setCurrentIndex(0);
    qDebug() << "Log: usuário filtrou pesquisa de relatório";
}

void Relatorio::onLimparClicked()
{
    qDebug() << "Log: usuário limpou pesquisa de relatório";
}

void Relatorio::montarTw()
{
    QList<CadastroBase*> list;

    CadastroBase* cad1 = new CadastroBase;

//    QString a = cad1->categoria();
    cad1->setCategoria("Cad1");
    cad1->setProduto("Prod1");
    cad1->setBase("1");

    list << cad1;

    CadastroBase* cad2 = new CadastroBase;
    cad2->setCategoria("Cad2");
    cad2->setProduto("Prod2");
    cad2->setBase("2");

    list << cad2;

    CadastroBase* cad3 = new CadastroBase;
    cad3->setCategoria("Cad3");
    cad3->setProduto("Prod3");
    cad3->setBase("3");

    list << cad3;

    int linha=0;
    foreach (CadastroBase* cad, list) {
        ui->tableWidget->insertRow(linha);

        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(cad->categoria());
        ui->tableWidget->setItem(linha, 0, item);
        QTableWidgetItem* item1 = new QTableWidgetItem;
        item1->setText(cad->produto());
        ui->tableWidget->setItem(linha,1,item1);
        QTableWidgetItem* item2 = new QTableWidgetItem;
        item2->setText(cad->base() + "%");
        ui->tableWidget->setItem(linha, 2, item2);

        linha++;
    }

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
    connect(ui->pbCadastrar, SIGNAL(clicked()), this, SLOT(onEditarClicked()));
    connect(ui->pbFiltrar, SIGNAL(clicked()), this, SLOT(onFiltrarClicked()));
    connect(ui->pbLimpar, SIGNAL(clicked()), this, SLOT(onLimparClicked()));

}
