#ifndef PLOTTERWIDJET_H
#define PLOTTERWIDJET_H

#include <QWidget>
#include "qcustomplot.h"
#include "datatypes.h"

namespace Ui {
class PlotterWidjet;
}

class GraphsPlotter3 : public QWidget
{
    Q_OBJECT

public:
    explicit GraphsPlotter3(QWidget *parent = 0);
    ~GraphsPlotter3();
    void appendADCData(ADCData data);
    void reset();
private slots:
    void on_PlotHorizontalScrollBar_valueChanged(int value);
    void xAxisChanged(QCPRange range);
private:
    void initGraphs(QCustomPlot *graph, QPen pen);
    Ui::PlotterWidjet *ui;
    QVector<double> m_vol, m_tin, m_tout;
    int N = 20000;//точек для показа
    int K = 0;//всего точек на графике
    double l = 0;//Коэффициент трансформации

};

#endif // PLOTTERWIDJET_H
