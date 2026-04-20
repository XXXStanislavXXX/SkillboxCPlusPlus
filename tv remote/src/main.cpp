#include <QApplication>
#include "RemoteControlWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    RemoteControlWidget w;
    w.show();
    return QApplication::exec();
}
