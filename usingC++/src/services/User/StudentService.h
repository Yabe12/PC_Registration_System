#include <iostream>
#include <string>
#include "../models/Student.h"
#include "../utils/DatabaseHandler.h"
#include "../controll/authentication.h"

using namespace std;

class StudentService {
public:
    // Register a new student
    static void registerStudent() {
        if (!Authentication::isSuperAdmin()) {
            cout << "Unauthorized: Only superadmins can register students." << endl;
            return;
        }

        Student newStudent;
        
        cout << "Enter student name: ";
        cin.ignore();
        cin.getline(newStudent.name, 50);

        cout << "Enter student ID: ";
        cin.getline(newStudent.id, 20);

        cout << "Enter gender (M/F): ";
        cin >> newStudent.gender;

        cout << "Enter department: ";
        cin.ignore();
        cin.getline(newStudent.department, 50);

        cout << "Enter year: ";
        cin >> newStudent.year;

        cout << "Enter phone number: ";
        cin >> newStudent.phone;

        cout << "Enter PC name: ";
        cin.ignore();
        cin.getline(newStudent.pcname, 50);

        cout << "Enter serial number: ";
        cin.getline(newStudent.serial, 50);

        PGconn* conn = DatabaseHandler::connectToDatabase();
        if (!conn) return;

        string query = "INSERT INTO students (name, id, gender, department, year, phone, pcname, serial) VALUES ('" +
                        string(newStudent.name) + "', '" + string(newStudent.id) + "', '" + newStudent.gender + "', '" +
                        string(newStudent.department) + "', " + to_string(newStudent.year) + ", " + to_string(newStudent.phone) +
                        ", '" + string(newStudent.pcname) + "', '" + string(newStudent.serial) + "');";

        if (DatabaseHandler::executeQuery(conn, query)) {
            cout << "Student registered successfully." << endl;
        }

        DatabaseHandler::closeConnection(conn);
    }

    // Update student details
    static void updateStudent() {
        if (!Authentication::isSuperAdmin()) {
            cout << "Unauthorized: Only superadmins can update student details." << endl;
            return;
        }

        cout << "Enter ID of the student to update: ";
        string searchId;
        cin >> searchId;

        PGconn* conn = DatabaseHandler::connectToDatabase();
        if (!conn) return;

        string query = "SELECT * FROM students WHERE id = '" + searchId + "';";
        PGresult* res = DatabaseHandler::executeSelectQuery(conn, query);

        if (!res || PQntuples(res) == 0) {
            cout << "Student not found." << endl;
            PQclear(res);
            DatabaseHandler::closeConnection(conn);
            return;
        }

        cout << "Enter updated student name: ";
        string name;
        cin.ignore();
        getline(cin, name);

        cout << "Enter updated department: ";
        string department;
        getline(cin, department);

        cout << "Enter updated year: ";
        int year;
        cin >> year;

        query = "UPDATE students SET name = '" + name + "', department = '" + department + "', year = " + to_string(year) +
                " WHERE id = '" + searchId + "';";

        if (DatabaseHandler::executeQuery(conn, query)) {
            cout << "Student details updated successfully." << endl;
        }

        PQclear(res);
        DatabaseHandler::closeConnection(conn);
    }

    // Search for a student
    static void searchStudent() {
        cout << "Enter ID of the student to search: ";
        string searchId;
        cin >> searchId;

        PGconn* conn = DatabaseHandler::connectToDatabase();
        if (!conn) return;

        string query = "SELECT * FROM students WHERE id = '" + searchId + "';";
        PGresult* res = DatabaseHandler::executeSelectQuery(conn, query);

        if (!res || PQntuples(res) == 0) {
            cout << "Student not found." << endl;
        } else {
            cout << "\nName: " << PQgetvalue(res, 0, 0)
                 << "\nID: " << PQgetvalue(res, 0, 1)
                 << "\nGender: " << PQgetvalue(res, 0, 2)
                 << "\nDepartment: " << PQgetvalue(res, 0, 3)
                 << "\nYear: " << PQgetvalue(res, 0, 4)
                 << "\nPhone: " << PQgetvalue(res, 0, 5)
                 << "\nPC Name: " << PQgetvalue(res, 0, 6)
                 << "\nSerial: " << PQgetvalue(res, 0, 7) << endl;
        }

        PQclear(res);
        DatabaseHandler::closeConnection(conn);
    }

    // Delete a student (superadmin only)
    static void deleteStudent() {
        if (!Authentication::isSuperAdmin()) {
            cout << "Unauthorized: Only superadmins can delete students." << endl;
            return;
        }

        cout << "Enter ID of the student to delete: ";
        string searchId;
        cin >> searchId;

        PGconn* conn = DatabaseHandler::connectToDatabase();
        if (!conn) return;

        string query = "DELETE FROM students WHERE id = '" + searchId + "';";
        if (DatabaseHandler::executeQuery(conn, query)) {
            cout << "Student deleted successfully." << endl;
        }

        DatabaseHandler::closeConnection(conn);
    }
};
