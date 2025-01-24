// --- menus/sub_menus/non_staff_menu.cpp ---
#include <iostream>
#include "../../../services/user/non_staff_service.h"
#include "non_staff_menu.h"

using namespace std;

void printHeader(const string& title) {
    cout << "\n=============================================" << endl;
    cout << "              " << title << endl;
    cout << "=============================================" << endl;
}

void printFooter() {
    cout << "=============================================" << endl;
}

void non_staff_menu() {
    int choice;
    do {
        printHeader("Nonstaff Management System");
        cout << "1. Add Nonstaff\n";
        cout << "2. Search Nonstaff\n";
        cout << "3. Display Nonstaff\n";
        cout << "4. Update Nonstaff\n";
        cout << "5. Delete Nonstaff\n";
        cout << "6. Exit\n";
        printFooter();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printFooter();
                add_nonstaff();
                break;
            case 2:
                printFooter();
                search_nonstaff();
                break;
            case 3:
                printFooter();
                display_nonstaff();
                break;
            case 4:
                printFooter();
                update_nonstaff();
                break;
            case 5:
                printFooter();
                delete_nonstaff();
                break;
            case 6:
                cout << "\nExiting Nonstaff Management System. Goodbye!" << endl;
                printFooter();
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                printFooter();
        }
    } while (choice != 6);
}
