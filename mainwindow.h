#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "db/dbconnection.h"
#include "forms/patientslistwidget.h"
#include "forms/patientresearchslist.h"
#include "forms/researchwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DBCOnnection m_db_connection;
    PatientsListWidget m_patients_list;
    PatientResearchsList m_research_list;
    ResearchWidget m_research;
};

#endif // MAINWINDOW_H
