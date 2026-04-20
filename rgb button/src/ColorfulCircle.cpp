#include "../include/ColorfulCircle.h"
#include <QPainter>


ColorfulCircle::ColorfulCircle(QWidget *parent)
    : QWidget(parent) {
    mGreenCircle = QPixmap(":/buttons/green_circle.png");
    mYellowCircle = QPixmap(":/buttons/yellow_circle.png");
    mRedCircle = QPixmap(":/buttons/red_circle.png");

}

void ColorfulCircle::setGreen() {
    mCurrentCircle = mGreenCircle;
    update();
}

void ColorfulCircle::setYellow() {
    mCurrentCircle = mYellowCircle;
    update();
}

void ColorfulCircle::setRed() {
    mCurrentCircle = mRedCircle;
    update();
}

QSize ColorfulCircle::minimumSizeHint() const {
    return QSize(65, 65);
}

void ColorfulCircle::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(rect(), mCurrentCircle);
}
