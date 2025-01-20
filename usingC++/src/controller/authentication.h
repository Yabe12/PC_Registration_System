#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

#include <cstring>
#include <iostream>
#include <string>
#include <cstdlib>
#include "../models/Admin.h"
#include "../utils/Hasher.h" // Utility for hashing passwords

using namespace std;

class AuthService {
private:
    static bool isSuperAdmin;

public:
    static bool loginSuperAdmin() {
        char username[50], password[50];
        cout << "Enter superadmin username: ";
        cin >> username;
        cout << "Enter superadmin password: ";
        cin >> password;

        const char* superAdminUsername = getenv("SUPER_ADMIN_USERNAME");
        const char* superAdminPassword = getenv("SUPER_ADMIN_PASSWORD");

        if (!superAdminUsername || !superAdminPassword) {
            cout << "Error: Superadmin credentials not configured.\n";
            return false;
        }

        if (strcmp(username, superAdminUsername) == 0 && 
            strcmp(Hasher::hash(password).c_str(), superAdminPassword) == 0) {
            isSuperAdmin = true;
            return true;
        }

        cout << "Authentication failed.\n";
        return false;
    }

    static bool loginAdmin() {
        char username[50], password[50];
        cout << "Enter admin username: ";
        cin >> username;
        cout << "Enter admin password: ";
        cin >> password;

        Admin* temp = admin_head;
        while (temp) {
            if (strcmp(temp->username, username) == 0 &&
                strcmp(Hasher::hash(password).c_str(), temp->password) == 0) {
                isSuperAdmin = false;
                return true;
            }
            temp = temp->next;
        }

        cout << "Authentication failed.\n";
        return false;
    }

    static bool isUserSuperAdmin() { return isSuperAdmin; }
};

bool AuthService::isSuperAdmin = false;

#endif // AUTH_SERVICE_H
