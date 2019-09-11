#ifndef STATS_TAB_H
#define STATS_TAB_H
#include <QVBoxLayout>
#include <QLabel>
class StatsTab: public QWidget
{
    QVBoxLayout * layout = new QVBoxLayout(this);
    public:
    StatsTab(QWidget * parent = Q_NULLPTR);
    void addStats(QLabel *);
};
#endif
