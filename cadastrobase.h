#ifndef CADASTROBASE_H
#define CADASTROBASE_H

#include <QObject>

class CadastroBase : public QObject
{
    Q_OBJECT
public:
    explicit CadastroBase(QObject *parent = nullptr);

    long long id() const;
    void setId(long long id);

    QString categoria() const;
    void setCategoria(const QString &categoria);

    QString produto() const;
    void setProduto(const QString &produto);

    QString base() const;
    void setBase(const QString &base);

private:
    long long _id;
    QString _categoria;
    QString _produto;
    QString _base;
};

#endif // CADASTROBASE_H
