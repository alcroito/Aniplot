#ifndef NEWEVENTDIALOG_H
#define NEWEVENTDIALOG_H

#include <QDialog>
#include <QTime>

namespace Ui {
    class NewEventDialog;
}

namespace Phonon {
    class MediaObject;
}

class NewEventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewEventDialog(QWidget *parent = 0);
    ~NewEventDialog();

private:
    Ui::NewEventDialog *ui;
    QString filename;
    Phonon::MediaObject* media_object;

private slots:
    void on_screenshotButton_clicked();
    void on_closeButton_clicked();
    void on_stopButton_clicked();
    void on_playButton_clicked();
    void on_openVideoButton_clicked();
    void changeCurrentTimePlayback(qint64 time);
};

#endif // NEWEVENTDIALOG_H
