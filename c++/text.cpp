#include <iostream>
#include <libpq-fe.h>

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
   
    // Connect to the database
    PGconn *conn = PQconnectdb(conninfo);

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
