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

    ui->comboBox->addItem(tr("Page 1"));
    ui->comboBox->addItem(tr("Page 2"));
    ui->comboBox->addItem(tr("Page 3"));
    ui->comboBox->addItem(tr("Page 4"));
    ui->comboBox->addItem(tr("Page 5"));

    connect(ui->comboBox, SIGNAL(activated(int)), ui->stackedWidgetPages, SLOT(setCurrentIndex(int)));
    connect(&m_patients_list, &PatientsListWidget::patientId, &m_research_list, &PatientResearchsList::setPatiendId);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonBack_clicked()
{
    size_t index = ui->stackedWidgetPages->currentIndex()-1;
    ui->stackedWidgetPages->setCurrentIndex(index);
}
