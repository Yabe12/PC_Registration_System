#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <iostream>
#include "../services/AuthService.h"
#include "../services/StudentService.h"
#include "../services/StaffService.h"
#include "../services/NonStaffService.h"
#include <cstring>
using namespace std;

class MainMenu {
public:
    static void showSuperAdminMenu() {
        while (true) {
            cout << "\nSuper Admin Menu:\n"
                 << "1. Manage Admins\n"
                 << "2. Manage Students\n"
                 << "3. Manage Staff\n"
                 << "4. Manage Non-Staff\n"
                 << "5. Logout\n"
                 << "Enter choice: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    // showAdminManagementMenu();
                    break;
                case 2:
                    // showStudentManagementMenu();
                    break;
                case 3:
                    // showStaffManagementMenu();
                    break;
                case 4:
                    // showNonStaffManagementMenu();
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid choice!\n";
            }
        }
    }

    static void showAdminMenu() {
        while (true) {
            cout << "\nAdmin Menu:\n"
                 << "1. Manage Students\n"
                 << "2. Manage Staff\n"
                 << "3. Manage Non-Staff\n"
                 << "4. Logout\n"
                 << "Enter choice: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    // showStudentManagementMenu();
                    break;
                case 2:
                    // showStaffManagementMenu();
                    break;
                case 3:
                    // showNonStaffManagementMenu();
                    break;
                case 4:
                    return;
                default:
                    cout << "Invalid choice!\n";
            }
        }
    }

private:
    static void showStudentManagementMenu() {
        while (true) {
            cout << "\nStudent Management:\n"
                 << "1. Add Student\n"
                 << "2. Display Students\n"
                 << "3. Back\n"
                 << "Enter choice: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    StudentService::addStudent();
                    break;
                case 2:
                    StudentService::displayStudents();
                    break;
                case 3:
                    return;
                default:
                    cout << "Invalid choice!\n";
            }
        }
    }

    // Add similar methods for staff and non-staff management menus
};

#endif // MAIN_MENU_H
