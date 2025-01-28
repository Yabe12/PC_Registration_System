#include <iostream>
#include <libpq-fe.h>
#include <string>
#include "database_operations.h"
#include "connection.h"

void executeQuery(PGconn *conn, const std::string &query) {
    PGresult *res = PQexec(conn, query.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK && PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::cerr << "Query execution failed: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        exit(1);
    }

    PQclear(res);
}

void createTables(PGconn *conn) {
    const std::string superadminTable = "CREATE TABLE IF NOT EXISTS superadmin (" \
                                        "username VARCHAR(50) PRIMARY KEY, " \
                                        "password VARCHAR(50) NOT NULL);";

    const std::string adminTable = "CREATE TABLE IF NOT EXISTS admin (" \
                                    "id SERIAL PRIMARY KEY, " \
                                    "username VARCHAR(50) NOT NULL, " \
                                    "password VARCHAR(50) NOT NULL);";

    const std::string studentTable = "CREATE TABLE IF NOT EXISTS student (" \
                                      "id SERIAL PRIMARY KEY, " \
                                      "name VARCHAR(50), " \
                                      "student_id VARCHAR(20), " \
                                      "gender VARCHAR(10), " \
                                      "department VARCHAR(50), " \
                                      "phone BIGINT, " \
                                      "pcname VARCHAR(50), " \
                                      "serial VARCHAR(50));";

    const std::string staffTable = "CREATE TABLE IF NOT EXISTS staff (" \
                                   "id SERIAL PRIMARY KEY, " \
                                   "name VARCHAR(50), " \
                                   "staff_id VARCHAR(20), " \
                                   "gender VARCHAR(10), " \
                                   "job VARCHAR(50), " \
                                   "phone BIGINT, " \
                                   "typeofpc VARCHAR(20), " \
                                   "pcname VARCHAR(50), " \
                                   "serial VARCHAR(50));";

    const std::string nonStaffTable = "CREATE TABLE IF NOT EXISTS nonstaff (" \
                                      "id SERIAL PRIMARY KEY, " \
                                      "name VARCHAR(50), " \
                                      "nonstaff_id VARCHAR(20), " \
                                      "gender VARCHAR(10), " \
                                      "phone BIGINT, " \
                                      "pcname VARCHAR(50), " \
                                      "serial VARCHAR(50));";

    executeQuery(conn, superadminTable);
    executeQuery(conn, adminTable);
    executeQuery(conn, studentTable);
    executeQuery(conn, staffTable);
    executeQuery(conn, nonStaffTable);
}

void createSuperAdmin(PGconn *conn, const std::string &username, const std::string &password) {
    std::string query = "INSERT INTO superadmin (username, password) VALUES ('" + username + "', '" + password + "') ON CONFLICT DO NOTHING;";
    executeQuery(conn, query);
    std::cout << "Superadmin created successfully." << std::endl;
}

void addAdmin(PGconn *conn, const std::string &username, const std::string &password) {
    std::string query = "INSERT INTO admin (username, password) VALUES ('" + username + "', '" + password + "');";
    executeQuery(conn, query);
    std::cout << "Admin created successfully." << std::endl;
}

void addStudent(PGconn *conn, const std::string &name, const std::string &id, const std::string &gender, const std::string &department, long long phone, const std::string &pcname, const std::string &serial) {
    std::string query = "INSERT INTO student (name, student_id, gender, department, phone, pcname, serial) VALUES ('" + name + "', '" + id + "', '" + gender + "', '" + department + "', " + std::to_string(phone) + ", '" + pcname + "', '" + serial + "');";
    executeQuery(conn, query);
    std::cout << "Student added successfully." << std::endl;
}

void updateRecord(PGconn *conn, const std::string &table, const std::string &setClause, const std::string &condition) {
    std::string query = "UPDATE " + table + " SET " + setClause + " WHERE " + condition + ";";
    executeQuery(conn, query);
    std::cout << "Record updated successfully." << std::endl;
}

void deleteRecord(PGconn *conn, const std::string &table, const std::string &condition) {
    std::string query = "DELETE FROM " + table + " WHERE " + condition + ";";
    executeQuery(conn, query);
    std::cout << "Record deleted successfully." << std::endl;
}

void searchRecords(PGconn *conn, const std::string &table, const std::string &condition) {
    std::string query = "SELECT * FROM " + table + " WHERE " + condition + ";";
    PGresult *res = PQexec(conn, query.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::cerr << "Query execution failed: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        exit(1);
    }

    int nRows = PQntuples(res);
    int nFields = PQnfields(res);

    // Print column names
    for (int i = 0; i < nFields; i++) {
        std::cout << PQfname(res, i) << "\t";
    }
    std::cout << std::endl;

    // Print rows
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nFields; j++) {
            std::cout << PQgetvalue(res, i, j) << "\t";
        }
        std::cout << std::endl;
    }

    PQclear(res);
}

void displayAllRecords(PGconn *conn, const std::string &table) {
    std::string query = "SELECT * FROM " + table + ";";
    PGresult *res = PQexec(conn, query.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::cerr << "Query execution failed: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        exit(1);
    }

    int nRows = PQntuples(res);
    int nFields = PQnfields(res);

    // Print column names
    for (int i = 0; i < nFields; i++) {
        std::cout << PQfname(res, i) << "\t";
    }
    std::cout << std::endl;

    // Print rows
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nFields; j++) {
            std::cout << PQgetvalue(res, i, j) << "\t";
        }
        std::cout << std::endl;
    }

    PQclear(res);
}

void connect(){
  PGconn *conn = connectToDatabase();
    createTables(conn);

    // Example usage:
    createSuperAdmin(conn, "superadmin", "superpassword");
    addAdmin(conn, "admin1", "adminpass");
    addStudent(conn, "John Doe", "S123", "Male", "CS", 1234567890, "Dell", "SN123");

    closeConnection(conn);

}