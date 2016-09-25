#include "patientslistwidget.h"
#include "ui_patientslistwidget.h"
#include <QDebug>
#include <QSqlRecord>
#include <QAbstractItemView>

PatientsListWidget::PatientsListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientsListWidget)
{
    ui->setupUi(this);

    m_patients = new QSqlRelationalTableModel();

    m_patients->setTable("patients");
    m_patients->setHeaderData(m_patients->fieldIndex("FirstName"), Qt::Horizontal, tr("Имя"));
    m_patients->setHeaderData(m_patients->fieldIndex("SecondName"), Qt::Horizontal, tr("Фамилия"));
    m_patients->setHeaderData(m_patients->fieldIndex("LastName"), Qt::Horizontal, tr("Отчество"));
    m_patients->setHeaderData(m_patients->fieldIndex("MVL"), Qt::Horizontal, tr("МВЛ"));
    m_patients->select();

    ui->patientsTableView->setModel(m_patients);
    ui->patientsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->patientsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->patientsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->patientsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->patientsTableView->hideColumn(0);
    ui->patientsTableView->hideColumn(4);
    ui->patientsTableView->hideColumn(5);

    connect(ui->patientsTableView, &QTableView::doubleClicked, this, &PatientsListWidget::setCurrentPatient);
}

PatientsListWidget::~PatientsListWidget()
{
    delete ui;
}

void PatientsListWidget::setCurrentPatient(QModelIndex index)
{
    QSqlRecord record = m_patients->record(index.row());
    int id_patient = record.value(0).toInt();
    emit patientId(id_patient);
}
