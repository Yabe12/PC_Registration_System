#include <iostream>
#include "superadmin_menu.cpp"
#include "admin_menu.cpp"

using namespace std;

void mainMenu() {
    char roleChoice;
    cout << "Choose your role:\nA. I am SuperAdmin\nB. I am Admin\n";
    cin >> roleChoice;

    if (roleChoice == 'A' || roleChoice == 'a') {
        superAdminMenu();
    } else if (roleChoice == 'B' || roleChoice == 'b') {
        adminMenu();
    } else {
        cout << "Invalid choice!\n";
    }
}
