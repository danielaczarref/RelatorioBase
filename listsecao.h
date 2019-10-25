#ifndef LISTSECAO_H
#define LISTSECAO_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class ListSecao;
}

class ListSecao : public QDialog
{
    Q_OBJECT

public:
    explicit ListSecao(QWidget *parent = 0);
    ~ListSecao();

    void configuracaoInicial();
    void preencherRelatorioSecao();
    void setConnects();
    QString getId();


private:
    Ui::ListSecao *ui;
    QString _idSecao;
private slots:
     void clicouEmSecao(QTableWidgetItem* item);
};

#endif // LISTSECAO_H
