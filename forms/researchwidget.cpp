#include "researchwidget.h"
#include "ui_researchwidget.h"

ResearchWidget::ResearchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResearchWidget)
{
    ui->setupUi(this);
    connect(&m_device, &Ioton::sendSignalsAndParams, this, &ResearchWidget::setSignalsAndParams);
    connect(&m_device, &Ioton::sendSignals, this, &ResearchWidget::setSensorSignals);
    ui->verticalLayoutAllPlotter->addWidget(&m_gpkotter);
    //m_gpkotter.appendData()
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

void ResearchWidget::setPatiendId(int pid)
{

}

void ResearchWidget::on_startExam_clicked()
{
    m_device.beginResearch(180000);
}

void ResearchWidget::on_stopExam_clicked()
{
    m_device.endResearch();
}

void ResearchWidget::setSignalsAndParams(parameters params, ADCData data)
{
    m_gpkotter.appendADCData(data);
}

void ResearchWidget::setPramsToWidget(parameters params)
{
    ;
}

void ResearchWidget::setSensorSignals(ADCData data)
{
    m_gpkotter.appendADCData(data);
}
