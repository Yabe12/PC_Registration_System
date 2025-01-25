#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <iostream>
#include <cstring>

using namespace std;

bool validateInput(const char* str, int maxLength);
bool validateGender(char gender);
bool validatePhoneNumber(long long phone);

#endif // INPUT_VALIDATION_H