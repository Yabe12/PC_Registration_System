#ifndef ADMIN_MENU_H
#define ADMIN_MENU_H

#include <iostream>
#include "../services/AdminService.h"

class AdminMenu {
public:
    static void showAdminManagementMenu() {
        while (true) {
            std::cout << "\nAdmin Management Menu:\n"
                     << "1. Add New Admin\n"
                     << "2. Display All Admins\n"
                     << "3. Update Admin\n"
                     << "4. Delete Admin\n"
                     << "5. Back\n"
                     << "Enter choice: ";
            
            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    AdminService::addAdmin();
                    break;
                case 2:
                    AdminService::displayAdmins();
                    break;
                case 3:
                    AdminService::updateAdmin();
                    break;
                case 4:
                    AdminService::deleteAdmin();
                    break;
                case 5:
                    return;
                default:
                    std::cout << "Invalid choice!\n";
            }
        }
    }
};

#endif 