#ifndef LISTDEPARTAMENTO_H
#define LISTDEPARTAMENTO_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class listDepartamento;
}

class listDepartamento : public QDialog
{
    Q_OBJECT

public:
    explicit listDepartamento(QWidget *parent = 0);
    ~listDepartamento();

    void configuracaoInicial();
    void preencherRelatorioDeDepartamento();
    void setConnects();
    QString getId();

private:
    Ui::listDepartamento *ui;

    QString _idDepartamento;
private slots:
     void clicouEmDepartamentoSelecionado(QTableWidgetItem* item);
};

#endif // LISTDEPARTAMENTO_H
