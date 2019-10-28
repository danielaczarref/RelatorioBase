#include "listsecao.h"
#include "ui_listsecao.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "cadastrosecao.h"
#include "dominio/secao.h"
#include <QDebug>

ListSecao::ListSecao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListSecao)
{
    ui->setupUi(this);
    configuracaoInicial();
}

ListSecao::~ListSecao()
{
    delete ui;
}

void ListSecao::configuracaoInicial()
{
    preencherRelatorioSecao();
    setConnects();
}

void ListSecao::preencherRelatorioSecao()
{

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
        item->setData(QTableWidgetItem::UserType, QVariant(QMetaType::QObjectStar, &secao));


        item = new QTableWidgetItem;
        item->setText(QString("%1").arg(secao->getIdDepartamento()));
        ui->tableWidget->setItem(linha, 2, item);

        item = new QTableWidgetItem;
        item->setText(secao->getDescDepartamento());
        ui->tableWidget->setItem(linha, 3, item);
        linha++;

        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();

    }
}

void ListSecao::setConnects()
{
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(clicouEmSecao(QTableWidgetItem*)));
}

QString ListSecao::getId()
{
    return _idSecao;

}

void ListSecao::clicouEmSecao(QTableWidgetItem *item)
{
    if(item == nullptr)
        return;

    qDebug() << item->row();

    QTableWidgetItem* itemId = ui->tableWidget->item(item->row(), 0);

    if(itemId == nullptr)
        return;

    _idSecao = itemId->text();

    qDebug() << "printando pra ver se chegou aqui" ;
    CadastroSecao* cadastroSecao;

    QVariant value = item->data(QTableWidgetItem::UserType);
    if (!value.isNull()){
        qDebug() << "entrou aqui johnnys";
        cadastroSecao = qobject_cast<CadastroSecao*>(qvariant_cast<QObject*>(value));
        if (cadastroSecao != nullptr) {
            qDebug() << "entrou aqui johnnys 2";

        }
    }

    this->accept();
}
