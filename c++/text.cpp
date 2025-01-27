#include <iostream>
#include <libpq-fe.h>
#include <cstdlib>

void checkConnection(PGconn *conn) {
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        exit(1);
    }
}

void executeQuery(PGconn *conn, const char *query) {
    PGresult *res = PQexec(conn, query);

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

int main() {
    const char *host = std::getenv("DB_HOST");
    const char *port = std::getenv("DB_PORT");
    const char *dbname = std::getenv("DB_NAME");
    const char *user = std::getenv("DB_USER");
    const char *password = std::getenv("DB_PASSWORD");

    if (!host || !port || !dbname || !user || !password) {
        std::cerr << "Environment variables for database connection are not set." << std::endl;
        return 1;
    }

    std::string conninfo = "host=" + std::string(host) +
                           " port=" + std::string(port) +
                           " dbname=" + std::string(dbname) +
                           " user=" + std::string(user) +
                           " password=" + std::string(password);

    // Connect to the database
    PGconn *conn = PQconnectdb(conninfo.c_str());

    checkConnection(conn);

    std::cout << "Connected to the database successfully." << std::endl;

    // Execute a query
    const char *query = "SELECT * FROM your_table;";
    executeQuery(conn, query);

    // Close the connection
    PQfinish(conn);
    std::cout << "Connection closed." << std::endl;

    return 0;
}
