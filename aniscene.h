#ifndef ANISCENE_H
#define ANISCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Event;

class AniScene : public QGraphicsView
{
    Q_OBJECT
public:
    explicit AniScene(QWidget *parent = 0);

signals:

public slots:

private:
    QGraphicsScene *scene;


};

#endif // ANISCENE_H
