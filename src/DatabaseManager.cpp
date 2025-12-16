#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager()
{
    openDatabase();
}

bool DatabaseManager::openDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("health.db");

    if (!db.open()) {
        qDebug() << "Error DB:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;

    query.exec(
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT UNIQUE,"
        "password TEXT)"
    );

    query.exec(
        "CREATE TABLE IF NOT EXISTS health_records ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "user_id INTEGER,"
        "date_time TEXT,"
        "weight REAL,"
        "glucose_level REAL,"
        "systolic_pressure INTEGER,"
        "diastolic_pressure INTEGER)"
    );

    return true;
}
