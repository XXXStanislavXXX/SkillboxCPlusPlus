#include "PhoneChecker.h"

PhoneChecker::PhoneChecker()
    : phoneRegex("^\\+[0-9]{11}$") {
}

bool PhoneChecker::isValidPhoneNumber(const QString &phoneNumber) const {
    QRegularExpressionMatch match = phoneRegex.match(phoneNumber);
    return match.hasMatch();
}

