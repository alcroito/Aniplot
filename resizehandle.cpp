#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
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

bool ResizeHandle::numberIsWithinLimit(qreal number, qreal limit, qreal delta) {
    if ((number < (limit + delta)) && (number > (limit - delta)))
	return true;
    else
	return false;
}

void ResizeHandle::mouseMoveEvent ( QGraphicsSceneMouseEvent * event ) {
    QPointF curr = event->scenePos();
    rect = static_cast<ScreenshotSelectorBorder*> (this->parentItem())->rect();
    QRectF old_rect = rect;
    qreal size_x;
    qreal size_y;

    // Center
    if ((numberIsWithinLimit(prev.x(), rect.width() / 2 + rect.x(), 25))) {
	size_y = curr.y() - prev.y();
	// Top
	if (prev.y() < rect.height() / 2 + rect.y()) {
	    rect.setY(curr.y() + size_y);
	}
	// Bottom
	else {
	    rect.setHeight(rect.height() + size_y);
	}
    }
    // Left
    else if (prev.x() < rect.width() / 2  + rect.x()) {
	// Not Middle
	if (!numberIsWithinLimit(prev.y(), rect.height() / 2 + rect.y(), 25)) {
	    size_y = curr.y() - prev.y();
	    // Top
	    if (prev.y() < rect.height() / 2 + rect.y()) {
		rect.setY(rect.y() + size_y);
	    // Bottom
	    } else {
		rect.setHeight(rect.height() + size_y);
	    }
	}
	size_x = curr.x() - prev.x();
	rect.setX(rect.x() + size_x);
    }
    // Right
    else if (prev.x() > rect.width() / 2 + rect.x()) {
	// Not Middle
	if (!numberIsWithinLimit(prev.y(), rect.height() / 2 + rect.y(), 25)) {
	    size_y = curr.y() - prev.y();
	    // Top
	    if (prev.y() < rect.height() / 2 + rect.y()) {
		rect.setY(rect.y() + size_y);
	    }
	    // Bottom
	    else {
		rect.setHeight(rect.height() + size_y);
	    }
	}
	size_x = curr.x() - prev.x();
	rect.setWidth(rect.width() + size_x);
    }

    static_cast<ScreenshotSelectorBorder*> (this->parentItem())->setRect(rect);
    prev = event->scenePos();
    setPos(x() + size_x, y() + size_y);

    qDebug() << "New:" << rect << " Old:" << old_rect;
    static_cast<ScreenshotSelectorBorder*> (this->parentItem())->emitResized(rect, old_rect);

    QGraphicsItem::mouseMoveEvent(event);
}

void ResizeHandle::reposition(QRectF new_rect, QRectF old_rect) {
    QPointF curr = this->scenePos();
    qreal x = new_rect.x();
    qreal y = new_rect.y();
    qreal w = new_rect.width();
    qreal h = new_rect.height();

    // Middle
    if ((numberIsWithinLimit(curr.x(), old_rect.width() / 2 + old_rect.x(), 25))) {
	// Top
	if (curr.y() < old_rect.height() / 2 + old_rect.y()) {
	    this->setPos(x + w/2, y);
	}
	// Bottom
	else {
	    this->setPos(x + w/2, y + h);
	}
    }
    // Left
    else if (curr.x() < old_rect.width() / 2  + old_rect.x()) {
	// Not Center
	if (!numberIsWithinLimit(curr.y(), old_rect.height() / 2 + old_rect.y(), 25)) {
	    // Top
	    if (curr.y() < old_rect.height() / 2 + old_rect.y()) {
		this->setPos(x, y);
	    // Bottom
	    } else {
		this->setPos(x, y + h);
	    }
	// Center
	} else {
	    this->setPos(x, y + h/2);
	}

    }
    // Right
    else if (curr.x() > old_rect.width() / 2 + old_rect.x()) {
	// Not Center
	if (!numberIsWithinLimit(curr.y(), old_rect.height() / 2 + old_rect.y(), 25)) {
	    // Top
	    if (curr.y() < old_rect.height() / 2 + old_rect.y()) {
		this->setPos(x + w, y);
	    }
	    // Bottom
	    else {
		this->setPos(x + w, y + h);
	    }
	// Center
	} else {
	    this->setPos(x + w, y + h/2);
	}
    }
}

void ResizeHandle::setPrev(QPointF val) {
    prev = val;
}
