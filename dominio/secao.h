#ifndef SECAO_H
#define SECAO_H
#include <QObject>


class Secao : public QObject
{
    Q_OBJECT
public:
    explicit Secao(QObject *parent = 0);
    //Secao();
    long long getIdSecao() const;
    void setIdSecao(long long value);

    QString getDescSecao() const;
    void setDescSecao(const QString &value);

    long long getIdDepartamento() const;
    void setIdDepartamento(long long value);

    QString getDescDepartamento() const;
    void setDescDepartamento(const QString &value);

private:
    long long idSecao;
    QString descSecao;
    long long idDepartamento;
    QString descDepartamento;
};

#endif // SECAO_H
