#ifndef LISTSECAO_H
#define LISTSECAO_H

#include <QDialog>

namespace Ui {
class ListSecao;
}

class ListSecao : public QDialog
{
    Q_OBJECT

public:
    explicit ListSecao(QWidget *parent = 0);
    ~ListSecao();

private:
    Ui::ListSecao *ui;
};

#endif // LISTSECAO_H
