#ifndef RELATORIO_H
#define RELATORIO_H

#include <QWidget>
#include "negocio/filtro.h"
#include <QTableWidgetItem>

namespace Ui {
class Relatorio;
}
class Relatorio : public QWidget
{
    Q_OBJECT

public:
    explicit Relatorio(QWidget *parent = 0);
    ~Relatorio();

    void preencherRelatorio(Filtro* filtro);


private slots:
    void onCadastrarProdutoClicked();
    void onFiltrarClicked();
    void montarTw();
    void onVoltarClicked();

private:
    Ui::Relatorio *ui;
    void configuracaoInicial();

    void setConnects();

    Filtro* filtroCorreto;


private slots:
     void clicouProdutoSelecionado(QTableWidgetItem* item);
};

#endif // RELATORIO_H
