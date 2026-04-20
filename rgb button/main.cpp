#include <QApplication>
#include  <QDebug>
#include  <Qresource>
#include <QSlider>
#include <QVBoxLayout>
#include "ColorfulCircle.h"

int main(int argc, char *argv[]) {
    qDebug() << QResource(":/buttons/green_circle.png").isValid();
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(200, 250);

    ColorfulCircle circle(&window);

    QSlider slider(Qt::Horizontal, &window);
    slider.setMinimum(0);
    slider.setMaximum(100);
    slider.setValue(0);

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(&circle);
    layout->addWidget(&slider);

    QObject::connect(&slider, &QSlider::valueChanged,
                     [&circle](int newValue) {
        if (newValue >= 0 && newValue < 33) {
            circle.setGreen();
        } else if (newValue >= 33 && newValue < 66) {
            circle.setYellow();
        } else {
            circle.setRed();
        }
    });

    window.show();
    return app.exec();
}
