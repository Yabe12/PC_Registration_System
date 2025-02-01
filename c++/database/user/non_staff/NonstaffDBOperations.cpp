#include "NonStaffDBOperations.h"
#include "../../connection.h"
#include <iostream>
#include <libpq-fe.h>
#include <string>

using namespace std;

void add_nonstaff_to_db(const std::string& name, const std::string& id, const std::string& gender, long long phone, const std::string& pcname, const std::string& serial) {
    PGconn *conn = connectToDatabase();
    if (conn) {
      
        std::string query = "INSERT INTO nonstaff (name, id, gender, phone, pcname, serial) VALUES ('" + name + "', '" + id + "', '" + gender + "', " + std::to_string(phone) + ", '" + pcname + "', '" + serial + "');";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error executing query: " << PQerrorMessage(conn) << endl;
        } else {
            cout << "Nonstaff added successfully!" << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void update_nonstaff_in_db(const std::string& id, const std::string& name, const std::string& gender, long long phone, const std::string& pcname, const std::string& serial) {
    PGconn *conn = connectToDatabase();
    if (conn) {
     std::string query = "UPDATE nonstaff SET name = '" + name + "', gender = '" + gender + "', phone = " + std::to_string(phone) + ", pcname = '" + pcname + "', serial = '" + serial + "' WHERE id = '" + id + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error executing query: " << PQerrorMessage(conn) << endl;
        } else {
            cout << "Nonstaff updated successfully!" << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void delete_nonstaff_from_db(const std::string& id) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "DELETE FROM nonstaff WHERE id = '" + id + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error executing query: " << PQerrorMessage(conn) << endl;
        } else {
            cout << "Nonstaff deleted successfully!" << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}
void display_all_nonstaff_from_db() {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "SELECT * FROM nonstaff;";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            cerr << "Error fetching nonstaff from database: " << PQerrorMessage(conn) << endl;
            PQclear(res);
            closeConnection(conn);
            return;
        }

        int numRows = PQntuples(res);
        if (numRows > 0) {
            cout << "\nAll Nonstaff in Database:" << endl;
            for (int i = 0; i < numRows; i++) {
                cout << "DB ID: " << PQgetvalue(res, i, 0) << endl;
                cout << "Name: " << PQgetvalue(res, i, 1) << endl;
                cout << "ID: " << PQgetvalue(res, i, 2) << endl;
                cout << "Gender: " << PQgetvalue(res, i, 3) << endl;
                cout << "Phone: " << PQgetvalue(res, i, 4) << endl;
                cout << "PC Name: " << PQgetvalue(res, i, 5) << endl;
                cout << "Serial: " << PQgetvalue(res, i, 6) << endl;
                cout << "-----------------------" << endl;
            }
        } else {
            cout << "No nonstaff members found in the database." << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void search_nonstaff_in_db(const std::string& name) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "SELECT * FROM nonstaff WHERE name = '" + name + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            cerr << "Error searching nonstaff in database: " << PQerrorMessage(conn) << endl;
            PQclear(res);
            closeConnection(conn);
            return;
        }

        if (PQntuples(res) > 0) {
            cout << "Nonstaff found:" << endl;
            cout << "Name: " << PQgetvalue(res, 0, 0) << endl;
            cout << "ID: " << PQgetvalue(res, 0, 1) << endl;
            cout << "Gender: " << PQgetvalue(res, 0, 2) << endl;
            cout << "Phone: " << PQgetvalue(res, 0, 3) << endl;
            cout << "PC Name: " << PQgetvalue(res, 0, 4) << endl;
            cout << "Serial: " << PQgetvalue(res, 0, 5) << endl;
        } else {
            cout << "Nonstaff not found." << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void sort_nonstaff_from_db() {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "SELECT * FROM nonstaff ORDER BY name;";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            cerr << "Error sorting nonstaff from database: " << PQerrorMessage(conn) << endl;
            PQclear(res);
            closeConnection(conn);
            return;
        }

        int numRows = PQntuples(res);
        if (numRows > 0) {
            cout << "\nSorted Nonstaff List:" << endl;
            for (int i = 0; i < numRows; i++) {
                cout << "Name: " << PQgetvalue(res, i, 0) << endl;
                cout << "ID: " << PQgetvalue(res, i, 1) << endl;
                cout << "Gender: " << PQgetvalue(res, i, 2) << endl;
                cout << "Phone: " << PQgetvalue(res, i, 3) << endl;
                cout << "PC Name: " << PQgetvalue(res, i, 4) << endl;
                cout << "Serial: " << PQgetvalue(res, i, 5) << endl;
                cout << "-----------------------" << endl;
            }
        }

        PQclear(res);
        closeConnection(conn);
    }
}