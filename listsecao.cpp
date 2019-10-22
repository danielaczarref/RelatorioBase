#include "listsecao.h"
#include "ui_listsecao.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "cadastrosecao.h"
#include "dominio/secao.h"

ListSecao::ListSecao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListSecao)
{
    ui->setupUi(this);
    QTableWidget* tableWidget = new QTableWidget;
    //tableWidget->show();

    QList<Secao*> listaSecoes;
    CadastroSecao* cadastroSecao = new CadastroSecao;

    listaSecoes = cadastroSecao->getInformacoesSecao();

    int linha = 0;

    foreach (Secao* secao, listaSecoes){
        ui->tableWidget->insertRow(linha);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString("%1").arg(secao->getIdSecao()));
        ui->tableWidget->setItem(linha, 0, item);

        item = new QTableWidgetItem;
        item->setText(secao->getDescSecao());
        ui->tableWidget->setItem(linha, 1, item);

        item = new QTableWidgetItem;
        item->setText(QString("%1").arg(secao->getIdDepartamento()));
        ui->tableWidget->setItem(linha, 2, item);

        item = new QTableWidgetItem;
        item->setText(secao->getDescDepartamento());
        ui->tableWidget->setItem(linha, 3, item);
        linha++;
    }
}

ListSecao::~ListSecao()
{
    delete ui;
}
