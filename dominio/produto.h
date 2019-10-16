#ifndef PRODUTO_H
#define PRODUTO_H

#include <QObject>

class Produto : public QObject
{
    Q_OBJECT
public:
    explicit Produto(QObject *parent = 0);
   // Produto();
};

#endif // PRODUTO_H
