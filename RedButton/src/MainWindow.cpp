#include "MainWindow.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QApplication>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), label(nullptr), button(nullptr), player(nullptr), audioOutput(nullptr) {
    setupUI();
    connectSignals();

    // Initialize media player
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Connect error signal for debugging
    connect(player, &QMediaPlayer::errorOccurred, this, [this](QMediaPlayer::Error error, const QString &errorString) {
        qDebug() << "QMediaPlayer Error:" << error << errorString;
        if (label) {
            label->setText("Audio Error: " + errorString);
        }
    });

    // Set the path to the sound file
    QString exePath = QApplication::applicationDirPath();
    QString soundFile = exePath + "/click.wav";
    qDebug() << "Loading sound file:" << soundFile;
    qDebug() << "File exists:" << QFile::exists(soundFile);

    player->setSource(QUrl::fromLocalFile(soundFile));

    qDebug() << "QMediaPlayer status:" << player->playbackState();
    qDebug() << "QMediaPlayer error:" << player->errorString();
}

void MainWindow::setupUI() {
    // Set window parameters
    setWindowTitle("Red Button Interface");
    resize(300, 200);

    // Create central widget and layout
    QWidget *centralWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create label
    label = new QLabel("Click the red button!");
    label->setStyleSheet("font-size: 14px;");
    layout->addWidget(label);

    // Create red button
    button = new QPushButton("Click me!");
    button->setStyleSheet("background-color: red; color: white; font-size: 16px; padding: 10px; border: none; border-radius: 5px;");
    button->setCursor(Qt::PointingHandCursor);
    layout->addWidget(button);

    // Set central widget
    setCentralWidget(centralWidget);
}

void MainWindow::connectSignals() {
    if (button) {
        connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    }
}

void MainWindow::onButtonClicked() {
    if (label) {
        // Play sound using QMediaPlayer
        if (player) {
            player->setPosition(0); // Reset to beginning
            player->play();
        }
        label->setText("Button clicked!");
    }
}

