#include "stats_label.h"
StatsLabel::StatsLabel(QString default_text, QWidget * parent):
    QLabel(parent),
    default_text(default_text)
{
    setText(default_text);
}
void StatsLabel::process(QString text)
{
    setText(text);
}
void StatsLabel::clear()
{
    LastValueListenerBackgroundService<QString>::clear();
    setText(default_text);
}
