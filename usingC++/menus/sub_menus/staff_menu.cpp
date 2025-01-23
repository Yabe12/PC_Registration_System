#include <iostream>
#include <cstring>
#include "../../services/User/staff_service.h"
#include "../../services/User/staff_service.cpp"
#include "staff_menu.h"

using namespace std;

// Function declarations
void add_staff();
void display_staff();
void search_staff();
void update_staff();
void delete_staff();

void staff_menu() {
    int choice;
    do {
        cout << "\nStaff Management System\n";
        cout << "1. Add Staff\n";
        cout << "2. Display Staff\n";
        cout << "3. Search Staff\n";
        cout << "4. Update Staff\n";
        cout << "5. Delete Staff\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_staff();
                break;
            case 2:
                display_staff();
                break;
            case 3:
                search_staff();
                break;
            case 4:
                update_staff();
                break;
            case 5:
                delete_staff();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

int main() {
    staff_menu();
    return 0;
}

// Function definitions
void add_staff() {
    // Call the function from staff_service.cpp
    STAFF_SERVICE_H::add_staff();
}

void display_staff() {
    // Call the function from staff_service.cpp
    STAFF_SERVICE_H::display_staff();
}

void search_staff() {
    // Call the function from staff_service.cpp
    STAFF_SERVICE_H::search_staff();
}

void update_staff() {
    // Call the function from staff_service.cpp
    STAFF_SERVICE_H::update_staff();
}

void delete_staff() {
    // Call the function from staff_service.cpp
    STAFF_SERVICE_H::delete_staff();
}
