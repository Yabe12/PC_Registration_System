#include "AdminDBOperations.h"
#include "../Connection.h"  // Include connection header
#include <iostream>
#include <cstring>  // Include cstring for strlen
#include <libpq-fe.h>

using namespace std;

void add_admin_to_db(const std::string& username, const std::string& password) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "INSERT INTO admin (username, password) VALUES ('" + username + "', '" + password + "');";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error executing query: " << PQerrorMessage(conn) << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void update_admin_in_db(const std::string& username, const std::string& password) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "UPDATE admin SET password = '" + password + "' WHERE username = '" + username + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error executing query: " << PQerrorMessage(conn) << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void delete_admin_from_db(const std::string& username) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "DELETE FROM admin WHERE username = '" + username + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error executing query: " << PQerrorMessage(conn) << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void search_admin_in_db(const std::string& username) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "SELECT * FROM admin WHERE username = '" + username + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            cerr << "Error searching admin in database: " << PQerrorMessage(conn) << endl;
            PQclear(res);
            closeConnection(conn);
            return;
        }

        if (PQntuples(res) > 0) {
            cout << "Admin found in database:" << endl;
            cout << "Username: " << PQgetvalue(res, 0, 0) << endl;
            cout << "Password: " << string(strlen(PQgetvalue(res, 0, 1)), '*') << endl;
        } else {
            cout << "Admin not found in database." << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}


bool check_admin_credentials(const std::string& username, const std::string& password) {
    PGconn *conn = connectToDatabase();
    if (!conn) {
        cerr << "❌ Database connection failed!" << endl;
        return false;
    }

    const char *query = "SELECT * FROM admin WHERE username = $1 AND password = $2;";
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