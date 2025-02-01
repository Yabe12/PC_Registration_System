#include "./auth_service.h"
#include <iostream>
#include <cstring>
#include "../middleware/input_validation.h"
#include "../database/admin/AdminDBOperations.h"

#include "../database/superadmin/SuperAdminDBOperations.h"
using namespace std;


Admin* admin_head = nullptr;
Admin* admin_tall = nullptr;


bool isSuperAdmin = false;  
bool isAuthenticated = false;

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

 
    string usernameStr(username);
    string passwordStr(password);

    if (isSuper) {
        
        if (checkSuperAdminCredentials(usernameStr, passwordStr)) {
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
        if (check_admin_credentials(usernameStr, passwordStr)) {
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