#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include "resizehandle.h"
#include "screenshotselectorborder.h"

ResizeHandle::ResizeHandle()
{
    setFlag(ItemIsMovable);
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


void ResizeHandle::mouseMoveEvent ( QGraphicsSceneMouseEvent * event ) {
    QPointF curr = event->scenePos();
    rect = mapRectToScene(static_cast<ScreenshotSelectorBorder*> (this->parentItem())->rect());
    qint32 size;

    if (prev.x() < (rect.width() + rect.x()) / 2) { //left
	if (prev.y() != (rect.height() + rect.y()) / 2 ) { //not middle
	    size = curr.y() - prev.y();
	    if (prev.y() > (rect.height() + rect.y()) /2) { //bottom
		size = -size;
	    }
	    rect.setY(rect.y() + size);
	    //rect.setHeight(rect.height() + size);
	}
	size = curr.x() - prev.x();
	rect.setX(rect.x() + size);
	//rect.setWidth(rect.width() + size);
    }
    else if (prev.x() > (rect.width() + rect.x()) / 2) //right <=====
    {
	if (prev.y() != (rect.height() + rect.y()) / 2) // not middle
	{
	    size = prev.y() - curr.y();
	    if (prev.y() > (rect.height() + rect.y()) / 2) //bottom
		size = -size;
	    else
		curr.setY(curr.y() + size);
	    rect.setHeight(rect.height() + size);
	}
	size = curr.x() - prev.x();
	rect.setWidth(rect.width() + size);
    }
    //else if (prev.x() == (rect.width() + rect.x()) / 2) // center
    else // center
    {

	size = prev.y() - curr.y(); // <======
	if (prev.y() > (rect.height() + rect.y()) / 2) // bottom
	    size = -size;
	else
	    curr.setY(curr.y() + size);
	//rect.setHeight(rect.height() + size);
    }

    static_cast<ScreenshotSelectorBorder*> (this->parentItem())->setRect(mapRectFromScene(rect));
    prev = event->scenePos();
    QGraphicsItem::mouseMoveEvent(event);

}

void ResizeHandle::setPrev(QPointF val) {
    prev = val;
}
