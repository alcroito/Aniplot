#ifndef RESIZEHANDLE_H
#define RESIZEHANDLE_H

#include <QGraphicsItem>

class ResizeHandle : public QGraphicsItem
{
public:
    ResizeHandle();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPrev(QPointF val);
protected:
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
   // void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    QPointF prev;
    QRectF rect;

};

#endif // RESIZEHANDLE_H
