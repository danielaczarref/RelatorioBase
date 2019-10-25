#include "listfilial.h"
#include "ui_listfilial.h"
#include <QTableWidget>
#include "cadastrofilial.h"
#include <QTableWidgetItem>
#include "dominio/filial.h"
#include <QDebug>

ListFilial::ListFilial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListFilial)
{
    ui->setupUi(this);
    configuracaoInicial();
}

ListFilial::~ListFilial()
{
    delete ui;
}

void ListFilial::configuracaoInicial()
{
    preencherRelatorioFilial();
    setConnects();
}

void ListFilial::preencherRelatorioFilial()
{
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
        item->setData(QTableWidgetItem::UserType, QVariant(QMetaType::QObjectStar, &filial));

        linha++;

        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();

    }
}

void ListFilial::setConnects()
{
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(clicouEmFilial(QTableWidgetItem*)));
}

QString ListFilial::getId()
{
    return _idFilial;
}

void ListFilial::clicouEmFilial(QTableWidgetItem *item)
{
    if(item == nullptr)
        return;

    qDebug() << item->row();

    QTableWidgetItem* itemId = ui->tableWidget->item(item->row(), 0);

    if(itemId == nullptr)
        return;

    _idFilial = itemId->text();

    qDebug() << "printando pra ver se chegou aqui" ;
    CadastroFilial* cadastroFilial;

    QVariant value = item->data(QTableWidgetItem::UserType);
    if (!value.isNull()){
        qDebug() << "entrou aqui johnnys";
        cadastroFilial = qobject_cast<CadastroFilial*>(qvariant_cast<QObject*>(value));
        if (cadastroFilial != nullptr) {
            qDebug() << "entrou aqui johnnys 2";

        }
    }

    this->accept();
}
