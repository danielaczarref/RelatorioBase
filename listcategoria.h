#ifndef LISTCATEGORIA_H
#define LISTCATEGORIA_H

#include <QDialog>

namespace Ui {
class ListCategoria;
}

class ListCategoria : public QDialog
{
    Q_OBJECT

public:
    explicit ListCategoria(QWidget *parent = 0);
    ~ListCategoria();

private:
    Ui::ListCategoria *ui;
};

#endif // LISTCATEGORIA_H
