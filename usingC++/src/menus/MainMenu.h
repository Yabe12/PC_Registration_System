#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <iostream>
#include "./SuperAdminMenu.h"
#include "../utils/Logger.h"
#include "./AdminMenu.h"
#include "./AddMenu.h"
#include "./UpdateMenu.h"
#include "./SearchMenu.h"
#include "./displayMenu.h"

#include <cstring>
using namespace std;
int main() {
    while (true) {
        char roleChoice;
        cout << "Choose your role:\nA. I am SuperAdmin\nB. I am Admin\n";
        cin >> roleChoice;

        if (roleChoice == 'A' || roleChoice == 'a') {
            if (!login(true)) return 0;
            menu_superadmin();
        } else if (roleChoice == 'B' || roleChoice == 'b') {
            if (!login(false)) return 0;
            menu_admin();
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
#endif // MAIN_MENU_H