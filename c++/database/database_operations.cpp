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

void createSuperAdmin(PGconn *conn, const std::string &username, const std::string &password) {
    std::string query = "INSERT INTO superadmin (username, password) VALUES ('" + username + "', '" + password + "') ON CONFLICT DO NOTHING;";
    executeQuery(conn, query);
    std::cout << "Superadmin created successfully." << std::endl;
}

void addAdmin(PGconn *conn, const std::string &username, const std::string &password, const std::string &superadmin_username) {
    std::string query = "INSERT INTO admin (username, password, superadmin_username) VALUES ('" + username + "', '" + password + "', '" + superadmin_username + "');";
    executeQuery(conn, query);
    std::cout << "Admin created successfully." << std::endl;
}

void addStudent(PGconn *conn, const std::string &name, const std::string &id, const std::string &gender, const std::string &department, long long phone, const std::string &pcname, const std::string &serial, const std::string &superadmin_username, int admin_id) {
    std::string query = "INSERT INTO student (name, student_id, gender, department, phone, pcname, serial, superadmin_username, admin_id) VALUES ('" + name + "', '" + id + "', '" + gender + "', '" + department + "', " + std::to_string(phone) + ", '" + pcname + "', '" + serial + "', '" + superadmin_username + "', " + std::to_string(admin_id) + ");";
    executeQuery(conn, query);
    std::cout << "Student added successfully." << std::endl;
}

void addStaff(PGconn *conn, const std::string &name, const std::string &id, const std::string &gender, const std::string &job, long long phone, const std::string &typeofpc, const std::string &pcname, const std::string &serial, const std::string &superadmin_username, int admin_id) {
    std::string query = "INSERT INTO staff (name, staff_id, gender, job, phone, typeofpc, pcname, serial, superadmin_username, admin_id) VALUES ('" + name + "', '" + id + "', '" + gender + "', '" + job + "', " + std::to_string(phone) + ", '" + typeofpc + "', '" + pcname + "', '" + serial + "', '" + superadmin_username + "', " + std::to_string(admin_id) + ");";
    executeQuery(conn, query);
    std::cout << "Staff added successfully." << std::endl;
}

void addNonStaff(PGconn *conn, const std::string &name, const std::string &id, const std::string &gender, long long phone, const std::string &pcname, const std::string &serial, const std::string &superadmin_username, int admin_id) {
    std::string query = "INSERT INTO nonstaff (name, nonstaff_id, gender, phone, pcname, serial, superadmin_username, admin_id) VALUES ('" + name + "', '" + id + "', '" + gender + "', " + std::to_string(phone) + ", '" + pcname + "', '" + serial + "', '" + superadmin_username + "', " + std::to_string(admin_id) + ");";
    executeQuery(conn, query);
    std::cout << "Nonstaff added successfully." << std::endl;
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

    for (int i = 0; i < nFields; i++) {
        std::cout << PQfname(res, i) << "\t";
    }
    std::cout << std::endl;

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

    for (int i = 0; i < nFields; i++) {
        std::cout << PQfname(res, i) << "\t";
    }
    std::cout << std::endl;

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nFields; j++) {
            std::cout << PQgetvalue(res, i, j) << "\t";
        }
        std::cout << std::endl;
    }

    PQclear(res);
}

void connect() {
    PGconn *conn = connectToDatabase();

    createSuperAdmin(conn, "superadmin", "superpassword");
    addAdmin(conn, "admin1", "adminpass", "superadmin");
    addStudent(conn, "John Doe", "S123", "Male", "CS", 1234567890, "Dell", "SN123", "superadmin", 1);
    addStaff(conn, "Jane Smith", "ST123", "Female", "Manager", 9876543210, "HP", "Workstation", "SN456", "superadmin", 1);
    addNonStaff(conn, "Bob Brown", "NST123", "Male", 1239874560, "Acer", "SN789", "superadmin", 1);

    closeConnection(conn);
}
