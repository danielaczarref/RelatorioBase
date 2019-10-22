#ifndef ESTOQUEDAO_H
#define ESTOQUEDAO_H

#include <QObject>
#include "dominio/estoque.h"
#include "negocio/filtro.h"

class EstoqueDAO : public QObject
{
    Q_OBJECT
public:
    explicit EstoqueDAO(QObject *parent = nullptr);

    QList<Estoque*> recuperEstoque(Filtro* filtro);
};

#endif // ESTOQUEDAO_H
