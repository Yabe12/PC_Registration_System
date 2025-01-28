#ifndef DATABASE_OPERATIONS_H
#define DATABASE_OPERATIONS_H

#include <iostream>

#include "connection.h" // Include the connection header

#include <libpq-fe.h>
#include <string>

// Function to execute a general query
void executeQuery(PGconn *conn, const std::string &query);

// Functions for managing Superadmin
void createSuperAdmin(PGconn *conn, const std::string &username, const std::string &password);

// Functions for managing Admin
void addAdmin(PGconn *conn, const std::string &username, const std::string &password, const std::string &superadmin_username);

// Functions for managing Student
void addStudent(PGconn *conn, const std::string &name, const std::string &id, const std::string &gender, const std::string &department, long long phone, const std::string &pcname, const std::string &serial, const std::string &superadmin_username, int admin_id);

// Functions for managing Staff
void addStaff(PGconn *conn, const std::string &name, const std::string &id, const std::string &gender, const std::string &job, long long phone, const std::string &typeofpc, const std::string &pcname, const std::string &serial, const std::string &superadmin_username, int admin_id);

// Functions for managing Non-Staff
void addNonStaff(PGconn *conn, const std::string &name, const std::string &id, const std::string &gender, long long phone, const std::string &pcname, const std::string &serial, const std::string &superadmin_username, int admin_id);

// General record management functions
void updateRecord(PGconn *conn, const std::string &table, const std::string &setClause, const std::string &condition);
void deleteRecord(PGconn *conn, const std::string &table, const std::string &condition);
void searchRecords(PGconn *conn, const std::string &table, const std::string &condition);
void displayAllRecords(PGconn *conn, const std::string &table);

#endif // DATABASE_OPERATIONS_H
