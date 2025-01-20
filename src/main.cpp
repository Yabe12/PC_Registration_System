#include <iostream>

#include "models/Admin.h"
#include "models/Student.h"
#include "models/Staff.h"
#include "models/NonStaff.h"
#include "services/AuthService.h"
#include "menus/MainMenu.h"
#include <cstring>
using namespace std;
// Initialize global pointers
Admin* admin_head = nullptr;
Admin* admin_tall = nullptr;
Student* student_head = nullptr;
Student* student_tall = nullptr;
// ... other global pointer initializations

int main() {
    while (true) {
        char roleChoice;
        std::cout << "Choose your role:\nA. I am SuperAdmin\nB. I am Admin\n";
        std::cin >> roleChoice;

        if (roleChoice == 'A' || roleChoice == 'a') {
            if (!AuthService::login(true)) return 0;
            MainMenu::showSuperAdminMenu();
        } else if (roleChoice == 'B' || roleChoice == 'b') {
            if (!AuthService::login(false)) return 0;
            MainMenu::showAdminMenu();
        } else {
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
} 