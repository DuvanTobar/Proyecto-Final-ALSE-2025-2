#include "addrecorddialog.h"
#include "ui_addrecorddialog.h"
#include <QSqlQuery>
#include <QMessageBox>

AddRecordDialog::AddRecordDialog(int userId, QWidget *parent)
    : QDialog(parent),
      ui(new Ui::AddRecordDialog),
      currentUserId(userId)
{
    ui->setupUi(this);
}

AddRecordDialog::~AddRecordDialog()
{
    delete ui;
}

void AddRecordDialog::on_saveButton_clicked()
{
    if (ui->weightSpin->value() <= 0) {
        QMessageBox::warning(this, "Error", "El peso debe ser mayor que 0");
        return;
    }

    QSqlQuery query;
    query.prepare(
        "INSERT INTO health_records "
        "(user_id, date_time, weight, glucose_level, systolic_pressure, diastolic_pressure) "
        "VALUES (?, datetime('now'), ?, ?, ?, ?)"
    );

    query.addBindValue(currentUserId);
    query.addBindValue(ui->weightSpin->value());
    query.addBindValue(ui->glucoseSpin->value());
    query.addBindValue(ui->systolicSpin->value());
    query.addBindValue(ui->diastolicSpin->value());

    query.exec();
    accept();
}
