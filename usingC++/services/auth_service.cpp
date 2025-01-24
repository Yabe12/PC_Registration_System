#include "auth_service.h"

// Define global pointers for the linked list
Admin* admin_head = nullptr;
Admin* admin_tall = nullptr;

// Define global variables
bool isSuperAdmin = false;
bool isAuthenticated = false;

// Define super admin credentials
const char superAdminUsername[] = "superadmin";
const char superAdminPassword[] = "superpassword";

bool login(bool isSuper) {
    char username[50];
    char password[50];

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (isSuper) {
        if (strcmp(username, superAdminUsername) == 0 && strcmp(password, superAdminPassword) == 0) {
            isSuperAdmin = true;
            isAuthenticated = true;
            cout << "SuperAdmin login successful!" << endl;
            return true;
        } else {
            cout << "Invalid SuperAdmin credentials!" << endl;
            return false;
        }
    } else {
        Admin* current = admin_head;
        while (current != nullptr) {
            if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0) {
                isAuthenticated = true;
                cout << "Admin login successful!" << endl;
                return true;
            }
            current = current->next;
        }
        cout << "Invalid Admin credentials!" << endl;
        return false;
    }
}