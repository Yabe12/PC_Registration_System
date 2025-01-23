// --- controllers/authentication_controller.cpp ---
#include <iostream>
#include "../services/admin/AdminService.h"

class AuthenticationController {
public:
    static bool login(bool isSuperAdmin) {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        return AuthService::authenticate(username, password, isSuperAdmin);
    }
};