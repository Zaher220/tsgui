#ifndef RESEARCHWIDGET_H
#define RESEARCHWIDGET_H

#include <QWidget>
#include "device/ioton.h"

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
private:
    Ui::ResearchWidget *ui;
    Ioton m_device;
    int m_patient_id = -1;
};

#endif // RESEARCHWIDGET_H
