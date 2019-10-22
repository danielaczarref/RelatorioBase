#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <QObject>

class Categoria : public QObject
{
    Q_OBJECT
public:
    explicit Categoria(QObject *parent = 0);
    //Categoria();
    long long getIdCategoria() const;
    void setIdCategoria(long long value);

    QString getDescCategoria() const;
    void setDescCategoria(const QString &value);

    QString getDescSecao() const;
    void setDescSecao(const QString &value);

    long long getIdSecao() const;
    void setIdSecao(long long value);

private:
    long long idCategoria;
    QString descCategoria;
    QString descSecao;
    long long idSecao;
};

#endif // CATEGORIA_H
