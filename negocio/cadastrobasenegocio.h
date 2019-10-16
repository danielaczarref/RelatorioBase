#ifndef CADASTROBASENEGOCIO_H
#define CADASTROBASENEGOCIO_H

#include <QObject>

class CadastroBaseNegocio : public QObject
{
    Q_OBJECT
public:
    explicit CadastroBaseNegocio(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CADASTROBASENEGOCIO_H