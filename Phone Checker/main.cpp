#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include "PhoneChecker.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create phone checker instance
    PhoneChecker checker;

    // Create main window
    QWidget window;
    window.setWindowTitle("Phone Checker");
    window.resize(400, 150);

    // Create layout
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // Create label for instructions
    QLabel *instructionLabel = new QLabel("Enter phone number:");
    layout->addWidget(instructionLabel);

    // Create input field
    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("+11111111111");
    layout->addWidget(lineEdit);

    // Create result indicator (color only, no text)
    QLabel *resultLabel = new QLabel();
    resultLabel->setStyleSheet("background-color: red; border-radius: 10px;");
    resultLabel->setFixedHeight(40);
    layout->addWidget(resultLabel);

    // Connect line edit text changed signal to validate phone number
    QObject::connect(lineEdit, &QLineEdit::textChanged, [&](const QString &text) {
        if (checker.isValidPhoneNumber(text)) {
            resultLabel->setStyleSheet("background-color: green; border-radius: 10px;");
        } else {
            resultLabel->setStyleSheet("background-color: red; border-radius: 10px;");
        }
    });

    window.show();
    return QApplication::exec();
}