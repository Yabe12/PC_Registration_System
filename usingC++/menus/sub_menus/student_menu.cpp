#include <iostream>
#include <cstring>
#include "../../services/User/student_service.h"
using namespace std;

// Function declarations
void add_student();
void display_students();
void search_student();
void update_student();
void delete_student();

int main() {
    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                update_student();
                break;
            case 5:
                delete_student();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Function definitions
void add_student() {
    // Call the function from student_service.cpp
    student_service::addStudent();
}

void display_students() {
    // Call the function from student_service.cpp
    student_service::displayStudents();
}

void search_student() {
    // Call the function from student_service.cpp
    student_service::searchStudent();
}

void update_student() {
    // Call the function from student_service.cpp
    student_service::updateStudent();
}

void delete_student() {
    // Call the function from student_service.cpp
    student_service::deleteStudent();
}