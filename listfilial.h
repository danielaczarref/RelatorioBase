#ifndef LISTFILIAL_H
#define LISTFILIAL_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class ListFilial;
}

class ListFilial : public QDialog
{
    Q_OBJECT

public:
    explicit ListFilial(QWidget *parent = 0);
    ~ListFilial();
    void configuracaoInicial();
    void preencherRelatorioFilial();
    void setConnects();
    QString getId();

private:
    Ui::ListFilial *ui;
    QString _idFilial;
private slots:
     void clicouEmFilial(QTableWidgetItem* item);
};

#endif // LISTFILIAL_H
