#include <iostream>
#include "../services/auth_service.h"
using namespace std;

bool login(bool isSuperAdmin) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    return AUTH_SERVICE_H::authenticate(username, password, isSuperAdmin);
}
