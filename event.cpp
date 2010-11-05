#include <QCursor>

#include "event.h"

Event::Event()
{
    setFlag(ItemIsMovable);
    setCacheMode(DeviceCoordinateCache);
    setCursor(Qt::PointingHandCursor);
}
