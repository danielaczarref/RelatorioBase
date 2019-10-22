#ifndef LISTDEPARTAMENTO_H
#define LISTDEPARTAMENTO_H

#include <QDialog>

namespace Ui {
class listDepartamento;
}

class listDepartamento : public QDialog
{
    Q_OBJECT

public:
    explicit listDepartamento(QWidget *parent = 0);
    ~listDepartamento();

private:
    Ui::listDepartamento *ui;
};

#endif // LISTDEPARTAMENTO_H
