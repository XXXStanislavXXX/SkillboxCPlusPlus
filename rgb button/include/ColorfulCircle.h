#ifndef COLORFULCIRCLE_H
#define COLORFULCIRCLE_H

#include <QWidget>
#include <QPixmap>

class ColorfulCircle : public QWidget {
    Q_OBJECT

public:
    explicit ColorfulCircle(QWidget *parent = nullptr);

public slots:
    void setGreen();
    void setYellow();
    void setRed();

protected:
    QSize minimumSizeHint() const override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
    QPixmap mCurrentCircle;
};

#endif // COLORFULCIRCLE_H
