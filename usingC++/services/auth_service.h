#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

#include <iostream>
#include <cstring>
using namespace std;

// Declare global variables
extern bool isSuperAdmin;
extern bool isAuthenticated;

// Define global variables
bool isSuperAdmin = false;
bool isAuthenticated = false;

// Define super admin credentials
const char superAdminUsername[] = "superadmin";
const char superAdminPassword[] = "superpassword";

// Define your Admin structure or class if it's not already defined
struct Admin {
    char username[50];
    char password[50];
    Admin* next;
};

// Global pointers for the linked list
extern Admin* admin_head;

// Authentication Function
bool login(bool isSuper) {
    char username[50], password[50];
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (isSuper && strcmp(username, superAdminUsername) == 0 && strcmp(password, superAdminPassword) == 0) {
        isSuperAdmin = true;
        isAuthenticated = true;
        return true;
    }

    if (!isSuper) {
        Admin* temp = admin_head;
        while (temp) {
            if (strcmp(temp->username, username) == 0 && strcmp(temp->password, password) == 0) {
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

#endif // AUTH_SERVICE_H

