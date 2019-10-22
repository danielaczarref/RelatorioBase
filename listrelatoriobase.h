#ifndef LISTRELATORIOBASE_H
#define LISTRELATORIOBASE_H

#include <QDialog>
#include "negocio/filtro.h"

namespace Ui {
class ListRelatorioBase;
}

class ListRelatorioBase : public QDialog
{
    Q_OBJECT

public:
    explicit ListRelatorioBase(Filtro* filtro, QWidget *parent = 0);
    ~ListRelatorioBase();

private:
    Ui::ListRelatorioBase *ui;
};

#endif // LISTRELATORIOBASE_H
