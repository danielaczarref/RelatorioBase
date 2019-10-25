#ifndef LISTRELATORIOBASE_H
#define LISTRELATORIOBASE_H

#include <QDialog>
#include "negocio/filtro.h"
#include <QTableWidgetItem>
#include "relatorio.h"

namespace Ui {
class ListRelatorioBase;
}

class ListRelatorioBase : public QDialog
{
    Q_OBJECT

public:
    explicit ListRelatorioBase(Filtro* filtro, QWidget *parent = 0);
    ~ListRelatorioBase();


private:
    Ui::ListRelatorioBase *ui;

     void setConnects();

     void configuracaoInicial();

     void preencherRelatorioBase();

     Filtro* filtroCorreto;

private slots:
     void clicouProdutoSelecionado(QTableWidgetItem* item);

};

#endif // LISTRELATORIOBASE_H
