#include <iostream>
#include "../../../services/user/staff_service.h"
#include "staff_menu.h"
// #include "../../../utils/menu_utils/menu_utils.h"  // No longer needed if removing header/footer

using namespace std;

void staff_menu() {
    int choice;
    do {
        cout << "************************************" << endl;
        cout << "  Staff Management System" << endl;
        cout << "************************************" << endl;
        cout << "1. Add Staff\n";
        cout << "2. Display Staff\n";
        cout << "3. Search Staff\n";
        cout << "4. Update Staff\n";
        cout << "5. Delete Staff\n";
        cout << "6. Exit\n";
        cout << "************************************" << endl;
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
                cout << "\nExiting Staff Management System.\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 6);
}
