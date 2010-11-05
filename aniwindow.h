#ifndef ANIWINDOW_H
#define ANIWINDOW_H

#include <QMainWindow>

namespace Ui {
    class AniWindow;
}

class NewEventDialog;

class AniWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AniWindow(QWidget *parent = 0);
    ~AniWindow();


private:
    Ui::AniWindow *ui;
    NewEventDialog* event_dialog;

private slots:
    void on_addEventButton_clicked();
};

#endif // ANIWINDOW_H
