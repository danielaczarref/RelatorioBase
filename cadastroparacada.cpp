#include "cadastroparacada.h"
#include "ui_cadastroparacada.h"

CadastroParaCada::CadastroParaCada(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastroParaCada)
{
    ui->setupUi(this);
}

CadastroParaCada::~CadastroParaCada()
{
    delete ui;
}
