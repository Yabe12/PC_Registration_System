// --- menus/main_menu.cpp ---
#include <iostream>
#include "../middleware/auth_middleware.cpp"
#include "./sub_menus/super_admin_menu/super_admin_menu.h"
#include "./sub_menus/admin_menu/admin_menu.h"
void mainMenu() {
    char roleChoice;
    std::cout << "Choose your role:\nA. I am SuperAdmin\nB. I am Admin\n";
    std::cin >> roleChoice;

    if (roleChoice == 'A' || roleChoice == 'a') {
        if (AuthenticationController::login(true)) {
            super_admin_menu();
        }
    } else if (roleChoice == 'B' || roleChoice == 'b') {
        if (AuthenticationController::login(false)) {
            admin_menu();
        }
    } else {
        std::cout << "Invalid choice!\n";
    }
}
