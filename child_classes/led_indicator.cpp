#include "led_indicator.h"
    QPixmap * LedIndicator::red = NULL; 
    QPixmap * LedIndicator::green = NULL;
LedIndicator::LedIndicator(QWidget * parent):
    QWidget(parent)
    {
        std::cout << "Creating led_ind";
        if (red == NULL)
        {
        LedIndicator::red = new QPixmap();
        LedIndicator::green = new QPixmap();          }
        if (red -> isNull())
        {
            red ->load(RED_IMAGE);
            green -> load(GREEN_IMAGE);
        }
    }
void LedIndicator::paintEvent(QPaintEvent* event)
{
    std::cout << "paint event" << std::endl;
    QPixmap * target;
    QPainter painter(this);
    if (last_value != NULL)
    {
        target = *last_value ? green : red;
    }
    else 
    {
        target = red;
    }
    painter.drawPixmap(QPoint(0,0), *target);
}
void LedIndicator::recieve(bool b)
{
    std::cout << "recieving" << std::endl;
    LastValueListener<bool>::recieve(b);
    update();
}
void LedIndicator::clear()
{
    std::cout << "clearing" << std::endl;
    LastValueListener<bool>::clear();
    update();
}
