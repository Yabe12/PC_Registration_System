// --- menus/main_menu.cpp ---
#include <iostream>
#include "../middleware/auth_middleware.cpp"

void superAdminMenu();
void adminMenu();

void mainMenu() {
    char roleChoice;
    std::cout << "Choose your role:\nA. I am SuperAdmin\nB. I am Admin\n";
    std::cin >> roleChoice;

    if (roleChoice == 'A' || roleChoice == 'a') {
        if (AuthenticationController::login(true)) {
            superAdminMenu();
        }
    } else if (roleChoice == 'B' || roleChoice == 'b') {
        if (AuthenticationController::login(false)) {
            adminMenu();
        }
    } else {
        std::cout << "Invalid choice!\n";
    }
}
