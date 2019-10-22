#include "listcategoria.h"
#include "ui_listcategoria.h"
#include "dominio/categoria.h"
#include "negocio/cadastrocategoria.h"
#include <QTableWidget>
#include <QTableWidgetItem>

ListCategoria::ListCategoria(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListCategoria)
{
    ui->setupUi(this);
    QTableWidget* tableWidget = new QTableWidget;
    //tableWidget->show();

    QList<Categoria*> listaCategoria;
    CadastroCategoria* cadastroCategoria = new CadastroCategoria;
    listaCategoria = cadastroCategoria->getInformacoesCategoria();

    int linha = 0;

    foreach (Categoria* categoria, listaCategoria){
        ui->tableWidget->insertRow(linha);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString("%1").arg(categoria->getIdCategoria()));
        ui->tableWidget->setItem(linha, 0, item);

        item = new QTableWidgetItem;
        item->setText(categoria->getDescCategoria());
        ui->tableWidget->setItem(linha, 1, item);

        item = new QTableWidgetItem;
        item->setText(QString("%1").arg(categoria->getIdSecao()));
        ui->tableWidget->setItem(linha, 2, item);

        item = new QTableWidgetItem;
        item->setText(categoria->getDescSecao());
        ui->tableWidget->setItem(linha, 3, item);
        linha++;
    }
}

ListCategoria::~ListCategoria()
{
    delete ui;
}
