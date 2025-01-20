#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <libpq-fe.h>
#include <iostream>
#include <string>

class DatabaseHandler {
public:
    static PGconn* connectToDatabase() {
        PGconn* conn = PQconnectdb("host=localhost port=5432 dbname=pc_registration_db user=your_user password=your_password");
        if (PQstatus(conn) != CONNECTION_OK) {
            std::cerr << "Database connection failed: " << PQerrorMessage(conn) << std::endl;
            PQfinish(conn);
            return nullptr;
        }
        return conn;
    }

    static bool executeQuery(PGconn* conn, const std::string& query) {
        PGresult* res = PQexec(conn, query.c_str());
        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            std::cerr << "Query execution failed: " << PQerrorMessage(conn) << std::endl;
            PQclear(res);
            return false;
        }
        PQclear(res);
        return true;
    }

    static PGresult* executeSelectQuery(PGconn* conn, const std::string& query) {
        PGresult* res = PQexec(conn, query.c_str());
        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            std::cerr << "Select query failed: " << PQerrorMessage(conn) << std::endl;
            PQclear(res);
            return nullptr;
        }
        return res;
    }

    static void closeConnection(PGconn* conn) {
        PQfinish(conn);
    }
};

#endif
