#include "researchwidget.h"
#include "ui_researchwidget.h"

ResearchWidget::ResearchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResearchWidget)
{
    ui->setupUi(this);
    connect(&m_device, &Ioton::sendSignalsAndParams, this, &ResearchWidget::setSignalsAndParams);
    ui->verticalLayoutAllPlotter->addWidget(&m_gpkotter);
}

ResearchWidget::~ResearchWidget()
{
    delete ui;
}

void ResearchWidget::newResearch(int id_patient)
{
    if (id_patient <= 0)
        return;
}

void ResearchWidget::on_startExam_clicked()
{
    m_device.beginResearch();
}

void ResearchWidget::on_stopExam_clicked()
{
    m_device.endResearch();
}

void ResearchWidget::setSignalsAndParams(parameters params, ADCData data)
{
    ;
}

void ResearchWidget::setPramsToWidget(parameters params)
{
    ;
}

void ResearchWidget::setSensorSignals(ADCData data)
{
    ;
}
