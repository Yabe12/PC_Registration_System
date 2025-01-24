#include "auth_service.h"

// Define global variables
bool isSuperAdmin = false;
bool isAuthenticated = false;

// Define super admin credentials
const char superAdminUsername[] = "superadmin";
const char superAdminPassword[] = "superpassword";

// Define global pointers for the linked list
Admin* admin_head = nullptr;

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