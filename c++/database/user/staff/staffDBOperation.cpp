#include "./StaffDBOperations.h"
#include "../../connection.h"
#include <iostream>

using namespace std;

void add_staff_to_db(const std::string& name, const std::string& id, const std::string& gender, 
                     const std::string& job, long long phone, const std::string& typeofpc, 
                     const std::string& pcname, const std::string& serial) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "INSERT INTO staff (name, id, gender, job, phone, typeofpc, pcname, serial) VALUES ('" 
                            + name + "', '" + id + "', '" + gender + "', '" + job + "', " 
                            + to_string(phone) + ", '" + typeofpc + "', '" + pcname + "', '" + serial + "');";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error inserting staff: " << PQerrorMessage(conn) << endl;
        } else {
            cout << "Staff added to database successfully!" << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void update_staff_in_db(const std::string& id, const std::string& name, const std::string& gender, 
                        const std::string& job, long long phone, const std::string& typeofpc, 
                        const std::string& pcname, const std::string& serial) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "UPDATE staff SET name = '" + name + "', gender = '" + gender + "', job = '" + job + 
                            "', phone = " + to_string(phone) + ", typeofpc = '" + typeofpc + 
                            "', pcname = '" + pcname + "', serial = '" + serial + "' WHERE id = '" + id + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error updating staff: " << PQerrorMessage(conn) << endl;
        } else {
            cout << "Staff record updated successfully!" << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void delete_staff_from_db(const std::string& id) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "DELETE FROM staff WHERE id = '" + id + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error deleting staff: " << PQerrorMessage(conn) << endl;
        } else {
            cout << "Staff record deleted successfully!" << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void search_staff_in_db(const std::string& id) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "SELECT * FROM staff WHERE id = '" + id + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            cerr << "Error searching staff: " << PQerrorMessage(conn) << endl;
            PQclear(res);
            closeConnection(conn);
            return;
        }

        if (PQntuples(res) > 0) {
            cout << "Staff found in database:\n";
            cout << "Name: " << PQgetvalue(res, 0, 0) << "\nID: " << PQgetvalue(res, 0, 1) 
                 << "\nGender: " << PQgetvalue(res, 0, 2) << "\nJob: " << PQgetvalue(res, 0, 3)
                 << "\nPhone: " << PQgetvalue(res, 0, 4) << "\nPC Type: " << PQgetvalue(res, 0, 5) 
                 << "\nPC Name: " << PQgetvalue(res, 0, 6) << "\nSerial: " << PQgetvalue(res, 0, 7) << endl;
        } else {
            cout << "Staff not found in database." << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void display_all_staff_from_db() {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "SELECT * FROM staff;";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            cerr << "Error retrieving staff data: " << PQerrorMessage(conn) << endl;
            PQclear(res);
            closeConnection(conn);
            return;
        }

        int rows = PQntuples(res);
        if (rows > 0) {
            cout << "\nAll Staff Members:\n";
            cout << "------------------------------------------------------\n";
            for (int i = 0; i < rows; i++) {
                cout << "Name: " << PQgetvalue(res, i, 0) 
                     << " | ID: " << PQgetvalue(res, i, 1) 
                     << " | Gender: " << PQgetvalue(res, i, 2) 
                     << " | Job: " << PQgetvalue(res, i, 3) 
                     << " | Phone: " << PQgetvalue(res, i, 4) 
                     << " | PC Type: " << PQgetvalue(res, i, 5) 
                     << " | PC Name: " << PQgetvalue(res, i, 6) 
                     << " | Serial: " << PQgetvalue(res, i, 7) << endl;
                cout << "------------------------------------------------------\n";
            }
        } else {
            cout << "No staff found in database." << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}