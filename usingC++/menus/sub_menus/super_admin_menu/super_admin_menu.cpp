// --- menus/sub_menus/super_admin_menu.cpp ---
#include <iostream>
#include "../user_menu/user_menu.h"
#include "super_admin_menu.h"
#include "../admin_menu/admin_menu.h"
using namespace std;

void printHeader(const string& title) {
    cout << "\n=============================================" << endl;
    cout << "              " << title << endl;
    cout << "=============================================" << endl;
}

void printFooter() {
    cout << "=============================================" << endl;
}

void super_admin_menu() {
    int choice;
    while (true) {
        printHeader("Super Admin Menu");
        cout << "1. Work on admin\n";
        cout << "2. Work on user\n";
        cout << "3. Exit\n";
        printFooter();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printFooter();
                admin_menu();
                break;
            case 2:
                printFooter();
                user_menu();
                break;
            case 3:
                cout << "\nExiting Super Admin Menu.\n";
                printFooter();
                return;
            default:
                cout << "\nInvalid choice, try again.\n";
                printFooter();
        }
    }
}

