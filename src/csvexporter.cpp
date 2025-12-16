#include "csvexporter.h"
#include <QFile>
#include <QSqlQuery>
#include <QTextStream>

bool CSVExporter::exportToCSV(int userId)
{
    QFile file("health_records.csv");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "Fecha,Peso,Glucosa,Sistolica,Diastolica\n";

    QSqlQuery query;
    query.prepare(
        "SELECT date_time, weight, glucose_level, systolic_pressure, diastolic_pressure "
        "FROM health_records WHERE user_id=?"
    );
    query.addBindValue(userId);
    query.exec();

    while (query.next()) {
        out << query.value(0).toString() << ","
            << query.value(1).toString() << ","
            << query.value(2).toString() << ","
            << query.value(3).toString() << ","
            << query.value(4).toString() << "\n";
    }

    file.close();
    return true;
}
