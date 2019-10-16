#ifndef FILIAL_H
#define FILIAL_H

#include <QObject>

class Filial : public QObject
{
    Q_OBJECT

public:
    explicit Filial(QObject *parent = 0);

    long long getIdFilial() const;
    void setIdFilial(long long value);

    QString getDescFilial() const;
    void setDescFilial(const QString &value);

private:
    long long idFilial;
    QString descFilial;
};

#endif // FILIAL_H
