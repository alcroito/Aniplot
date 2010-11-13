#ifndef SCREENSHOTSELECTORBORDER_H
#define SCREENSHOTSELECTORBORDER_H

#include <QGraphicsRectItem>

class QGraphicsSceneMouseEvent;
class ResizeHandle;

class ScreenshotSelectorBorder : public QGraphicsRectItem
{
public:
    //ScreenshotSelectorBorder();
    ScreenshotSelectorBorder(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = 0);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

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
