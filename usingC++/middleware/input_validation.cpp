#include <iostream>
#include <cstring>
#include <cctype>
#include "../services/User/student_service.h"
#include "../models/users/student.h"
#include "../models/users/non_staff.h"
#include "../models/users/staff.h"
using namespace std;

bool validateInput(const char *input, size_t maxLength) {
    if (strlen(input) >= maxLength) {
        cout << "Error: Input is too long. Maximum length is " << maxLength - 1 << " characters.\n";
        return false;
    }
    for (size_t i = 0; i < strlen(input); i++) {
        if (!isalnum(input[i]) && !isspace(input[i])) {
            cout << "Error: Input contains invalid characters.\n";
            return false;
        }
    }
    return true;
}

bool validateGender(char gender) {
    if (gender != 'M' && gender != 'F' && gender != 'm' && gender != 'f') {
        cout << "Error: Gender must be 'M' or 'F'.\n";
        return false;
    }
    return true;
}

bool validatePhoneNumber(const char *phone) {
    if (strlen(phone) != 10) {
        cout << "Error: Phone number must be exactly 10 digits.\n";
        return false;
    }
    for (size_t i = 0; i < strlen(phone); i++) {
        if (!isdigit(phone[i])) {
            cout << "Error: Phone number must contain only digits.\n";
            return false;
        }
    }
    return true;
}
