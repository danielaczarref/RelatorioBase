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
#include "listdepartamento.h"
#include <QLineEdit>
#include "listsecao.h"
#include "listcategoria.h"
#include "listproduto.h"
#include "listrelatoriobase.h"
#include "cadastrosecao.h"
#include "negocio/filtro.h"

using namespace std;

Cadastro::Cadastro(QWidget *parent) : QWidget(parent), ui(new Ui::Cadastro)
{
    ui->setupUi(this);
    configuracaoInicial();
    db = QSqlDatabase::addDatabase("QPSQL");
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
    QString id;
    CadastroFilial* cadastroFilial = new CadastroFilial;
    ListFilial* listaFilial = new ListFilial;
    if (listaFilial->exec() == QDialog::Accepted) {
        id = listaFilial->getId();
        QString novaDescFilial = cadastroFilial->getDescricaoFilial(id.toInt());
        ui->lnFilial->setText(id + " - " + novaDescFilial);
    }
    //listaFilial->show();

    qDebug() << "Log: usuário pesquisou filial";
}

void Cadastro::onbtDepartamentoclicked()
{
    QString id;
    CadastroDepartamento* cadastroDepartamento = new CadastroDepartamento;
    listDepartamento* listDep = new listDepartamento;
    if (listDep->exec() == QDialog::Accepted){
        id = listDep->getId();
        QString novaDescDepartamento = cadastroDepartamento->getDescricaoDepartamento(id.toInt());
        ui->lnDepartamento->setText(id + " - " + novaDescDepartamento);
    }
    qDebug() << "Log: usuário pesquisou departamento";
}

void Cadastro::onbtCategoriaclicked()
{
    QString id;
    CadastroCategoria* cadastroCategoria = new CadastroCategoria;
    ListCategoria* listCategoria = new ListCategoria;
    if(listCategoria->exec() == QDialog::Accepted) {
        id = listCategoria->getId();
        QString novaDescCategoria = cadastroCategoria->getDescricaoCategoria(id.toInt());
        ui->lnCategoria->setText(id + " - " + novaDescCategoria);
    }

    qDebug() << "Log: usuário pesquisou categoria " << id;
}

void Cadastro::onbtSecaoclicked()
{
    QString id;
    CadastroSecao* cadastroSecao = new CadastroSecao;
    ListSecao* listSecao = new ListSecao;
    if (listSecao->exec() == QDialog::Accepted){
        id = listSecao->getId();
        QString novaDescSecao = cadastroSecao->getDescricaoSecao(id.toInt());
        ui->lnSecao->setText(id + " - " + novaDescSecao);
    }
}

void Cadastro::onbtProdutoclicked()
{
    QString id;
    CadastroProduto* cadastroProduto = new CadastroProduto;
    ListProduto* listProduto = new ListProduto;
    if (listProduto->exec() == QDialog::Accepted){
        id = listProduto->getId();
        QString novaDescProduto = cadastroProduto->getDescricaoProduto(id.toInt());
        ui->lnProduto->setText(id + " - " + novaDescProduto);
    }
    qDebug() << "Log: usuário pesquisou produto";
}

void Cadastro::onbtLimparclicked()
{
    qDebug() << "Log: usuário limpou os parâmetros de pesquisa";
}

void Cadastro::onlnFilialinformed()
{
    if (!(validaString(ui->lnFilial->text())))
    {
        QMessageBox::about(this, "Alerta!", "Nome inválido!");
        qDebug() << "Log: usuário informou nome para filial inválido";
        ui->lnFilial->clear();
    }
    else if (!(ui->lnFilial->text().isEmpty()))
    {
        CadastroFilial* cadastroFilial = new CadastroFilial;
        if (!(cadastroFilial->verificaSeExiste(ui->lnFilial->text().toUpper())))
        {
            QMessageBox::about(this, "Erro!", "Dados informados não existem!");
            ui->lnFilial->clear();
        }
        else {
            if (VerificaSeENumero(ui->lnFilial->text()))
            {
                QString id = ui->lnFilial->text();
                QString descricao = cadastroFilial->getDescricaoFilial(id.toInt());
                ui->lnFilial->setText(id + " - " + descricao);
                qDebug() << "Log: usuário informou filial com sucesso!";
            }
            else
            {
                QString descFilial = ui->lnFilial->text().toUpper();
                int identificacaoFilial = cadastroFilial->RetornaIdDaFilial(descFilial);
                ui->lnFilial->setText(QString::number(identificacaoFilial) + " - " + descFilial);
                qDebug() << "Log: usuário informou departamento com sucesso!";
            }
        }
    }
}

void Cadastro::onlnDepartamentoinformed()
{

    if (!(validaString(ui->lnDepartamento->text())))
    {
        QMessageBox::about(this, "Alerta!", "Nome inválido!");
        ui->lnDepartamento->clear();
        qDebug() << "Log: usuário informou nome para departamento inválido";
    }
    else if (!(ui->lnDepartamento->text().isEmpty()))
    {
        CadastroDepartamento* cadastroDepartamento = new CadastroDepartamento;
        if (!(cadastroDepartamento->verificaSeExiste(ui->lnDepartamento->text().toUpper())))
        {
            QMessageBox::about(this, "Erro!", "Dados informados não existem!");
            ui->lnDepartamento->clear();
        }
        else {
            if (VerificaSeENumero(ui->lnDepartamento->text()))
            {
                QString id = ui->lnDepartamento->text();
                QString descricao = cadastroDepartamento->getDescricaoDepartamento(id.toInt());
                ui->lnDepartamento->setText(id + " - " + descricao);
                qDebug() << "Log: usuário informou departamento com sucesso!";
            }
            else
            {
                QString descDepartamento = ui->lnDepartamento->text().toUpper();
                int idDept = cadastroDepartamento->buscaIdDoDepartamento(descDepartamento);
                ui->lnDepartamento->setText(QString::number(idDept) + " - " + descDepartamento);
                qDebug() << "Log: usuário informou departamento com sucesso!";
            }
        }
    }
}

void Cadastro::onlnSecaoInformed()
{
    if (!(validaString(ui->lnSecao->text())))
    {
        QMessageBox::about(this, "Alerta!", "Nome inválido!");
        ui->lnSecao->clear();
        qDebug() << "Log: usuário informou nome para seção inválido";
    }
    else if (!(ui->lnSecao->text().isEmpty()))
    {
        CadastroSecao* cadastroSecao = new CadastroSecao;
        if (!(cadastroSecao->verificaSeExiste(ui->lnSecao->text().toUpper())))
        {
            QMessageBox::about(this, "Erro!", "Dados informados não existem!");
            ui->lnSecao->clear();
        }
        else {
            if (VerificaSeENumero(ui->lnSecao->text()))
            {
                QString id = ui->lnSecao->text();
                QString descricao = cadastroSecao->getDescricaoSecao(id.toInt());
                ui->lnSecao->setText(id + " - " + descricao);
                qDebug() << "Log: usuário informou departamento com sucesso!";
            }
            else
            {
                QString descSecao = ui->lnSecao->text().toUpper();
                int identificacaoSecao = cadastroSecao->BuscaIdPelaDescricaoDaSecao(descSecao);
                ui->lnSecao->setText(QString::number(identificacaoSecao) + " - " + descSecao);
                qDebug() << "Log: usuário informou departamento com sucesso!";
            }
        }
    }
}

bool Cadastro::isFilialEmpty()
{
    if (ui->lnFilial->text().isEmpty()){
        return true;
    } else {
        return false;
    }
}

bool Cadastro::isDepartamentoEmpty()
{
    if (ui->lnDepartamento->text().isEmpty()){
        return true;
    } else {
        return false;
    }
}

bool Cadastro::isSecaoEmpty()
{
    if (ui->lnSecao->text().isEmpty()){
        return true;
    } else {
        return false;
    }
}

bool Cadastro::isCategoriaEmpty()
{
    if (ui->lnCategoria->text().isEmpty()){
        return true;
    } else {
        return false;
    }
}

bool Cadastro::isProdutoEmpty()
{
    if (ui->lnProduto->text().isEmpty()){
        return true;
    } else {
        return false;
    }
}

QString Cadastro::getRetornalnProduto() const
{
    QString descProduto;
    if (!(ui->lnProduto->text().isEmpty())){
        descProduto = ui->lnProduto->text();
        return descProduto;
    }

}

QString Cadastro::getRetornalnFilial() const
{
    QString descFilial;
    if (!(ui->lnFilial->text().isEmpty())){
        descFilial = ui->lnFilial->text();
        return descFilial;
    }
}

void Cadastro::onlnCategoriainformed()
{    
    if (!(validaString(ui->lnCategoria->text())))
    {
        QMessageBox::about(this, "Alerta!", "Nome inválido!");
        ui->lnCategoria->clear();
        qDebug() << "Log: usuário informou nome para categoria inválido";
    }
    else if (!(ui->lnCategoria->text().isEmpty()))
    {
        CadastroCategoria* cadastroCategoria = new CadastroCategoria;
        if (!(cadastroCategoria->verificaSeExiste(ui->lnCategoria->text().toUpper())))
        {
            QMessageBox::about(this, "Erro!", "Dados informados não existem!");
            ui->lnCategoria->clear();
        }
        else {
            if (VerificaSeENumero(ui->lnCategoria->text()))
            {
                QString id = ui->lnCategoria->text();
                QString descricao = cadastroCategoria->getDescricaoCategoria(id.toInt());
                ui->lnCategoria->setText(id + " - " + descricao);
                qDebug() << "Log: usuário informou categoria com sucesso!";
            }
            else
            {
                QString descCategoria = ui->lnCategoria->text().toUpper();
                int idCateg = cadastroCategoria->RetornaIdAtravesdaDescricao(descCategoria);
                ui->lnCategoria->setText(QString::number(idCateg) + " - " + descCategoria);
                qDebug() << "Log: usuário informou categoria com sucesso!";
            }
        }
    }
}

void Cadastro::onlnProdutoinformed()
{    
    if (!(validaString(ui->lnProduto->text())))
    {
        QMessageBox::about(this, "Alerta!", "Nome inválido!");
        ui->lnProduto->clear();
        qDebug() << "Log: usuário informou nome para produto inválido";
    }
    else if (!(ui->lnProduto->text().isEmpty()))
    {
        CadastroProduto* cadastroProduto = new CadastroProduto;
        if (!(cadastroProduto->verificaSeExiste(ui->lnProduto->text().toUpper())))
        {
            QMessageBox::about(this, "Erro!", "Dados informados não existem!");
            ui->lnProduto->clear();
        }
        else {
            if (VerificaSeENumero(ui->lnProduto->text()))
            {
                QString id = ui->lnProduto->text();
                QString descricao = cadastroProduto->getDescricaoProduto(id.toInt());
                ui->lnProduto->setText(id + " - " + descricao);
                qDebug() << "Log: usuário informou produto com sucesso!";
            }
            else
            {
                QString descProduto = ui->lnProduto->text().toUpper();
                int idProd = cadastroProduto->RetornaIdDoProdutoPelaDescricao(descProduto);
                ui->lnProduto->setText(QString::number(idProd) + " - " + descProduto);
                qDebug() << "Log: usuário informou produto com sucesso!";
            }
        }
    }
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

bool Cadastro::verificaCampos()
{
    if (ui->lnFilial->text().isEmpty() && ui->lnDepartamento->text().isEmpty() && ui->lnCategoria->text().isEmpty()
            && ui->lnSecao->text().isEmpty() && ui->lnProduto->text().isEmpty()){
        QMessageBox::about(this, "Alerta!", "Não é possível filtrar busca sem parâmetros!");
        ui->lnFilial->setFocus();
        return false;
    }
    return true;
}

void Cadastro::onbtSalvarclicked()
{
    QStringList listFilial, listDepartamento, listSecao, listCategoria, listProduto;

    if (!(ui->lnFilial->text().isEmpty())){
        listFilial = ui->lnFilial->text().split(" - ");
    }

    if (!(ui->lnDepartamento->text().isEmpty())){
        listDepartamento = ui->lnDepartamento->text().split(" - ");
    }

    if (!(ui->lnSecao->text().isEmpty())){
        listSecao = ui->lnSecao->text().split(" - ");
    }

    if (!(ui->lnCategoria->text().isEmpty())){
        listCategoria = ui->lnCategoria->text().split(" - ");
    }

    if (!(ui->lnProduto->text().isEmpty())){
        listProduto = ui->lnProduto->text().split(" - ");
    }

    int sizeFilialList = listFilial.length();
    int sizeDepartamentoList = listDepartamento.length();
    int sizeSecaoList = listSecao.length();
    int sizeCategoriaList = listCategoria.length();
    int sizeProdutoList = listProduto.length();
    QString idDaFilial = " ";
    QString idDoDepartamento = " ";
    QString idDaSecao = " ";
    QString idDaCategoria = " ";
    QString idDoProduto = " ";

//        int sizeProdutoList = listProduto.length();

        for (int i = 0; i < sizeFilialList; i++) {
            idDaFilial = listFilial.at(0);
        }

        for (int i=0; i < sizeDepartamentoList; i++){
            idDoDepartamento = listDepartamento.at(0);
        }

        for (int i=0; i<sizeSecaoList; i++){
            idDaSecao = listSecao.at(0);
        }

        for (int i=0; i<sizeCategoriaList; i++){
            idDaCategoria = listCategoria.at(0);
        }

        for (int i=0; i<sizeProdutoList; i++){
            idDoProduto = listProduto.at(0);
        }

        int Filial = idDaFilial.toInt();
        int Departamento = idDoDepartamento.toInt();
        int Secao = idDaSecao.toInt();
        int Categoria = idDaCategoria.toInt();
        int Produto = idDoProduto.toInt();

    if (verificaCampos()){
        Filtro* filtro = new Filtro;
        filtro->setFilial(Filial);
        qDebug() << "filial: " << filtro->getFilial();
        filtro->setDepartamento(Departamento);
        filtro->setSecao(Secao);
        filtro->setCategoria(Categoria);
        filtro->setProduto(Produto);
        ListRelatorioBase* listRelatorio = new ListRelatorioBase(filtro);
        listRelatorio->show();
        ui->stRelatorio->setCurrentIndex(0);
        qDebug() << "Log: usuário salvou a busca/os dados";
    }
}
void Cadastro::configuracaoInicial()
{
     setConnects();
}

void Cadastro::setConnects()
{
    connect(ui->btFilial, SIGNAL(clicked()), this, SLOT(onbtFilialclicked()));
    connect(ui->btDepartamento, SIGNAL(clicked()), this, SLOT(onbtDepartamentoclicked()));
    connect(ui->btSecao, SIGNAL(clicked()), this, SLOT(onbtSecaoclicked()));
    connect(ui->btProduto, SIGNAL(clicked()), this, SLOT(onbtProdutoclicked()));
    connect(ui->btCategoria, SIGNAL(clicked()), this, SLOT(onbtCategoriaclicked()));
    connect(ui->btLimpar, SIGNAL(clicked()), this, SLOT(onbtLimparclicked()));
    connect(ui->btSalvar, SIGNAL(clicked()), this, SLOT(onbtSalvarclicked()));

    connect(ui->lnFilial, SIGNAL(returnPressed()), this, SLOT(onlnFilialinformed()));
    connect(ui->lnDepartamento, SIGNAL(returnPressed()), this, SLOT(onlnDepartamentoinformed()));
    connect(ui->lnProduto, SIGNAL(returnPressed()), this, SLOT(onlnProdutoinformed()));
    connect(ui->lnCategoria, SIGNAL(returnPressed()), this, SLOT(onlnCategoriainformed()));
    connect(ui->lnSecao, SIGNAL(returnPressed()), this, SLOT(onlnSecaoInformed()));
}
