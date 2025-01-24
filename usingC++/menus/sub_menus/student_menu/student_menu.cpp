// --- menus/sub_menus/student_menu.cpp ---
#include <iostream>
#include "../../../services/user/student_service.h"
#include "student_menu.h"

using namespace std;

void printHeader(const string& title) {
    cout << "\n=============================================" << endl;
    cout << "              " << title << endl;
    cout << "=============================================" << endl;
}

void printFooter() {
    cout << "=============================================" << endl;
}

void student_menu() {
    int choice;
    do {
        printHeader("Student Management System");
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        printFooter();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printFooter();
                add_student();
                break;
            case 2:
                printFooter();
                display_students();
                break;
            case 3:
                printFooter();
                search_student();
                break;
            case 4:
                printFooter();
                update_student();
                break;
            case 5:
                printFooter();
                delete_student();
                break;
            case 6:
                cout << "\nExiting Student Management System.\n";
                printFooter();
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                printFooter();
        }
    } while (choice != 6);
}
