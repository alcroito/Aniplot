#include <QFileDialog>
#include <QTime>
#include <Phonon/MediaObject>
#include <QDesktopServices>
#include <QPixmap>

#include "neweventdialog.h"
#include "ui_neweventdialog.h"
#include "screenshotsave.h"

NewEventDialog::NewEventDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEventDialog)
{
    ui->setupUi(this);
}

NewEventDialog::~NewEventDialog()
{
    delete ui;
}

void NewEventDialog::on_openVideoButton_clicked()
{
    filename = QFileDialog::getOpenFileName(this, tr("Open Video"),
        QDesktopServices::storageLocation(QDesktopServices::MoviesLocation), tr("Videos (*.avi *.mkv *.mp4)"));
    ui->player->play(filename);
    ui->seekSlider->setMediaObject(ui->player->mediaObject());
    media_object = ui->player->mediaObject();
    connect(media_object, SIGNAL(tick(qint64)), this, SLOT(changeCurrentTimePlayback(qint64)));
}

void NewEventDialog::on_playButton_clicked()
{
    ui->player->play();
}

void NewEventDialog::on_stopButton_clicked()
{
    ui->player->pause();
}

void NewEventDialog::changeCurrentTimePlayback(qint64 time) {
    QTime displayTime((time / (60000 * 60)) % 24, (time / 60000) % 60, (time / 1000) % 60);
    ui->currentTime->setText(displayTime.toString("hh:mm:ss"));

}

void NewEventDialog::on_closeButton_clicked()
{
    ui->player->stop();
}

void NewEventDialog::on_screenshotButton_clicked()
{
    QPixmap* pic = new QPixmap();
    *pic = pic->grabWidget(ui->player);
    ScreenshotSave* screenshot_save_dialog = new ScreenshotSave(*pic, this);
    screenshot_save_dialog->show();

}
