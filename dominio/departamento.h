#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <QObject>

class Departamento : public QObject
{
    Q_OBJECT
public:
    explicit Departamento(QObject *parent = 0);

    //Departamento();
    long long getIdDepartamento() const;
    void setIdDepartamento(long long value);

    QString getDescDepartamento() const;
    void setDescDepartamento(const QString &value);

private:
    long long idDepartamento;
    QString descDepartamento;
};

#endif // DEPARTAMENTO_H
