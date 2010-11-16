#ifndef SCREENSHOTSELECTORBORDER_H
#define SCREENSHOTSELECTORBORDER_H

#include <QGraphicsRectItem>
#include <QObject>

class QGraphicsSceneMouseEvent;
class ResizeHandle;

class ScreenshotSelectorBorder : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ScreenshotSelectorBorder(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = 0);

    void emitResized(QRectF new_rect, QRectF old_rect);

signals:
    void resized(QRectF new_rect, QRectF old_rect);
private:
    ResizeHandle* top_left;
    ResizeHandle* top_middle;
    ResizeHandle* top_right;
    ResizeHandle* center_left;
    ResizeHandle* center_right;
    ResizeHandle* bottom_left;
    ResizeHandle* bottom_middle;
    ResizeHandle* bottom_right;

};

#endif // SCREENSHOTSELECTORBORDER_H
