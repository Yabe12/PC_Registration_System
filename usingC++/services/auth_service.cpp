#include "auth_service.h"
// #include <iostream>
// #include <cstring>
// #include <cstdlib>  // for std::getenv
// #include "dotenv.h"
// Define global pointers for the linked list
Admin* admin_head = nullptr;
Admin* admin_tall = nullptr;

// Define global variables
bool isSuperAdmin = false;
bool isAuthenticated = false;

// Define super admin credentials
const char superAdminUsername[] = "superadmin";
const char superAdminPassword[] = "superpassword";

    // // Fetch SuperAdmin credentials from environment variables
    // const char* superAdminUsername = std::getenv("SUPERADMIN_USERNAME");
    // const char* superAdminPassword = std::getenv("SUPERADMIN_PASSWORD");
bool login(bool isSuper) {
    char username[50];
    char password[50];
vsoc
    cout << "\n=============================================" << endl;
    cout << "               Admin Login" << endl;
    cout << "=============================================" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (isSuper) {
        if (strcmp(username, superAdminUsername) == 0 && strcmp(password, superAdminPassword) == 0) {
            isSuperAdmin = true;
            isAuthenticated = true;
            cout << "\n=============================================" << endl;
            cout << "        SuperAdmin Login Successful!" << endl;
            cout << "=============================================" << endl;
            return true;
        } else {
            cout << "\n=============================================" << endl;
            cout << "    Invalid SuperAdmin Credentials!" << endl;
            cout << "=============================================" << endl;
            return false;
        }
    } else {
        Admin* current = admin_head;
        while (current != nullptr) {
            if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0) {
                isAuthenticated = true;
                cout << "\n=============================================" << endl;
                cout << "          Admin Login Successful!" << endl;
                cout << "=============================================" << endl;
                return true;
            }
            current = current->next;
        }
        cout << "\n=============================================" << endl;
        cout << "    Invalid Admin Credentials!" << endl;
        cout << "=============================================" << endl;
        return false;
    }
}
