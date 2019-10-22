#ifndef LISTPRODUTO_H
#define LISTPRODUTO_H

#include <QDialog>

namespace Ui {
class ListProduto;
}

class ListProduto : public QDialog
{
    Q_OBJECT

public:
    explicit ListProduto(QWidget *parent = 0);
    ~ListProduto();

private:
    Ui::ListProduto *ui;
};

#endif // LISTPRODUTO_H
