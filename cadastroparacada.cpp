#include "cadastroparacada.h"
#include "ui_cadastroparacada.h"
#include <QDebug>
#include <QSqlQuery>
#include <dominio/produto.h>
#include <negocio/cadastroproduto.h>
#include <regex>
#include <QMessageBox>
#include "negocio/cadastrocategoria.h"
#include "listcategoria.h"

using namespace std;

CadastroParaCada::CadastroParaCada(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastroParaCada)
{
    ui->setupUi(this);
    configuracaoInicial();
}

CadastroParaCada::~CadastroParaCada()
{
    delete ui;
}

void CadastroParaCada::onpbPesquisarCategoria()
{
    QString id;
    CadastroCategoria* cadastroCategoria = new CadastroCategoria;
    ListCategoria* listCategoria = new ListCategoria;
    if(listCategoria->exec() == QDialog::Accepted) {
        id = listCategoria->getId();
        QString novaDescCategoria = cadastroCategoria->getDescricaoCategoria(id.toInt());
        ui->leCategoria->setText(id + " - " + novaDescCategoria);
    }

    qDebug() << "Log: usuário pesquisou categoria " << id;
}

void CadastroParaCada::onpbSalvar()
{
   // CadastroProduto* cadastroProduto = new CadastroProduto;
    if (validaCampos()){
        QMessageBox::about(this, "Alerta", "Produto cadastrado com sucesso!");
        ui->leDescricao->clear();
        ui->leValor->clear();
        ui->leCategoria->clear();
        ui->leDescricao->setFocus();
    } else{
        QMessageBox::about(this, "Alerta!", "Não foi possível cadastrar o produto! Verifique os campos novamente.");
        ui->leDescricao->setFocus();
    }
}

bool CadastroParaCada::onleDescricao()
{
    if (!(ui->leDescricao->text().isEmpty())){
        if ((validaString(ui->leDescricao->text()))){
            QString descricao = ui->leDescricao->text().toUpper();
            ui->leDescricao->setText(descricao);
            qDebug() << "Log: usuário informou descrição válida";
            ui->leValor->setFocus();
            return true;
        } else {
            QMessageBox::about(this, "Alerta!", "Uso de caracteres inválidos!");
            ui->leDescricao->clear();
            qDebug() << "Log: usuário informou descrição inválida";
            return false;
        }
    } else {
        return false;
    }
    return false;
}

bool CadastroParaCada::onleValor()
{
    if (!(ui->leValor->text().isEmpty())){
        ui->leCategoria->setFocus();
        return true;
    }
    return false;
}

bool CadastroParaCada::onleCategoria()
{
    if (!(ui->leCategoria->text().isEmpty())){
        if (validaString(ui->leCategoria->text())){
            QString categoria = ui->leCategoria->text().toUpper();
            ui->leCategoria->setText(categoria);
            qDebug() << "Log: usuário informou descrição válida";
            ui->pbSalvar->setFocus();
            return true;
        } else {
            QMessageBox::about(this, "Alerta!", "Uso de caracteres inválidos!");
            ui->leCategoria->clear();
            qDebug() << "Log: usuário informou descrição inválida";
            return false;
        }
    } else {
        return false;
    }
    return false;
}

void CadastroParaCada::configuracaoInicial()
{
    setConnects();
}

void CadastroParaCada::setConnects()
{
    connect(ui->leDescricao, SIGNAL(returnPressed()), this, SLOT(onleDescricao()));
    connect(ui->leValor, SIGNAL(returnPressed()), this, SLOT(onleValor()));
    connect(ui->leCategoria, SIGNAL(returnPressed()), this, SLOT(onleCategoria()));
    connect(ui->pbSalvar, SIGNAL(clicked()), this, SLOT(onpbSalvar()));
    connect(ui->pbPesquisarCategoria, SIGNAL(clicked()), this, SLOT(onpbPesquisarCategoria()));
}

bool CadastroParaCada::validaString(QString textoInformado)
{
    int upper = 0, lower = 0, number =0, special = 0, space = 0;
    for (int i=0; i<textoInformado.length(); i++){
        if (textoInformado[i] >= '0' && textoInformado[i] <= '9'){
            number++;
        } else if (textoInformado[i] >= 'A' && textoInformado[i] <= 'Z'){
            upper++;
        } else if (textoInformado[i] >= 'a' && textoInformado[i] <= 'z'){
            lower++;
        } else if (textoInformado[i] == ' ') {
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

bool CadastroParaCada::validaCampos()
{
    double ValorFinalProduto = 0;
    CadastroProduto* cadastroProduto = new CadastroProduto;
    if (onleDescricao() && onleValor() && onleCategoria()){        
        QStringList valorProduto;
        if (!ui->leValor->text().isEmpty()){
            valorProduto = ui->leValor->text().split(" ");
        }

        int sizeValor = valorProduto.length();
        QString valorNumeros = " ";
        for (int i=0; i<sizeValor; i++){
            valorNumeros = valorProduto.at(1);
        }

        ValorFinalProduto = valorNumeros.toDouble();

        CadastroCategoria* cadastroCategoria = new CadastroCategoria;
        if (!cadastroCategoria->verificaSeExiste(ui->leCategoria->text().toUpper())){
            QMessageBox::about(this, "Erro!", "Dados informados não existem!");
            ui->leCategoria->clear();
            ui->leCategoria->setFocus();
        } else {
            if (VerificaSeEhNumero(ui->leCategoria->text())){
                QString id = ui->leCategoria->text();
                QString descricao = cadastroCategoria->getDescricaoCategoria(id.toInt());
                ui->leCategoria->setText(id + " - " + descricao);
                qDebug() << "Log: usuário informou categoria com sucesso!";
            } else{
                QString descCategoria = ui->leCategoria->text().toUpper();
                int idCateg = cadastroCategoria->RetornaIdAtravesdaDescricao(descCategoria);
                ui->leCategoria->setText(QString::number(idCateg) + " - " + descCategoria);
                qDebug() << "Log: usuário informou categoria com sucesso!";
            }
            QStringList categoriaProduto;
            if (!(ui->leCategoria->text().isEmpty())){
                categoriaProduto = ui->leCategoria->text().split(" - ");
            }
            int sizeCategoria = categoriaProduto.length();
            QString idCategoria = " ";
            for (int i=0; i<sizeCategoria; i++){
                idCategoria = categoriaProduto.at(0);
            }
            int identificacaoCategoria = idCategoria.toInt();
            cadastroProduto->cadastrarNovoProduto(ui->leDescricao->text().toUpper(), ValorFinalProduto, identificacaoCategoria);
            return true;
        }
    }
    return false;
}

bool CadastroParaCada::VerificaSeEhNumero(QString s)
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

void CadastroParaCada::on_pbLimpar_clicked()
{

}
