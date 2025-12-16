#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    QString user = ui->usernameEdit->text();
    QString pass = ui->passwordEdit->text();

    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username=? AND password=?");
    query.addBindValue(user);
    query.addBindValue(pass);

    if (query.exec() && query.next()) {
        int userId = query.value(0).toInt();
        MainWindow *mw = new MainWindow(userId);
        mw->show();
        close();
    } else {
        QMessageBox::warning(this, "Error", "Credenciales incorrectas");
    }
}
