#pragma once

#include <QWidget>

class QLabel;

class RemoteControlWidget final : public QWidget {
    Q_OBJECT
public:
    explicit RemoteControlWidget(QWidget *parent = nullptr);

private slots:
    void setChannel(int channel);
    void nextChannel();
    void prevChannel();
    void volumeUp();
    void volumeDown();

private:
    void updateDisplay();

    int m_channel = 0;
    int m_volume = 50;

    QLabel *m_display = nullptr;
};
