// --- menus/sub_menus/admin_menu.cpp ---
#include <iostream>
#include "../../../services/admin/AdminService.h"
#include "admin_menu.h"

using namespace std;

void printHeader(const string& title) {
    cout << "\n=============================================" << endl;
    cout << "              " << title << endl;
    cout << "=============================================" << endl;
}

void printFooter() {
    cout << "=============================================" << endl;
}

void admin_menu() {
    int choice;
    do {
        printHeader("Admin Management System");
        cout << "1. Add Admin\n";
        cout << "2. Update Admin\n";
        cout << "3. Search Admin\n";
        cout << "4. Delete Admin\n";
        cout << "5. Display Admins\n";
        cout << "6. Exit\n";
        printFooter();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printFooter();
                add_admin();
                break;
            case 2:
                printFooter();
                update_admin();
                break;
            case 3:
                printFooter();
                search_admin();
                break;
            case 4:
                printFooter();
                delete_admin();
                break;
            case 5:
                printFooter();
                display_admin();
                break;
            case 6:
                cout << "\nExiting Admin Management System. Goodbye!" << endl;
                printFooter();
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                printFooter();
        }
    } while (choice != 6);
}
