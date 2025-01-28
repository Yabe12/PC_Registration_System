#include <iostream>
#include "database_operations.h"
#include "connection.h"

int main() {
    // Connect to the database
    PGconn *conn = connectToDatabase();

    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        return 1;
    }

    std::cout << "Connected to the database successfully." << std::endl;

    // Perform test operations
    try {
        createSuperAdmin(conn, "testSuperAdmin", "testPassword");
        std::cout << "Superadmin created successfully." << std::endl;

        addAdmin(conn, "testAdmin", "adminPassword", "testSuperAdmin");
        std::cout << "Admin created successfully." << std::endl;

        addStudent(conn, "Test Student", "TS123", "Male", "CS", 1234567890, "Dell", "SN123", "testSuperAdmin", 1);
        std::cout << "Student added successfully." << std::endl;

        addStaff(conn, "Test Staff", "ST123", "Female", "Manager", 9876543210, "HP", "Workstation", "SN456", "testSuperAdmin", 1);
        std::cout << "Staff added successfully." << std::endl;

        addNonStaff(conn, "Test Non-Staff", "NST123", "Male", 1239874560, "Acer", "SN789", "testSuperAdmin", 1);
        std::cout << "Non-Staff added successfully." << std::endl;

        displayAllRecords(conn, "superadmin");
        displayAllRecords(conn, "admin");
        displayAllRecords(conn, "student");
        displayAllRecords(conn, "staff");
        displayAllRecords(conn, "nonstaff");

    } catch (const std::exception &e) {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }

    // Close the connection
    closeConnection(conn);

    return 0;
}
