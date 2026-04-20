#include "RemoteControlWidget.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

RemoteControlWidget::RemoteControlWidget(QWidget *parent)
    : QWidget(parent) {
    setFixedSize(240, 680);

    auto *root = new QVBoxLayout(this);
    root->setContentsMargins(12, 12, 12, 12);
    root->setSpacing(12);

    auto *grid = new QGridLayout();
    grid->setSpacing(8);

    // buttons
    for (int i = 1; i <= 9; ++i) {
        auto *btn = new QPushButton(QString::number(i), this);
        btn->setFixedSize(64, 48);
        connect(btn, &QPushButton::clicked, this, [this, i]() { setChannel(i); });
        int row = (i - 1) / 3;
        int col = (i - 1) % 3;
        grid->addWidget(btn, row, col);
    }

    // 0 button in the middle bottom
    auto *btn0 = new QPushButton(QString::number(0), this);
    btn0->setFixedSize(64, 48);
    connect(btn0, &QPushButton::clicked, this, [this]() { setChannel(0); });
    grid->addWidget(btn0, 3, 1);

    root->addLayout(grid);

    // channel buttons
    auto *channelRow = new QHBoxLayout();
    auto *prevBtn = new QPushButton(QStringLiteral("CH-"), this);
    auto *nextBtn = new QPushButton(QStringLiteral("CH+"), this);
    prevBtn->setFixedHeight(48);
    nextBtn->setFixedHeight(48);
    connect(prevBtn, &QPushButton::clicked, this, &RemoteControlWidget::prevChannel);
    connect(nextBtn, &QPushButton::clicked, this, &RemoteControlWidget::nextChannel);
    channelRow->addWidget(prevBtn);
    channelRow->addWidget(nextBtn);
    root->addLayout(channelRow);

    // volume buttons
    auto *volumeRow = new QHBoxLayout();
    auto *volDown = new QPushButton(QStringLiteral("VOL-"), this);
    auto *volUp = new QPushButton(QStringLiteral("VOL+"), this);
    volDown->setFixedHeight(48);
    volUp->setFixedHeight(48);
    connect(volDown, &QPushButton::clicked, this, &RemoteControlWidget::volumeDown);
    connect(volUp, &QPushButton::clicked, this, &RemoteControlWidget::volumeUp);
    volumeRow->addWidget(volDown);
    volumeRow->addWidget(volUp);
    root->addLayout(volumeRow);

    root->addStretch(); // move display 2 bottom

    // display
    m_display = new QLabel(this);
    m_display->setFixedHeight(60);
    m_display->setStyleSheet(QStringLiteral("background:#202020;color:#E0E0E0;border-radius:6px;font-weight:600;"));
    m_display->setAlignment(Qt::AlignCenter);
    root->addWidget(m_display);

    updateDisplay();
}

void RemoteControlWidget::setChannel(int channel) {
    m_channel = channel % 10;
    if (m_channel < 0) m_channel += 10;
    updateDisplay();
}

void RemoteControlWidget::nextChannel() {
    m_channel = (m_channel + 1) % 10;
    updateDisplay();
}

void RemoteControlWidget::prevChannel() {
    m_channel = (m_channel + 9) % 10;
    updateDisplay();
}

void RemoteControlWidget::volumeUp() {
    m_volume = qMin(100, m_volume + 10);
    updateDisplay();
}

void RemoteControlWidget::volumeDown() {
    m_volume = qMax(0, m_volume - 10);
    updateDisplay();
}

void RemoteControlWidget::updateDisplay() {
    m_display->setText(QString("CH %1  |  VOL %2%").arg(m_channel).arg(m_volume));
}
