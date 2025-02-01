#include <iostream>
#include <libpq-fe.h>
#include <string>
#include "dotenv.h"
void checkConnection(PGconn *conn) {
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        exit(1);
    }
}



PGconn* connectToDatabase() {
  
    const std::string envPath = ".env";
    auto envVars = loadEnvFile(envPath);

    std::string dbName = envVars["DB_NAME"];
    std::string dbUser = envVars["DB_USER"];
    std::string dbPassword = envVars["DB_PASSWORD"];
    std::string dbHost = envVars["DB_HOST"];
    std::string dbPort = envVars["DB_PORT"];
     std::string conninfo = "host=" + dbHost +
                           " port=" + dbPort +
                           " dbname=" + dbName +
                           " user=" + dbUser +
                           " password=" + dbPassword;

    PGconn *conn = PQconnectdb(conninfo.c_str());
    checkConnection(conn);

    std::cout << "Connected to the database successfully." << std::endl;
    return conn;
}

void closeConnection(PGconn *conn) {
    PQfinish(conn);
    
}
