#ifndef RELATORIO_H
#define RELATORIO_H

#include <QWidget>

namespace Ui {
class Relatorio;
}
class Relatorio : public QWidget
{
    Q_OBJECT

public:
    explicit Relatorio(QWidget *parent = 0);
    ~Relatorio();


private slots:
    void onCadastrarProdutoClicked();
    void onFiltrarClicked();
    void montarTw();
    void onVoltarClicked();

private:
    Ui::Relatorio *ui;
    void configuracaoInicial();

    void setConnects();
};

#endif // RELATORIO_H
