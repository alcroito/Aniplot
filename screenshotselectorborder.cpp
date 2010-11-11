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
    : QGraphicsRectItem(x, y, w, h, parent),
    top_left(new ResizeHandle()), top_middle(new ResizeHandle()), bottom_right(new ResizeHandle())
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
    top_left->setZValue(10);
    top_left->setPrev(top_left->scenePos());
    bottom_right->setPos(x + w, y + h);
    bottom_right->setParentItem(this);
    bottom_right->setZValue(10);
    bottom_right->setPrev(bottom_right->scenePos());
    top_middle->setPos(x + w/2, y);
    top_middle->setParentItem(this);
    top_middle->setZValue(10);
    top_middle->setPrev(top_middle->scenePos());
}

void ScreenshotSelectorBorder::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
}

void ScreenshotSelectorBorder::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}
