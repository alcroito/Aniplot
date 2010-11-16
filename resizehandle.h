#ifndef RESIZEHANDLE_H
#define RESIZEHANDLE_H

#include <QGraphicsItem>
#include <QObject>

class ResizeHandle : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    ResizeHandle();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPrev(QPointF val);

public slots:
    void reposition(QRectF new_rect, QRectF old_rect);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    bool numberIsWithinLimit(qreal number, qreal limit, qreal delta);

    QPointF prev;
    QRectF rect;

};

#endif // RESIZEHANDLE_H
