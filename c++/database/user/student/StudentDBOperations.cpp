#include "./StudentDBOperations.h"
#include "../../connection.h"

#include <iostream>

using namespace std;

void add_student_to_db(const std::string& name, const std::string& id, const std::string& gender, 
                       const std::string& department, long long phone, const std::string& pcname, 
                       const std::string& serial) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "INSERT INTO students (name, id, gender, department, phone, pcname, serial) VALUES ('" 
                            + name + "', '" + id + "', '" + gender + "', '" + department + "', " 
                            + to_string(phone) + ", '" + pcname + "', '" + serial + "');";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error inserting student: " << PQerrorMessage(conn) << endl;
        } else {
            cout << "Student added to database successfully!" << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void update_student_in_db(const std::string& id, const std::string& name, const std::string& gender, 
                          const std::string& department, long long phone, const std::string& pcname, 
                          const std::string& serial) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "UPDATE students SET name = '" + name + "', gender = '" + gender + "', department = '" 
                            + department + "', phone = " + to_string(phone) + ", pcname = '" + pcname + 
                            "', serial = '" + serial + "' WHERE id = '" + id + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error updating student: " << PQerrorMessage(conn) << endl;
        } else {
            cout << "Student record updated successfully!" << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void display_all_students_from_db() {
    // Function body that retrieves and displays all students from the database
    PGconn *conn = connectToDatabase();
    if (conn) {
        string query = "SELECT * FROM students;";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            cerr << "Error retrieving student data: " << PQerrorMessage(conn) << endl;
            PQclear(res);
            closeConnection(conn);
            return;
        }

        int rows = PQntuples(res);
        if (rows > 0) {
            cout << "\nAll Students:\n";
            for (int i = 0; i < rows; i++) {
                cout << "Name: " << PQgetvalue(res, i, 0) 
                     << " | ID: " << PQgetvalue(res, i, 1) 
                     << " | Gender: " << PQgetvalue(res, i, 2) 
                     << " | Department: " << PQgetvalue(res, i, 3) 
                     << " | Phone: " << PQgetvalue(res, i, 4) 
                     << " | PC Name: " << PQgetvalue(res, i, 5) 
                     << " | Serial: " << PQgetvalue(res, i, 6) << endl;
            }
        } else {
            cout << "No students found in database." << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}
void search_student_in_db(const std::string& id) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        std::string query = "SELECT * FROM students WHERE id = '" + id + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            cerr << "Error searching student: " << PQerrorMessage(conn) << endl;
            PQclear(res);
            closeConnection(conn);
            return;
        }

        if (PQntuples(res) > 0) {
            cout << "Student found in database:\n";
            cout << "Name: " << PQgetvalue(res, 0, 0) << "\nID: " << PQgetvalue(res, 0, 1) 
                 << "\nGender: " << PQgetvalue(res, 0, 2) << "\nDepartment: " << PQgetvalue(res, 0, 3)
                 << "\nPhone: " << PQgetvalue(res, 0, 4) << "\nPC Name: " << PQgetvalue(res, 0, 5) 
                 << "\nSerial: " << PQgetvalue(res, 0, 6) << endl;
        } else {
            cout << "Student not found in database." << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}

void delete_student_from_db(const std::string& id) {
    PGconn *conn = connectToDatabase();
    if (conn) {
        string query = "DELETE FROM students WHERE id = '" + id + "';";
        PGresult *res = PQexec(conn, query.c_str());

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            cerr << "Error deleting student: " << PQerrorMessage(conn) << endl;
        } else {
            cout << "Student deleted successfully!" << endl;
        }

        PQclear(res);
        closeConnection(conn);
    }
}