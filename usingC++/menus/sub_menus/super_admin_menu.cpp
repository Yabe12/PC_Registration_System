// --- menus/sub_menus/admin_menu.cpp ---
#include <iostream>

#include "./user.h" 

void adminMenu() {
    int choice;
    while (true) {
        std::cout << "\nSuper Admin Menu:\n";
        std::cout << "1. work on admin \n";
        std::cout << "2. work on user \n";
        std::cout << "3. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                USER_MENU_H::user_menu();
                break;
            case 2:
                USER_MENU_H::user_menu();
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    }
}