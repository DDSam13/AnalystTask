#ifndef ANALYST_H
#define ANALYST_H

#include "qcustomplot.h"

#include <QObject>
#include <QString>
#include <QMap>
#include <QVector>

class Analyst : public QObject {
    Q_OBJECT

public:
    Analyst(QObject *parent = nullptr);

    void addNewStatistics(const QString &tagName, uint64_t time, uint64_t num);
    void showStatistics(const QString &tagName);

private:
    QMap<QString, QVector<QPair<uint64_t, uint64_t>>> m_statistics;

};

#endif // ANALYST_H
