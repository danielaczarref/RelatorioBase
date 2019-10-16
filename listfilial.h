#ifndef LISTFILIAL_H
#define LISTFILIAL_H

#include <QDialog>

namespace Ui {
class ListFilial;
}

class ListFilial : public QDialog
{
    Q_OBJECT

public:
    explicit ListFilial(QWidget *parent = 0);
    ~ListFilial();

private:
    Ui::ListFilial *ui;
};

#endif // LISTFILIAL_H
