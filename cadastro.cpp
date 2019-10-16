#include "cadastro.h"
#include "ui_cadastro.h"
#include <qdebug.h>
#include <QMessageBox>
#include "relatorio.h"
#include "QTableWidgetItem"
#include "QLineEdit"
#include "QString"
#include "cadastrobase.h"
#include <ctype.h>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <sstream>
#include <QCoreApplication>
#include "cadastrofilial.h"
#include "cadastrodepartamento.h"
#include "negocio/cadastrocategoria.h"
#include "negocio/cadastroproduto.h"
#include "negocio/cadastroestoque.h"
#include <stdlib.h>
#include "listfilial.h"


using namespace std;

Cadastro::Cadastro(QWidget *parent) : QWidget(parent), ui(new Ui::Cadastro)
{
    ui->setupUi(this);
    configuracaoInicial();
//    ui->lnFilial->setText("testando filial");

    db = QSqlDatabase::addDatabase("QPSQL");
    //QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("estoque");
    db.setUserName("postgres");
    db.setPassword("123456");
    db.setPort(5432);
    db.open();
}

Cadastro::~Cadastro()
{
    delete ui;
}

void Cadastro::onbtFilialclicked()
{
    ListFilial* listaFilial = new ListFilial;
    listaFilial->show();

    qDebug() << "Log: usuário pesquisou filial";
}

void Cadastro::onbtDepartamentoclicked()
{
    qDebug() << "Log: usuário pesquisou departamento";
}

void Cadastro::onbtCategoriaclicked()
{
    qDebug() << "Log: usuário pesquisou categoria";
}

void Cadastro::onbtProdutoclicked()
{
    qDebug() << "Log: usuário pesquisou produto";
}

void Cadastro::onbtBaseclicked()
{
    qDebug() << "Log: usuário pesquisou base";
}

void Cadastro::onbtSalvarclicked()
{
    qDebug() << "Log: usuário salvou a busca/os dados";
    //QMessageBox::about(this, "Alerta!", "Dados salvos com sucesso!");
//    ui->stRelatorio->setCurrentIndex(1);

    CadastroBase* cadastroBase = new CadastroBase;
    cadastroBase->setCategoria(ui->lnCategoria->text());
    cadastroBase->setProduto(ui->lnProduto->text());
    cadastroBase->setBase(ui->lnBase->text());

//    salva
}

void Cadastro::onbtLimparclicked()
{
    qDebug() << "Log: usuário limpou os parâmetros de pesquisa";
}

void Cadastro::onlnFilialinformed()
{

    if (ui->lnFilial->text().isEmpty()){
        QMessageBox::about(this, "Alerta!", "Por favor, preencha todos os campos!");
        qDebug() << "Log: usuário não informou filial";
    } else if (!(validaString(ui->lnFilial->text()))){
        QMessageBox::about(this, "Alerta!", "Nome inválido!");
        qDebug() << "Log: usuário informou nome para filial inválido";
    } else if (VerificaSeENumero(ui->lnFilial->text())) {
        qDebug() << "Log: usuário informou id da filial desejada";
        CadastroFilial* cadastroFilial = new CadastroFilial;
        QString id = ui->lnFilial->text();
        QString descricao = cadastroFilial->getDescricaoFilial(ui->lnFilial->text().toInt());
        ui->lnFilial->setText(id + " - " + descricao);
    } else {
            QString descFilial = ui->lnFilial->text().toUpper();
            CadastroFilial* cadastroFilial = new CadastroFilial;
           // cadastroFilial->RetornaIdDaFilial(descFilial);
            qDebug() << "Entrei aqui";
            int idFilial = cadastroFilial->RetornaIdDaFilial(descFilial);
            qDebug() << "entrei aqui tbm kkk bjs";
            ui->lnFilial->setText(QString::number(idFilial) + " - " + descFilial);
            qDebug() << "Log: usuário informou filial com sucesso!";
        }

}

void Cadastro::onlnDepartamentoinformed()
{    
    if (ui->lnDepartamento->text().isEmpty()){
        QMessageBox::about(this, "Alerta!", "Por favor, preencha todos os campos!");
        qDebug() << "Log: usuário não informou departamento";
    } else if (!(validaString(ui->lnDepartamento->text()))){
        QMessageBox::about(this, "Alerta!", "Nome inválido!");
        qDebug() << "Log: usuário informou nome para departamento inválido";
    } else if (VerificaSeENumero(ui->lnDepartamento->text())) {
        qDebug() << "Log: usuário informou número do departamento desejado";
        CadastroDepartamento* cadastroDepartmento = new CadastroDepartamento;
        QString id = ui->lnDepartamento->text();
        QString descricao = cadastroDepartmento->getDescricaoDepartamento(ui->lnDepartamento->text().toInt());
        qDebug() << descricao;
        ui->lnDepartamento->setText(id + " - " + descricao);

    }else {
        QString descDepartamento = ui->lnDepartamento->text().toUpper();
        CadastroDepartamento* cadastroDepartamento = new CadastroDepartamento;
        int idDepartamento = cadastroDepartamento->buscaIdDoDepartamento(descDepartamento);
        ui->lnDepartamento->setText(QString::number(idDepartamento) + " - " + descDepartamento);
        qDebug() << "Log: usuário informou departamento com sucesso!";
    }
}

void Cadastro::onlnCategoriainformed()
{    
    if (ui->lnCategoria->text().isEmpty()){
        QMessageBox::about(this, "Alerta!", "Por favor, preencha todos os campos!");
        qDebug() << "Log: usuário não informou categoria";
    } else if (!(validaString(ui->lnCategoria->text()))){
        QMessageBox::about(this, "Alerta!", "Nome inválido!");
        qDebug() << "Log: usuário informou nome para categoria inválido";
    } else if (VerificaSeENumero(ui->lnCategoria->text())){
        qDebug() << "Log: usuário informou id da categoria desejada";
        CadastroCategoria* cadastroCategoria = new CadastroCategoria;
        QString id = ui->lnCategoria->text();
        QString identificacao = cadastroCategoria->getDescricaoCategoria(ui->lnCategoria->text().toInt());
        ui->lnCategoria->setText(id + " - " + identificacao);
    } else {
        QString descCategoria = ui->lnCategoria->text().toUpper();
        CadastroCategoria* cadastroCategoria = new CadastroCategoria;
        int idCategoria = cadastroCategoria->RetornaIdAtravesdaDescricao(descCategoria);
        ui->lnCategoria->setText(QString::number(idCategoria) + " - " + descCategoria);
        qDebug() << "Log: usuário informou categoria com sucesso!";
    }
}

void Cadastro::onlnProdutoinformed()
{    
    if (ui->lnProduto->text().isEmpty()){
        QMessageBox::about(this, "Alerta!", "Por favor, preencha todos os campos!");
        qDebug() << "Log: usuário não informou produto";
    } else if (!(validaString(ui->lnProduto->text()))){
        QMessageBox::about(this, "Alerta!", "Nome inválido!");
        qDebug() << "Log: usuário informou nome para produto inválido";
    } else if (VerificaSeENumero(ui->lnProduto->text())){
        qDebug() << "Log: usuário informou id do produto";
        CadastroProduto* cadastroProduto = new CadastroProduto;
        QString identificacao = ui->lnProduto->text();
        QString descricaoProduto = cadastroProduto->getDescricaoProduto(ui->lnProduto->text().toInt());
        ui->lnProduto->setText(identificacao + " - " + descricaoProduto);
    } else {
        QString descProduto = ui->lnProduto->text().toUpper();
        CadastroProduto* cadastroProduto = new CadastroProduto;
        int idProduto = cadastroProduto->RetornaIdDoProdutoPelaDescricao(descProduto);
        ui->lnProduto->setText(QString::number(idProduto) + " - " + descProduto);
        QString descFilial = ui->lnFilial->text().toUpper();
//        CadastroEstoque* cadastroEstoque = new CadastroEstoque;
//        QString base = cadastroEstoque->getBasedoProdutoEstoque(descProduto,descFilial);
//        ui->lnBase->setText(base);
//        qDebug() << "Base: " << base;
        qDebug() << "Log: usuário informou produto com sucesso!";
    }
}

void Cadastro::chamaBase()
{
    if (!(ui->lnProduto->text().isEmpty()) && (!(ui->lnFilial->text().isEmpty()))){
        CadastroEstoque* cadastroEstoque = new CadastroEstoque;
        QString base = cadastroEstoque->getBasedoProdutoEstoque(ui->lnProduto->text(), ui->lnFilial->text());
        ui->lnBase->setText(base);
    }
}

void Cadastro::onlnBaseinformed()
{    
    QLineEdit lnBase;
    //lnBase.setValidator(new QDoubleValidator(0, 100, 2, this));
    QString a = ui->lnBase->text();
    if (ui->lnBase->text().isEmpty()){
        QMessageBox::about(this, "Alerta!", "Por favor, preencha todos os campos!");
        qDebug() << "Log: usuário não informou base";
    }

    qDebug() << a;

}

bool Cadastro::validaString(QString s)
{
    int upper = 0, lower = 0, number =0, special = 0, space = 0;
    for (int i=0; i<s.length(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            number++;
        } else if (s[i] >= 'A' && s[i] <= 'Z'){
            upper++;
        } else if (s[i] >= 'a' && s[i] <= 'z'){
            lower++;
        } else if (s[i] == ' ') {
            space++;
        } else{
            special++;
        }
    }
    if (special > 0){
        return false;
    } else {
        return true;
    }
}

bool Cadastro::VerificaSeENumero(QString s)
{
    int upper = 0, lower = 0, number =0, special = 0, space = 0;
    for (int i=0; i<s.length(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            number++;
        } else if (s[i] >= 'A' && s[i] <= 'Z'){
            upper++;
        } else if (s[i] >= 'a' && s[i] <= 'z'){
            lower++;
        } else if (s[i] == ' ') {
            space++;
        } else{
            special++;
        }
    }
    if (upper > 0 || lower > 0 || special > 0){
        return false;
    } else {
        return true;
    }
}

void Cadastro::configuracaoInicial()
{
     setConnects();
     //ui->lnBase->set
//     Relatorio* relatorio = new Relatorio();
//     ui->stRelatorio->addWidget(relatorio);
}

void Cadastro::setConnects()
{
    connect(ui->btBase, SIGNAL(clicked()), this, SLOT(onbtBaseclicked()));
    connect(ui->btFilial, SIGNAL(clicked()), this, SLOT(onbtFilialclicked()));
    connect(ui->btDepartamento, SIGNAL(clicked()), this, SLOT(onbtDepartamentoclicked()));
    connect(ui->btProduto, SIGNAL(clicked()), this, SLOT(onbtProdutoclicked()));
    connect(ui->btCategoria, SIGNAL(clicked()), this, SLOT(onbtCategoriaclicked()));
    connect(ui->btLimpar, SIGNAL(clicked()), this, SLOT(onbtLimparclicked()));
    connect(ui->btSalvar, SIGNAL(clicked()), this, SLOT(onbtSalvarclicked()));

    connect(ui->lnFilial, SIGNAL(returnPressed()), this, SLOT(onlnFilialinformed()));
    connect(ui->lnDepartamento, SIGNAL(returnPressed()), this, SLOT(onlnDepartamentoinformed()));
    connect(ui->lnProduto, SIGNAL(returnPressed()), this, SLOT(onlnProdutoinformed()));
    connect(ui->lnCategoria, SIGNAL(returnPressed()), this, SLOT(onlnCategoriainformed()));
    connect(ui->lnBase, SIGNAL(returnPressed()), this, SLOT(onlnBaseinformed()));
}
