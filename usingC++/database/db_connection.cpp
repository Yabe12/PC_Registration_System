// --- database/db_connection.cpp ---

#include <pqxx/pqxx>
#include <iostream>

class Database {
public:
    static pqxx::connection* connect() {
        try {
            static pqxx::connection conn("dbname=yourdb user=youruser password=yourpassword");
            if (conn.is_open()) {
                std::cout << "Database connected successfully!\n";
            }
            return &conn;
        } catch (const std::exception &e) {
            std::cerr << "Database connection error: " << e.what() << std::endl;
            exit(1);
        }
    }
};