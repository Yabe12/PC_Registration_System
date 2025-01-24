#include <iostream>
#include <cstring>
#include "../staff_menu/staff_menu.h"
#include "../non_staff_menu/non_staff_menu.h"
#include "../student_menu/student_menu.h"
#include "user.h"

using namespace std;

void user_menu() {
    int choice;
    do {
        cout << "\nUser Management System\n";
        cout << "1. Go to Student\n";
        cout << "2. Go to Staff\n";
        cout << "3. Go to NonStaff\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                student_menu();
                break;
            case 2:
                staff_menu();
                break;
            case 3:
                non_staff_menu();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

int main() {
    user_menu();
    return 0;
}
