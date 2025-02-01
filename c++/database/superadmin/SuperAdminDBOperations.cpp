#include "SuperAdminDBOperations.h"
#include "../connection.h"
#include <iostream>
#include <libpq-fe.h>

using namespace std;

bool checkSuperAdminCredentials(const std::string& usernameStr, const std::string& passwordStr) {
    PGconn *conn = connectToDatabase();
    if (!conn) {
        cerr << " Database connection failed!" << endl;
        return false;
    }



    const char *query = "SELECT 1 FROM superadmin WHERE LOWER(username) = LOWER($1) AND password = $2;";
    const char *paramValues[2] = { usernameStr.c_str(), passwordStr.c_str() };
    int paramLengths[2] = { (int)usernameStr.length(), (int)passwordStr.length() };
    int paramFormats[2] = { 0, 0 };

    PGresult *res = PQexecParams(conn, query, 2, NULL, paramValues, paramLengths, paramFormats, 0);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        cerr << "Error executing query: " << PQerrorMessage(conn) << endl;
        PQclear(res);
        closeConnection(conn);
        return false;
    }

    bool isValid = PQntuples(res) > 0;
    

    PQclear(res);
    closeConnection(conn);

    return isValid;
}
