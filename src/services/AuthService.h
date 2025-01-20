#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

#include <cstring>
#include <iostream>
#include "../models/Admin.h"
using namespace std;

class AuthService {
private:
    static const char superAdminUsername[];
    static const char superAdminPassword[];
    static bool isSuperAdmin;
    static bool isAuthenticated;

public:
    static bool login(bool isSuper) {
        char username[50], password[50];
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (isSuper && strcmp(username, superAdminUsername) == 0 && 
            strcmp(password, superAdminPassword) == 0) {
            isSuperAdmin = true;
            isAuthenticated = true;
            return true;
        }

        if (!isSuper) {
            Admin* temp = admin_head;
            while (temp) {
                if (strcmp(temp->username, username) == 0 && 
                    strcmp(temp->password, password) == 0) {
                    isSuperAdmin = false;
                    isAuthenticated = true;
                    return true;
                }
                temp = temp->next;
            }
        }

        cout << "Invalid credentials!\n";
        return false;
    }

    static bool isUserSuperAdmin() { return isSuperAdmin; }
    static bool isUserAuthenticated() { return isAuthenticated; }
};

const char AuthService::superAdminUsername[] = "superadmin";
const char AuthService::superAdminPassword[] = "admin123";
bool AuthService::isSuperAdmin = false;
bool AuthService::isAuthenticated = false;

#endif // AUTH_SERVICE_H
