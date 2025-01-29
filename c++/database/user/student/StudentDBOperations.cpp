#include "StudentDBOperations.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to read the student database file and return all student records
vector<student> read_students_from_db() {
    vector<student> students;
    ifstream infile("students_db.txt");

    if (infile.is_open()) {
        student temp_student;
        while (infile.getline(temp_student.name, 50)) {
            infile.getline(temp_student.id, 20);
            infile.getline(temp_student.gender, 10);
            infile.getline(temp_student.department, 50);
            infile >> temp_student.phone;
            infile.ignore();  // To skip the newline after the phone number
            infile.getline(temp_student.pcname, 50);
            infile.getline(temp_student.serial, 50);
            temp_student.next = nullptr;
            temp_student.prev = nullptr;  // For a simple linked list in memory
            students.push_back(temp_student);
        }
        infile.close();
    } else {
        cout << "Failed to open student database file." << endl;
    }

    return students;
}

// Helper function to write all students back to the database file
void write_students_to_db(const vector<student>& students) {
    ofstream outfile("students_db.txt");

    if (outfile.is_open()) {
        for (const auto& student : students) {
            outfile << student.name << endl;
            outfile << student.id << endl;
            outfile << student.gender << endl;
            outfile << student.department << endl;
            outfile << student.phone << endl;
            outfile << student.pcname << endl;
            outfile << student.serial << endl;
        }
        outfile.close();
    } else {
        cout << "Failed to open student database file." << endl;
    }
}

void add_student_to_db(const char* name, const char* id, const char* gender, const char* department,
                       long long phone, const char* pcname, const char* serial) {
    vector<student> students = read_students_from_db();

    // Add the new student to the list
    student new_student;
    strcpy(new_student.name, name);
    strcpy(new_student.id, id);
    strcpy(new_student.gender, gender);
    strcpy(new_student.department, department);
    new_student.phone = phone;
    strcpy(new_student.pcname, pcname);
    strcpy(new_student.serial, serial);
    new_student.next = nullptr;
    new_student.prev = nullptr;

    students.push_back(new_student);

    // Write updated student list to the database
    write_students_to_db(students);
}

void update_student_in_db(const char* id, const char* name, const char* gender, const char* department,
                          long long phone, const char* pcname, const char* serial) {
    vector<student> students = read_students_from_db();

    for (auto& student : students) {
        if (strcmp(student.id, id) == 0) {
            // Update the student data
            strcpy(student.name, name);
            strcpy(student.gender, gender);
            strcpy(student.department, department);
            student.phone = phone;
            strcpy(student.pcname, pcname);
            strcpy(student.serial, serial);
            break;
        }
    }

    // Write updated student list back to the database
    write_students_to_db(students);
}

void delete_student_from_db(const char* id) {
    vector<student> students = read_students_from_db();

    // Remove student from the list
    students.erase(remove_if(students.begin(), students.end(), [id](const student& s) {
        return strcmp(s.id, id) == 0;
    }), students.end());

    // Write updated student list to the database
    write_students_to_db(students);
}

void search_student_in_db(const char* id) {
    vector<student> students = read_students_from_db();

    bool found = false;
    for (const auto& student : students) {
        if (strcmp(student.id, id) == 0) {
            // Print student details if found
            cout << "Student found:\n";
            cout << "Name: " << student.name << endl;
            cout << "ID: " << student.id << endl;
            cout << "Gender: " << student.gender << endl;
            cout << "Department: " << student.department << endl;
            cout << "Phone: " << student.phone << endl;
            cout << "PC Name: " << student.pcname << endl;
            cout << "Serial Number: " << student.serial << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << id << " not found." << endl;
    }
}

void display_all_students_from_db() {
    vector<student> students = read_students_from_db();

    if (students.empty()) {
        cout << "No students found." << endl;
    } else {
        for (const auto& student : students) {
            cout << "Name: " << student.name << endl;
            cout << "ID: " << student.id << endl;
            cout << "Gender: " << student.gender << endl;
            cout << "Department: " << student.department << endl;
            cout << "Phone: " << student.phone << endl;
            cout << "PC Name: " << student.pcname << endl;
            cout << "Serial Number: " << student.serial << endl;
            cout << "------------------------------------" << endl;
        }
    }
}
