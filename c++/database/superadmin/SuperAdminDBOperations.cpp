#include "./SuperAdminDBOperations.h"
#include "../connection.h"
#include <libpq-fe.h>
#include <iostream>

using namespace std;

bool checkSuperAdminCredentials(const std::string& username, const std::string& password) {
    PGconn *conn = connectToDatabase();
    if (!conn) {
        cerr << "❌ Database connection failed!" << endl;
        return false;
    }

    const char *query = "SELECT * FROM superadmin WHERE username = $1 AND password = $2;";
    const char *paramValues[2] = { username.c_str(), password.c_str() };
    int paramLengths[2] = { (int)username.length(), (int)password.length() };
    int paramFormats[2] = { 0, 0 }; // Text format

    PGresult *res = PQexecParams(conn, query, 2, NULL, paramValues, paramLengths, paramFormats, 0);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        cerr << "❌ Error executing query: " << PQerrorMessage(conn) << endl;
        PQclear(res);
        closeConnection(conn);
        return false;
    }

    bool isValid = PQntuples(res) > 0;

    PQclear(res);
    closeConnection(conn);

    return isValid;
}