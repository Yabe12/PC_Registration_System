// --- menus/sub_menus/staff_menu.cpp ---
#include <iostream>
#include "../../../services/user/staff_service.h"
#include "staff_menu.h"

using namespace std;

void printHeader(const string& title) {
    cout << "\n=============================================" << endl;
    cout << "              " << title << endl;
    cout << "=============================================" << endl;
}

void printFooter() {
    cout << "=============================================" << endl;
}

void staff_menu() {
    int choice;
    do {
        printHeader("Staff Management System");
        cout << "1. Add Staff\n";
        cout << "2. Display Staff\n";
        cout << "3. Search Staff\n";
        cout << "4. Update Staff\n";
        cout << "5. Delete Staff\n";
        cout << "6. Exit\n";
        printFooter();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printFooter();
                add_staff();
                break;
            case 2:
                printFooter();
                display_staff();
                break;
            case 3:
                printFooter();
                search_staff();
                break;
            case 4:
                printFooter();
                update_staff();
                break;
            case 5:
                printFooter();
                delete_staff();
                break;
            case 6:
                cout << "\nExiting Staff Management System.\n";
                printFooter();
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                printFooter();
        }
    } while (choice != 6);
}
