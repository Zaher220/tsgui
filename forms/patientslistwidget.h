#ifndef PATIENTSLISTWIDGET_H
#define PATIENTSLISTWIDGET_H

#include <QWidget>
#include <QSqlRelationalTableModel>

namespace Ui {
class PatientsListWidget;
}

class PatientsListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PatientsListWidget(QWidget *parent = 0);
    ~PatientsListWidget();
signals:
    void patientId(int);
private slots:
    void setCurrentPatient(QModelIndex index);
private:
    Ui::PatientsListWidget *ui;
    QSqlRelationalTableModel *m_patients = nullptr;
};

#endif // PATIENTSLISTWIDGET_H
