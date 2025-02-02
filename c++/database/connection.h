#ifndef CONNECTION_H
#define CONNECTION_H

#include <libpq-fe.h>

void checkConnection(PGconn *conn);
PGconn* connectToDatabase();
void closeConnection(PGconn *conn);

#endif 
