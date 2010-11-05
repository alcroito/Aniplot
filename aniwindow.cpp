#include "aniwindow.h"
#include "ui_aniwindow.h"
#include "neweventdialog.h"

AniWindow::AniWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AniWindow), event_dialog(NULL)
{
    ui->setupUi(this);
}

AniWindow::~AniWindow()
{
    delete ui;
}

void AniWindow::on_addEventButton_clicked()
{
    if (!event_dialog) {
        event_dialog = new NewEventDialog(this);
    }
    event_dialog->show();

}
