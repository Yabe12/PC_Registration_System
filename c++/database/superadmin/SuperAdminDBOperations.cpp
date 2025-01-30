#include "SuperAdminDBOperations.h"
#include "Connection.h"  // For database connection
#include <libpq-fe.h>
#include <iostream>

using namespace std;

// Check SuperAdmin credentials in the database
bool checkSuperAdminCredentials(const std::string& username, const std::string& password) {
    PGconn *conn = connectToDatabase();  // Establish connection
    if (!conn) {
        cerr << "Database connection failed!" << endl;
        return false;
    }

    // Query to check if the username and password match in the database
    std::string query = "SELECT * FROM superadmin WHERE username = '" + username + "' AND password = '" + password + "';";

    PGresult *res = PQexec(conn, query.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        cerr << "Error executing query: " << PQerrorMessage(conn) << endl;
        PQclear(res);
        closeConnection(conn);
        return false;
    }

    bool isValid = PQntuples(res) > 0;  // Check if any rows were returned

    PQclear(res);
    closeConnection(conn);
    
    return isValid;
}
