// --- menus/sub_menus/admin_menu.cpp ---
#include <iostream>
#include "../../services/user_service.cpp"

void adminMenu() {
    int choice;
    while (true) {
        std::cout << "\nAdmin Menu:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. View Students\n";
        std::cout << "3. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                UserService::addStudent();
                break;
            case 2:
                UserService::viewStudents();
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    }
}