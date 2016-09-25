#include "researchwidget.h"
#include "ui_researchwidget.h"

ResearchWidget::ResearchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResearchWidget)
{
    ui->setupUi(this);
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
