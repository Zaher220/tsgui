#include "dbconnection.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

DBCOnnection::DBCOnnection(QObject *parent) : QObject(parent)
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("termospiro.db");
    if(m_database.open()) {
        qDebug()<<m_database.tables();
        qDebug()<<"Connected to database";
    } else {
        QMessageBox msg;
        msg.setText("Не удалось подсоединится к базе данных. Проверьте права доступа. " + m_database.lastError().text());
        msg.show();
        qDebug()<<"Not connected to database";
    }
}
