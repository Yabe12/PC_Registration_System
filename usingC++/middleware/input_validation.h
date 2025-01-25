#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <iostream>
#include <cstring>

using namespace std;
// validation.h


bool validateInput(const char* str, int maxLength);
bool validateGender(const char* gender);
bool validatePhoneNumber(long long phone);

#endif // INPUT_VALIDATION_H