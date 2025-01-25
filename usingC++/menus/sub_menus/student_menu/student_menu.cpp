#include <iostream>
#include "../../../services/user/student_service.h"
#include "student_menu.h"
// #include "../../../utils/menu_utils/menu_utils.h"  // No longer needed if removing header/footer

using namespace std;

void student_menu() {
    int choice = 0;  // Initialize choice to 0 to enter the loop
    while (choice != 6) {
        cout << "************************************" << endl;
        cout << "  Student Management System" << endl;
        cout << "************************************" << endl;
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "************************************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                update_student();
                break;
            case 5:
                delete_student();
                break;
            case 6:
                cout << "\nExiting Student Management System.\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }
    }
}
