#include <QPen>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>

#include "screenshotselectorborder.h"
#include "resizehandle.h"


ScreenshotSelectorBorder::ScreenshotSelectorBorder()
{
    setFlag(ItemIsMovable);
    setCacheMode(DeviceCoordinateCache);
    setCursor(Qt::PointingHandCursor);
}

ScreenshotSelectorBorder::ScreenshotSelectorBorder(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, w, h, parent), top_left(new ResizeHandle()), bottom_right(new ResizeHandle())
{
    // Setting some flags, hurr durr
    setFlag(ItemIsMovable);
    setCacheMode(DeviceCoordinateCache);
    setCursor(Qt::PointingHandCursor);

    // Changing rectangle color
    QPen pen;
    pen.setColor(Qt::white);
    setPen(pen);
    setZValue(5);

    // Setting resize handles
    top_left->setPos(x, y);
    top_left->setParentItem(this);
    bottom_right->setPos(x + w, y + h);
    bottom_right->setParentItem(this);
}

void ScreenshotSelectorBorder::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
}

void ScreenshotSelectorBorder::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}
