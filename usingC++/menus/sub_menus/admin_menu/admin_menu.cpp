#include <iostream>
#include "../../services/admin/AdminService.h"
#include "admin_menu.h"

using namespace std;

int main() {
    admin_menu();
    return 0;
}

void admin_menu() {
    int choice;
    do {
        cout << "\nAdmin Management System\n";
        cout << "1. Add Admin\n";
        cout << "2. Update Admin\n";
        cout << "3. Search Admin\n";
        cout << "4. Delete Admin\n";
        cout << "5. Display Admins\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_admin();
                break;
            case 2:
                update_admin();
                break;
            case 3:
                search_admin();
                break;
            case 4:
                delete_admin();
                break;
            case 5:
                display_admin();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

void add_admin() {
    // Call the function from staff_service.cpp
    ADMIN_SERVICE_H::add_admin();
}

void display_admin() {
    // Call the function from staff_service.cpp
    ADMIN_SERVICE_H::display_admin();
}

void search_admin() {
    // Call the function from staff_service.cpp
    ADMIN_SERVICE_H::search_admin();
}

void update_admin() {
    // Call the function from staff_service.cpp
    ADMIN_SERVICE_H::update_admin();
}

void delete_admin() {
    // Call the function from staff_service.cpp
    ADMIN_SERVICE_H::delete_admin();
}