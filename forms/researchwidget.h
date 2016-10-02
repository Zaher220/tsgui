#ifndef RESEARCHWIDGET_H
#define RESEARCHWIDGET_H

#include <QWidget>
#include "device/ioton.h"
#include "graphsplotter3.h"
#include "qcustomplot.h"

namespace Ui {
class ResearchWidget;
}

class ResearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ResearchWidget(QWidget *parent = 0);
    ~ResearchWidget();
public slots:
    void newResearch(int id_patient);
private slots:
    void on_startExam_clicked();
    void on_stopExam_clicked();
    void setSignalsAndParams(parameters params, ADCData data);
private:
    void setPramsToWidget(parameters params);
    void setSensorSignals(ADCData data);
    GraphsPlotter3 m_gpkotter;
    Ui::ResearchWidget *ui;
    Ioton m_device;
    int m_patient_id = -1;
};

#endif // RESEARCHWIDGET_H
