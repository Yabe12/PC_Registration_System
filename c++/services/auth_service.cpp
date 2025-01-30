#include "auth_service.h"
#include <iostream>
#include <cstring>
#include "../middleware/input_validation.h"
#include "../database/admin/AdminDBOperations.h"
#include "../database/superadmin/SuperAdminDBOperations.h"

using namespace std;

// Define global pointers for the linked list
Admin* admin_head = nullptr;
Admin* admin_tall = nullptr;

// Define global variables
bool isSuper = false;
bool isAuthenticated = false;

// Define super admin credentials
const char superAdminUsername[] = "superadmin";
const char superAdminPassword[] = "superpassword";


bool login(bool isSuper) {
    char username[50];
    char password[50];

    cout << "\n=============================================" << endl;
    cout << "               Login Required " << endl;
    cout << "=============================================" << endl;
    cout << "Enter username: ";
    cin >> username;
    if (!validateInput(username, 50)) return false;

    cout << "Enter password: ";
    cin >> password;
    if (!validateInput(password, 50)) return false;

    if (isSuper) {
        // Call SuperAdminDBOperations to verify the credentials
        if (checkSuperAdminCredentials(username, password)) {
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
       if (check_admin_credentials(username, password)) {
            isAuthenticated = true;
            cout << "\n=============================================" << endl;
            cout << "          Admin Login Successful!" << endl;
            cout << "=============================================" << endl;
            return true;
        } else {
            cout << "\n=============================================" << endl;
            cout << "    Invalid Admin Credentials!" << endl;
            cout << "=============================================" << endl;
            return false;
        }
    }
}
