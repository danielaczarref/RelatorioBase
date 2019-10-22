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
    listDepartamento* listDep = new listDepartamento;
    listDep->show();
    qDebug() << "Log: usuário pesquisou departamento";
}

void Cadastro::onbtCategoriaclicked()
{
    ListCategoria* listCategoria = new ListCategoria;
    listCategoria->show();
    qDebug() << "Log: usuário pesquisou categoria";
}

void Cadastro::onbtProdutoclicked()
{
    ListProduto* listProduto = new ListProduto;
    listProduto->show();
    qDebug() << "Log: usuário pesquisou produto";
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
        idFilial = id.toInt();
        qDebug() << "id filial ANTES: " << idFilial;
        QString descricao = cadastroFilial->getDescricaoFilial(ui->lnFilial->text().toInt());
        ui->lnFilial->setText(id + " - " + descricao);
    } else {
            QString descFilial = ui->lnFilial->text().toUpper();
            CadastroFilial* cadastroFilial = new CadastroFilial;
           // cadastroFilial->RetornaIdDaFilial(descFilial);
            qDebug() << "Entrei aqui";
            idFilial = cadastroFilial->RetornaIdDaFilial(descFilial);
            qDebug() << "entrei aqui tbm kkk bjs";
            ui->lnFilial->setText(QString::number(idFilial) + " - " + descFilial);
            qDebug() << "Log: usuário informou filial com sucesso!";
        } 

//    ui->lnCategoria->setProperty("id", idCategoria);
//    long long id = ui->lnCategoria->property("id");

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
        idDepartamento = id.toInt();
        QString descricao = cadastroDepartmento->getDescricaoDepartamento(ui->lnDepartamento->text().toInt());
        qDebug() << descricao;
        ui->lnDepartamento->setText(id + " - " + descricao);

    }else {
        QString descDepartamento = ui->lnDepartamento->text().toUpper();
        CadastroDepartamento* cadastroDepartamento = new CadastroDepartamento;
        idDepartamento = cadastroDepartamento->buscaIdDoDepartamento(descDepartamento);
        ui->lnDepartamento->setText(QString::number(idDepartamento) + " - " + descDepartamento);
        qDebug() << "Log: usuário informou departamento com sucesso!";
    }
}

void Cadastro::onlnSecaoInformed()
{
    if (!(validaString(ui->lnSecao->text()))){
        QMessageBox::about(this, "Alerta!", "Uso de caracteres inválido!");
        qDebug() << "Log: usuário informou nome para seção inválido";
    } else if (VerificaSeENumero(ui->lnSecao->text())){
        qDebug() << "Log: usuário informou número para seção desejada";
        CadastroSecao* cadastroSecao = new CadastroSecao;
        QString id = ui->lnSecao->text();
        idSecao = id.toInt();
        qDebug() << "id secao ANTES: " << idSecao;
        QString descricao = cadastroSecao->getDescricaoSecao(ui->lnSecao->text().toInt());
        qDebug() << descricao;
        ui->lnSecao->setText(id + " - " + descricao);

    } else {
        QString descSecao = ui->lnSecao->text().toUpper();
        CadastroSecao* cadastroSecao = new CadastroSecao;
        idSecao = cadastroSecao->BuscaIdPelaDescricaoDaSecao(descSecao);
        ui->lnSecao->setText(QString::number(idSecao) + " - " + descSecao);
        qDebug() << "Log: usuário informou seção com suceso!";
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
        idCategoria = id.toInt();
        QString identificacao = cadastroCategoria->getDescricaoCategoria(ui->lnCategoria->text().toInt());
        ui->lnCategoria->setText(id + " - " + identificacao);
    } else {
        QString descCategoria = ui->lnCategoria->text().toUpper();
        CadastroCategoria* cadastroCategoria = new CadastroCategoria;
        idCategoria = cadastroCategoria->RetornaIdAtravesdaDescricao(descCategoria);
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
        idProduto = identificacao.toInt();
        QString descricaoProduto = cadastroProduto->getDescricaoProduto(ui->lnProduto->text().toInt());
        ui->lnProduto->setText(identificacao + " - " + descricaoProduto);
    } else {
        QString descProduto = ui->lnProduto->text().toUpper();
        CadastroProduto* cadastroProduto = new CadastroProduto;
        idProduto = cadastroProduto->RetornaIdDoProdutoPelaDescricao(descProduto);
        ui->lnProduto->setText(QString::number(idProduto) + " - " + descProduto);
        QString descFilial = ui->lnFilial->text().toUpper();
//        CadastroEstoque* cadastroEstoque = new CadastroEstoque;
//        QString base = cadastroEstoque->getBasedoProdutoEstoque(descProduto,descFilial);
//        ui->lnBase->setText(base);
//        qDebug() << "Base: " << base;
        qDebug() << "Log: usuário informou produto com sucesso!";
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
    } /*else if (ui->lnFilial->text().isEmpty() || ui->lnProduto->text().isEmpty()){
        QMessageBox::about(this, "Alerta!", "Preenchimento do campos Filial e Produto são obrigatórios!");
        ui->lnFilial->setFocus();
        return false;
    }*/

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
