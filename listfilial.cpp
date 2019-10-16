#include "listfilial.h"
#include "ui_listfilial.h"
#include <QTableWidget>
#include "cadastrofilial.h"
#include <QTableWidgetItem>
#include "dominio/filial.h"

ListFilial::ListFilial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListFilial)
{
    ui->setupUi(this);
    QTableWidget* tableWidget = new QTableWidget;
   // tableWidget->setItem(0, 1, new QTableWidgetItem("Hello"));
    //tableWidget->setModel(model);
    tableWidget->show();

    QList<Filial*> listaFiliais;
    CadastroFilial* cadastroFilial = new CadastroFilial;
    listaFiliais = cadastroFilial->getInformacoesFilial();

    int linha = 0;

    foreach (Filial* filial, listaFiliais){
        ui->tableWidget->insertRow(linha);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString("%1").arg(filial->getIdFilial()));
        ui->tableWidget->setItem(linha, 0, item);

        item = new QTableWidgetItem;
        item->setText(filial->getDescFilial());
        ui->tableWidget->setItem(linha, 1, item);
        linha++;
    }



//    int linha = 0;
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

ListFilial::~ListFilial()
{
    delete ui;
}
