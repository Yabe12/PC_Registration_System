// --- user_menu.cpp ---
#include <iostream>
#include <cstring>
#include "../staff_menu/staff_menu.h"
#include "../non_staff_menu/non_staff_menu.h"
#include "../student_menu/student_menu.h"
#include "user_menu.h"

using namespace std;

void printHeader(const string& title) {
    cout << "\n=============================================" << endl;
    cout << "              " << title << endl;
    cout << "=============================================" << endl;
}

void printFooter() {
    cout << "=============================================" << endl;
}

void user_menu() {
    int choice;
    do {
        printHeader("User Management System");
        cout << "1. Go to Student\n";
        cout << "2. Go to Staff\n";
        cout << "3. Go to NonStaff\n";
        cout << "4. Exit\n";
        printFooter();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printFooter();
                student_menu();
                break;
            case 2:
                printFooter();
                staff_menu();
                break;
            case 3:
                printFooter();
                non_staff_menu();
                break;
            case 4:
                cout << "\nExiting program.\n";
                printFooter();
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                printFooter();
        }
    } while (choice != 4);
}

int main() {
    user_menu();
    return 0;
}
