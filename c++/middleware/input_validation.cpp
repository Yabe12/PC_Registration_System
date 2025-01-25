#include "input_validation.h"
#include <iostream>
#include <cstring>

using namespace std;

bool validateInput(const char* str, int maxLength) {
    if (strlen(str) >= maxLength) {
        cout << "Input too long. Maximum length is " << maxLength-1 << " characters." << endl;
        return false;
    }
    return true;
}

bool validateGender(const char* gender) {
    std::string genderStr(gender);
    for (auto & c: genderStr) c = tolower(c);
    if (genderStr != "male" && genderStr != "female") {
        cout << "Invalid gender. Please enter Male or Female." << endl;
        return false;
    }
    return true;
}

bool validatePhoneNumber(long long phone) {
    // Assuming phone numbers should be between 8 and 15 digits
    int digits = 0;
    long long temp = phone;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }
    if (digits < 8 || digits > 15) {
        cout << "Invalid phone number length." << endl;
        return false;
    }
    return true;
}