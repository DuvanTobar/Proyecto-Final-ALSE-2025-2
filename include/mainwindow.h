#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int userId, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addRecordButton_clicked();
    void on_exportButton_clicked();

private:
    void loadData();

    Ui::MainWindow *ui;
    int currentUserId;
};

#endif
