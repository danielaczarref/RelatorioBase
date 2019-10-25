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

private:
    Ui::CadastroParaCada *ui;
};

#endif // CADASTROPARACADA_H
