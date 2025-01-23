// // --- services/auth_service.cpp ---
// #include <iostream>
// #include <pqxx/pqxx>
// #include "../database/db_connection.cpp"

// class AuthService {
// public:
//     static bool authenticate(const std::string& username, const std::string& password, bool isSuperAdmin) {
//         try {
//             auto conn = Database::connect();
//             pqxx::work txn(*conn);
//             std::string query = "SELECT * FROM admins WHERE username=" + txn.quote(username) +
//                                 " AND password=" + txn.quote(password) + " AND is_superadmin=" + (isSuperAdmin ? "true" : "false");
//             pqxx::result result = txn.exec(query);

//             if (!result.empty()) {
//                 std::cout << "Authentication successful!\n";
//                 return true;
//             }
//         } catch (const std::exception &e) {
//             std::cerr << "Authentication error: " << e.what() << std::endl;
//         }

//         std::cout << "Invalid credentials.\n";
//         return false;
//     }
// };


#include <iostream>
#include <cstring>
using namespace std;

int main () {
    
// Authentication Function
bool login(bool isSuper) {
    char username[50], password[50];
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (isSuper && strcmp(username, superAdminUsername) == 0 && strcmp(password, superAdminPassword) == 0) {
        isSuperAdmin = true;
        isAuthenticated = true;
        return true;
    }

    if (!isSuper) {
        Admin *temp = admin_head;
        while (temp) {
            if (strcmp(temp->username, username) == 0 && strcmp(temp->password, password) == 0) {
                isSuperAdmin = false;
                isAuthenticated = true;
                return true;
            }
            temp = temp->next;
        }
    }

    cout << "Invalid credentials!\n";
    return false;
}

}

