#include "listcategoria.h"
#include "ui_listcategoria.h"
#include "dominio/categoria.h"
#include "negocio/cadastrocategoria.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "cadastro.h"
#include <QDialogButtonBox>
#include "dominio/estoque.h"
#include <QDebug>

ListCategoria::ListCategoria(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListCategoria)
{
    ui->setupUi(this);
    configuracaoInicial();
}

ListCategoria::~ListCategoria()
{
    delete ui;
}

void ListCategoria::clicouNoBotaoOk()
{
    Cadastro* cadastro = new Cadastro;
    cadastro->show();
}

void ListCategoria::configuracaoInicial()
{
    setConnects();
    preencherRelatorioDeCategorias();
}

void ListCategoria::preencherRelatorioDeCategorias()
{
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
        item->setData(QTableWidgetItem::UserType, QVariant(QMetaType::QObjectStar, &categoria));

        item = new QTableWidgetItem;
        item->setText(QString("%1").arg(categoria->getIdSecao()));
        ui->tableWidget->setItem(linha, 2, item);

        item = new QTableWidgetItem;
        item->setText(categoria->getDescSecao());
        ui->tableWidget->setItem(linha, 3, item);
        linha++;

        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();

    }
}

void ListCategoria::setConnects()
{
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(clicouProdutoSelecionado(QTableWidgetItem*)));
}

QString ListCategoria::getId()
{
  return _id;
}

void ListCategoria::clicouProdutoSelecionado(QTableWidgetItem *item)
{
    if(item == nullptr)
        return;

    qDebug() << item->row();

    QTableWidgetItem* itemId = ui->tableWidget->item(item->row(), 0);

    if(itemId == nullptr)
        return;

    _id = itemId->text();
    CadastroCategoria* cadastroCategoria;

    QVariant value = item->data(QTableWidgetItem::UserType);
    if (!value.isNull()){
        qDebug() << "entrou aqui johnnys";
        cadastroCategoria = qobject_cast<CadastroCategoria*>(qvariant_cast<QObject*>(value));
        if (cadastroCategoria != nullptr) {
            qDebug() << "entrou aqui johnnys 2";

        }
    }

    this->accept();
}
