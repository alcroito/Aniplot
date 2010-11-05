#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

#include "screenshotsave.h"
#include "ui_screenshotsave.h"
#include "screenshotselectorborder.h"

ScreenshotSave::ScreenshotSave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScreenshotSave)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(parent);
    ui->sceneView->setScene(scene);
    QGraphicsRectItem* selector = new QGraphicsRectItem(0, 0, 100, 100);
    scene->addItem(selector);
}

ScreenshotSave::ScreenshotSave(const QPixmap& screenshot_pixmap, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScreenshotSave)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(parent);
    ui->sceneView->setScene(scene);
    ScreenshotSelectorBorder* selector = new ScreenshotSelectorBorder(175, 75, 100, 100);

    scene->addItem(selector);
    QGraphicsPixmapItem* screenshot = new QGraphicsPixmapItem(screenshot_pixmap);
    screenshot->setPos(0, 0);
    screenshot->setZValue(1);
    scene->addItem(screenshot);
}

ScreenshotSave::~ScreenshotSave()
{
    delete ui;
}
