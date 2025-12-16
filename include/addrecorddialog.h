#ifndef ADDRECORDDIALOG_H
#define ADDRECORDDIALOG_H

#include <QDialog>

namespace Ui {
class AddRecordDialog;
}

class AddRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecordDialog(int userId, QWidget *parent = nullptr);
    ~AddRecordDialog();

private slots:
    void on_saveButton_clicked();

private:
    Ui::AddRecordDialog *ui;
    int currentUserId;
};

#endif
