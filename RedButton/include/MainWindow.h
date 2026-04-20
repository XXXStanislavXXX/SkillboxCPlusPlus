#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

class QMediaPlayer;
class QAudioOutput;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Constructor of the main application window
     * @param parent Parent widget
     */
    MainWindow(QWidget *parent = nullptr);

private:
    QLabel *label;           ///< Label for displaying status
    QPushButton *button;     ///< Red button
    QMediaPlayer *player;    ///< Media player for sound playback
    QAudioOutput *audioOutput; ///< Audio output device

    /**
     * @brief Initializes the user interface
     */
    void setupUI();

    /**
     * @brief Connects signals to slots
     */
    void connectSignals();

private slots:
    /**
     * @brief Button click handler
     */
    void onButtonClicked();
};

#endif // MAINWINDOW_H

