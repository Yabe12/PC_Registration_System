#include <iostream>
#include "database_operations.h"
#include "connection.h"

int main() {
    PGconn *conn = connectToDatabase();

    // Example usage:
    createSuperAdmin(conn, "superadmin", "superpassword");
    addAdmin(conn, "admin1", "adminpass");
    addStudent(conn, "John Doe", "S123", "Male", "CS", 1234567890, "Dell", "SN123");

    // Update a record
    updateRecord(conn, "student", "name='Jane Doe'", "student_id='S123'");

    // Delete a record
    deleteRecord(conn, "student", "student_id='S123'");

    // Search for records
    searchRecords(conn, "student", "gender='Male'");

    // Display all records
    displayAllRecords(conn, "student");

    closeConnection(conn);
    return 0;
}
