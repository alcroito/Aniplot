#include <QPen>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>

#include "screenshotselectorborder.h"
#include "resizehandle.h"


//ScreenshotSelectorBorder::ScreenshotSelectorBorder()
//{
//    setFlag(ItemIsMovable);
//    setCacheMode(DeviceCoordinateCache);
//    setCursor(Qt::PointingHandCursor);
//}

ScreenshotSelectorBorder::ScreenshotSelectorBorder(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, w, h, parent),
    top_left(new ResizeHandle()), top_middle(new ResizeHandle()), top_right(new ResizeHandle()),
    center_left(new ResizeHandle()), center_right(new ResizeHandle()),
    bottom_left(new ResizeHandle()), bottom_middle(new ResizeHandle()), bottom_right(new ResizeHandle())
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
    top_middle->setPos(x + w/2, y);
    top_middle->setParentItem(this);
    top_middle->setZValue(10);
    top_middle->setPrev(top_middle->scenePos());
    top_right->setPos(x + w, y);
    top_right->setParentItem(this);
    top_right->setZValue(10);
    top_right->setPrev(top_right->scenePos());

    center_left->setPos(x, y + h/2);
    center_left->setParentItem(this);
    center_left->setZValue(10);
    center_left->setPrev(center_left->scenePos());
    center_right->setPos(x + w, y + h/2);
    center_right->setParentItem(this);
    center_right->setZValue(10);
    center_right->setPrev(center_right->scenePos());

    bottom_left->setPos(x, y + h);
    bottom_left->setParentItem(this);
    bottom_left->setZValue(10);
    bottom_left->setPrev(bottom_left->scenePos());
    bottom_middle->setPos(x + w/2, y + h);
    bottom_middle->setParentItem(this);
    bottom_middle->setZValue(10);
    bottom_middle->setPrev(bottom_middle->scenePos());
    bottom_right->setPos(x + w, y + h);
    bottom_right->setParentItem(this);
    bottom_right->setZValue(10);
    bottom_right->setPrev(bottom_right->scenePos());


}

void ScreenshotSelectorBorder::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
}

void ScreenshotSelectorBorder::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}
