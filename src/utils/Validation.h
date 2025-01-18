#ifndef VALIDATION_H
#define VALIDATION_H

#include <cstring>
#include <iostream>

class Validation {
public:
    static bool validateInput(const char* str, int maxLength) {
        if (strlen(str) >= maxLength) {
            std::cout << "Input too long. Maximum length is " << maxLength-1 << " characters." << std::endl;
            return false;
        }
        return true;
    }

    static bool validateGender(char gender) {
        gender = toupper(gender);
        if (gender != 'M' && gender != 'F') {
            std::cout << "Invalid gender. Please enter M or F." << std::endl;
            return false;
        }
        return true;
    }

    static bool validatePhoneNumber(long long phone) {
        int digits = 0;
        long long temp = phone;
        while (temp != 0) {
            temp /= 10;
            digits++;
        }
        if (digits < 8 || digits > 15) {
            std::cout << "Invalid phone number length." << std::endl;
            return false;
        }
        return true;
    }
};

#endif 