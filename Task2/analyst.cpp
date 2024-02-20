#include "analyst.h"
#include <QDebug>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QGridLayout>
#include <QWidget>
#include <QtCharts/QChartView>
#include <QPainter>
#include "qcustomplot.h"

QT_CHARTS_USE_NAMESPACE

Analyst::Analyst(QObject *parent) : QObject(parent) {}

void Analyst::addNewStatistics(const QString &tagName, uint64_t time, uint64_t num) {
    if (!m_statistics.contains(tagName)) {
        m_statistics[tagName] = QVector<QPair<uint64_t, uint64_t>>();
    }
    m_statistics[tagName].append(qMakePair(time, num));
}

void Analyst::showStatistics(const QString &tagName) {
    if (!m_statistics.contains(tagName)) {
        qDebug() << "No statistics available for tag" << tagName;
        return;
    }

    const QVector<QPair<uint64_t, uint64_t>> &data = m_statistics[tagName];


    QChart *chart = new QChart();
    QLineSeries *series = new QLineSeries();

    for (const auto &pair : data) {
        series->append(pair.second, pair.first);
    }

    chart->addSeries(series);
    chart->setTitle(tagName);
    chart->createDefaultAxes();
    chart->axisX()->setTitleText("Parameter n");
    chart->axisY()->setTitleText("Average Execution Time(microseconds)");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QWidget *widget = new QWidget();
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(chartView);
    widget->setLayout(layout);
    widget->resize(800, 600);
    widget->show();

}
