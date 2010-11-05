#ifndef SCREENSHOTSAVE_H
#define SCREENSHOTSAVE_H

#include <QDialog>

namespace Ui {
    class ScreenshotSave;
}

class QGraphicsScene;

class ScreenshotSave : public QDialog
{
    Q_OBJECT

public:
    explicit ScreenshotSave(QWidget *parent = 0);
    explicit ScreenshotSave(const QPixmap& screenshot_pixmap, QWidget *parent = 0);
    ~ScreenshotSave();

private:
    Ui::ScreenshotSave *ui;
    QGraphicsScene* scene;
};

#endif // SCREENSHOTSAVE_H
