#include "patientresearchslist.h"
#include "ui_patientresearchslist.h"
#include <QDebug>
#include <QSqlRecord>
#include <QAbstractItemView>

PatientResearchsList::PatientResearchsList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientResearchsList)
{
    ui->setupUi(this);
}

PatientResearchsList::~PatientResearchsList()
{
    delete ui;
}

void PatientResearchsList::setPatiendId(int id)
{
    if( m_researchs != nullptr )
        delete m_researchs;

    m_researchs = new QSqlRelationalTableModel();

    m_researchs->setTable("researchs");
    m_researchs->setHeaderData(m_researchs->fieldIndex("Date"), Qt::Horizontal, tr("Дата"));
    m_researchs->setFilter(" fk_patient = " + QString::number(id));
    m_researchs->select();

    ui->researchsTableView->setModel(m_researchs);
    ui->researchsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->researchsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->researchsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->researchsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->researchsTableView->hideColumn(m_researchs->fieldIndex("idResearch"));
    ui->researchsTableView->hideColumn(m_researchs->fieldIndex("volume"));
    ui->researchsTableView->hideColumn(m_researchs->fieldIndex("tempin"));
    ui->researchsTableView->hideColumn(m_researchs->fieldIndex("tempout"));
    ui->researchsTableView->hideColumn(m_researchs->fieldIndex("fk_patient"));

    connect(ui->researchsTableView, &QTableView::doubleClicked, this, &PatientResearchsList::setCurrentResearch);
}

void PatientResearchsList::setCurrentResearch(QModelIndex index)
{
    QSqlRecord record = m_researchs->record(index.row());
    int id_research = record.value(0).toInt();
    emit ResearchId(id_research);
}

void PatientResearchsList::on_newExamButton_clicked()
{
    emit newResearch();
}
