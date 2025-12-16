#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class DatabaseManager
{
public:
    DatabaseManager();
    bool openDatabase();

private:
    QSqlDatabase db;
};

#endif
