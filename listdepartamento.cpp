#include "listdepartamento.h"
#include "ui_listdepartamento.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "dominio/departamento.h"
#include "cadastrodepartamento.h"
#include <QDebug>

listDepartamento::listDepartamento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listDepartamento)
{
    ui->setupUi(this);
    configuracaoInicial();
}

listDepartamento::~listDepartamento()
{
    delete ui;
}

void listDepartamento::configuracaoInicial()
{
    preencherRelatorioDeDepartamento();
    setConnects();
}

void listDepartamento::preencherRelatorioDeDepartamento()
{
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
        item->setData(QTableWidgetItem::UserType, QVariant(QMetaType::QObjectStar, &departamento));

        linha++;

        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();
    }
}

void listDepartamento::setConnects()
{
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(clicouEmDepartamentoSelecionado(QTableWidgetItem*)));
}

QString listDepartamento::getId()
{
    return _idDepartamento;

}

void listDepartamento::clicouEmDepartamentoSelecionado(QTableWidgetItem *item)
{
    if(item == nullptr)
        return;

    qDebug() << item->row();

    QTableWidgetItem* itemId = ui->tableWidget->item(item->row(), 0);

    if(itemId == nullptr)
        return;

    _idDepartamento = itemId->text();
    CadastroDepartamento* cadastroDepartamento;

    QVariant value = item->data(QTableWidgetItem::UserType);
    if (!value.isNull()){
        qDebug() << "entrou aqui johnnys";
        cadastroDepartamento = qobject_cast<CadastroDepartamento*>(qvariant_cast<QObject*>(value));
        if (cadastroDepartamento != nullptr) {
            qDebug() << "entrou aqui johnnys 2";
        }
    }

    this->accept();
}
