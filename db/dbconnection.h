#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QObject>
#include <QSqlDatabase>

class DBCOnnection : public QObject
{
    Q_OBJECT
public:
    explicit DBCOnnection(QObject *parent = 0);
signals:
public slots:
private:
    QSqlDatabase m_database;
};

#endif // DBCONNECTION_H
