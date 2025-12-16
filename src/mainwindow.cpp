#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addrecorddialog.h"
#include "csvexporter.h"
#include <QSqlQuery>

MainWindow::MainWindow(int userId, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      currentUserId(userId)
{
    ui->setupUi(this);
    loadData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadData()
{
    ui->tableWidget->setRowCount(0);

    QSqlQuery query;
    query.prepare("SELECT date_time, weight, glucose_level, systolic_pressure, diastolic_pressure "
                  "FROM health_records WHERE user_id=?");
    query.addBindValue(currentUserId);
    query.exec();

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        for (int i = 0; i < 5; i++)
            ui->tableWidget->setItem(row, i,
                new QTableWidgetItem(query.value(i).toString()));
        row++;
    }
}

void MainWindow::on_addRecordButton_clicked()
{
    AddRecordDialog dlg(currentUserId, this);
    if (dlg.exec() == QDialog::Accepted)
        loadData();
}

void MainWindow::on_exportButton_clicked()
{
    CSVExporter exporter;
    exporter.exportToCSV(currentUserId);
}
