#include <QPainter>
#include "resizehandle.h"

ResizeHandle::ResizeHandle()
{
}


QRectF ResizeHandle::boundingRect() const {
    return QRect(-5, -5, 10, 10);
}
QPainterPath ResizeHandle::shape() const {
    QPainterPath path;
    path.addEllipse(-5, -5, 10, 10);
    return path;

}
void ResizeHandle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-5, -5, 10, 10);
}

void ResizeHandle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsItem::mousePressEvent(event);
}

void ResizeHandle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}
