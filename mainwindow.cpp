#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cadastro.h"
#include "relatorio.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Cadastro* telacadastro = new Cadastro();
    //telacadastro->show();
    Relatorio* relt = new Relatorio();
    relt->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}
