// --- services/auth_service.cpp ---
#include <iostream>
#include <pqxx/pqxx>
#include "../database/db_connection.cpp"

class AuthService {
public:
    static bool authenticate(const std::string& username, const std::string& password, bool isSuperAdmin) {
        try {
            auto conn = Database::connect();
            pqxx::work txn(*conn);
            std::string query = "SELECT * FROM admins WHERE username=" + txn.quote(username) +
                                " AND password=" + txn.quote(password) + " AND is_superadmin=" + (isSuperAdmin ? "true" : "false");
            pqxx::result result = txn.exec(query);

            if (!result.empty()) {
                std::cout << "Authentication successful!\n";
                return true;
            }
        } catch (const std::exception &e) {
            std::cerr << "Authentication error: " << e.what() << std::endl;
        }

        std::cout << "Invalid credentials.\n";
        return false;
    }
};
