#ifndef LED_INDICATOR_H
#define LED_INDICATOR_H
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QWidget>
#include "base_classes/last_value_listener.h"
#define RED_IMAGE "assets/red.png"
#define GREEN_IMAGE "assets/green.png"
class LedIndicator: public LastValueListener<bool>, public QWidget
{
	public:
		static QPixmap * red;
		static QPixmap * green;
		LedIndicator(QWidget * parent = 0);
		void recieve(bool) override;
		void clear() override;
		void paintEvent(QPaintEvent *) override;
};
#endif
