#ifndef STATS_LABEL_H
#define STATS_LABEL_H
#include <QLabel>
#include "base_classes/last_value_listener_background_service.h"
class StatsLabel: public QLabel, public LastValueListenerBackgroundService<QString>
{
	QString default_text;
	void process(QString) override;
	public:
		StatsLabel(QString, QWidget * parent = Q_NULLPTR);
		void clear() override;
};
#endif
