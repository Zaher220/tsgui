#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->verticalLayoutPatients->addWidget(&m_patients_list);
    ui->verticalLayoutResearchs->addWidget(&m_research_list);

    connect(&m_patients_list, &PatientsListWidget::patientId, &m_research_list, &PatientResearchsList::setPatiendId);
}

MainWindow::~MainWindow()
{
    delete ui;
}
