#include "calc.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this);
}

void MainWindow::plus()     { calculate('+'); }
void MainWindow::minus()    { calculate('-'); }
void MainWindow::multiply() { calculate('*'); }
void MainWindow::devide()   { calculate('/'); }

void MainWindow::calculate(QChar op) {
    bool ok1 = false, ok2 = false;
    double a = ui.firstNumber->text().toDouble(&ok1);
    double b = ui.secondNumber->text().toDouble(&ok2);

    if (!ok1 || !ok2) {
        ui.result->setText(QString::fromUtf8("Input ERROR!!!"));
        return;
    }

    if (op == '/' && b == 0.0) {
        ui.result->setText(QString::fromUtf8("Devision by 0"));
        return;
    }

    double res = 0.0;
    switch (op.toLatin1()) {
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/': res = a / b; break;
        default: ui.result->setText(QString::number(a)); return;
    }

    ui.result->setText(QString::number(res));
}

#include "calc.moc"
