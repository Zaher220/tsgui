#ifndef PATIENTRESEARCHSLIST_H
#define PATIENTRESEARCHSLIST_H

#include <QWidget>
#include <QSqlRelationalTableModel>

namespace Ui {
class PatientResearchsList;
}

class PatientResearchsList : public QWidget
{
    Q_OBJECT

public:
    explicit PatientResearchsList(QWidget *parent = 0);
    ~PatientResearchsList();
signals:
    void ResearchId(int);
    void newResearch();
    void newResearchWithId(int);
public slots:
    void setPatiendId(int id);
    void setCurrentResearch(QModelIndex index);
private slots:
    void on_newExamButton_clicked();

private:
    Ui::PatientResearchsList *ui;
    QSqlRelationalTableModel *m_researchs = nullptr;
};

#endif // PATIENTRESEARCHSLIST_H
