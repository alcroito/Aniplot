#include <QtGui/QApplication>
#include "aniwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Music Player");
    a.setQuitOnLastWindowClosed(true);
    AniWindow w;
    w.show();

    return a.exec();
}
