#include <QApplication>
#include "HTMLEditor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    HTMLEditor editor;
    editor.show();

    return app.exec();
}

