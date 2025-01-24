// --- menus/main_menu.cpp ---
#include <iostream>
#include "../services/auth_service.h"
#include "./sub_menus/super_admin_menu/super_admin_menu.h"
#include "./sub_menus/admin_menu/admin_menu.h"

using namespace std;

void printHeader(const string& title) {
    cout << "\n=============================================" << endl;
    cout << "              " << PC REGESTRATION SYSTEM  << endl;
    cout << "=============================================" << endl;
}

void printFooter() {
    cout << "=============================================" << endl;
}

void mainMenu() {
    char roleChoice;

    printHeader("Main Menu");
    cout << "Choose your role:\n";
    cout << "A. I am SuperAdmin\n";
    cout << "B. I am Admin\n";
    cout << "=============================================" << endl;
    cout << "Enter your choice (A or B): ";
    cin >> roleChoice;

    if (roleChoice == 'A' || roleChoice == 'a') {
        if (login(true)) {
            printFooter();
            super_admin_menu();
        }
    } else if (roleChoice == 'B' || roleChoice == 'b') {
        if (login(false)) {
            printFooter();
            admin_menu();
        }
    } else {
        cout << "Invalid choice! Please enter either A or B." << endl;
        printFooter();
    }
}

int main() {
    // Main menu is called when the program starts
    mainMenu();
    return 0;
}
