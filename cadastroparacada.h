#ifndef CADASTROPARACADA_H
#define CADASTROPARACADA_H

#include <QDialog>

namespace Ui {
class CadastroParaCada;
}

class CadastroParaCada : public QDialog
{
    Q_OBJECT

public:
    explicit CadastroParaCada(QWidget *parent = 0);
    ~CadastroParaCada();
private slots:
    void onpbPesquisarCategoria();
    void onpbSalvar();
    bool onleDescricao();
    bool onleValor();
    bool onleCategoria();
    void configuracaoInicial();
    void setConnects();
    bool validaString(QString textoInformado);
    bool validaCampos ();
    bool VerificaSeEhNumero(QString s);

private slots:
    void on_pbLimpar_clicked();

private:
    Ui::CadastroParaCada *ui;
};

#endif // CADASTROPARACADA_H
