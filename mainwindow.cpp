#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pageResearchs->layout()->addWidget(&m_research_list);
    ui->pagePatients->layout()->addWidget(&m_patients_list);
    ui->pageResearch->layout()->addWidget(&m_research);

    connect(&m_patients_list, &PatientsListWidget::patientId, &m_research_list, &PatientResearchsList::setPatiendId);
    connect(&m_patients_list, &PatientsListWidget::patientId, &m_research, &ResearchWidget::setPatiendId);
    connect(&m_patients_list, &PatientsListWidget::gotoPatient, this, &MainWindow::setPatient);
    connect(&m_research_list, &PatientResearchsList::newResearch, this, &MainWindow::setNewResearch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonBack_clicked()
{
    size_t index = ui->stackedWidgetPages->currentIndex() - 1;
    ui->stackedWidgetPages->setCurrentIndex(index);
}

void MainWindow::setPatient()
{
    ui->stackedWidgetPages->setCurrentIndex(1);
}

void MainWindow::setNewResearch()
{
    ui->stackedWidgetPages->setCurrentIndex(2);
}
