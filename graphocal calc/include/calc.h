#pragma once


#include "ui_calc.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void plus();
    void minus();
    void multiply();
    void devide();
private:
    Ui::MainWindow ui;
    void calculate(QChar op);
};
