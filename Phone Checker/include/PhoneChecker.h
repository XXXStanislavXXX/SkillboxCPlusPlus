#ifndef PHONE_CHECKER_H
#define PHONE_CHECKER_H

#include <QString>
#include <QRegularExpression>

class PhoneChecker {
public:
    PhoneChecker();

    // Validates if the input string matches phone number format
    // Format: +11 digits (e.g., +79999999999)
    bool isValidPhoneNumber(const QString &phoneNumber) const;

private:
    QRegularExpression phoneRegex;
};

#endif // PHONE_CHECKER_H

