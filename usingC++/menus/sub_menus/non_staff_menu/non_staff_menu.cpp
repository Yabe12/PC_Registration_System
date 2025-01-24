#include <iostream>
#include "../../../services/user/non_staff_service.h"
#include "non_staff_menu.h"

using namespace std;

void non_staff_menu() {
    int choice;
    do {
        cout << "\nNonstaff Management System\n";
        cout << "1. Add Nonstaff\n";
        cout << "2. Search Nonstaff\n";
        cout << "3. Display Nonstaff\n";
        cout << "4. Update Nonstaff\n";
        cout << "5. Delete Nonstaff\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_nonstaff();
                break;
            case 2:
                search_nonstaff();
                break;
            case 3:
                display_nonstaff();
                break;
            case 4:
                update_nonstaff();
                break;
            case 5:
                delete_nonstaff();
                break;
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}
