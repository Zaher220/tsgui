#ifndef PLOTTERWIDJET_H
#define PLOTTERWIDJET_H

#include <QWidget>
#include "qcustomplot.h"
#include "datatypes.h"
//#include "examscontrollerl.h"
//#include "ui_plotterwidjet.h"
namespace Ui {
class PlotterWidjet;
}

class GraphsPlotter3 : public QWidget
{
    Q_OBJECT

public:
    explicit GraphsPlotter3(QWidget *parent = 0);
    ~GraphsPlotter3();
    void appendData(QVector<QVector<double > > data);
    void appendIntData(QVector<int> volume, QVector<int> tempin, QVector<int> tempout);
    void reset();
private slots:
    void on_PlotHorizontalScrollBar_valueChanged(int value);
    void xAxisChanged(QCPRange range);

    void setFullPatientGrapgicsData(VTT_Data data);

private:
    void initGraphs(QCustomPlot *graph, QPen pen);
    Ui::PlotterWidjet *ui;
    QVector<double> m_vol, m_tin, m_tout;
    int N = 10;//точек для показа
    int K = 0;//всего точек на графике
    double l = 0;//Коэффициент трансформации

};

#endif // PLOTTERWIDJET_H
