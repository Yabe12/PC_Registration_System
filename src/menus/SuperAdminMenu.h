#ifndef SUPER_ADMIN_MENU_H
#define SUPER_ADMIN_MENU_H

#include <iostream>
#include "../services/AdminService.h"
#include "AdminMenu.h"

class SuperAdminMenu {
public:
    static void showSystemSettings() {
        while (true) {
            std::cout << "\nSystem Settings:\n"
                     << "1. Backup Database\n"
                     << "2. Restore Database\n"
                     << "3. System Statistics\n"
                     << "4. Back\n"
                     << "Enter choice: ";
            
            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    backupDatabase();
                    break;
                case 2:
                    restoreDatabase();
                    break;
                case 3:
                    showStatistics();
                    break;
                case 4:
                    return;
                default:
                    std::cout << "Invalid choice!\n";
            }
        }
    }

private:
    static void backupDatabase() {
        // Implementation for database backup
        std::cout << "Database backup initiated...\n";
    }

    static void restoreDatabase() {
        // Implementation for database restore
        std::cout << "Database restore initiated...\n";
    }

    static void showStatistics() {
        // Show system statistics
        std::cout << "System Statistics:\n";
        // Add implementation
    }
};

#endif 