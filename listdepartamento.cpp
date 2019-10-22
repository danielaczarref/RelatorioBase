#include "listdepartamento.h"
#include "ui_listdepartamento.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "dominio/departamento.h"
#include "cadastrodepartamento.h"

listDepartamento::listDepartamento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listDepartamento)
{
    ui->setupUi(this);
    QTableWidget* tableWidget = new QTableWidget;
    //tableWidget->show();

    QList<Departamento*> listaDepartamento;
    CadastroDepartamento* cadastroDepartamento = new CadastroDepartamento;
    listaDepartamento = cadastroDepartamento->getInformacoesDepartamento();

    int linha = 0;

    foreach (Departamento* departamento, listaDepartamento){
        ui->tableWidget->insertRow(linha);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString("%1").arg(departamento->getIdDepartamento()));
        ui->tableWidget->setItem(linha, 0, item);

        item = new QTableWidgetItem;
        item->setText(departamento->getDescDepartamento());
        ui->tableWidget->setItem(linha, 1, item);
        linha++;
    }

}

listDepartamento::~listDepartamento()
{
    delete ui;
}
