#include <iostream>
#include <cstring>
#include "../../models/users/student.h"
#include "../../middleware/input_validation.h"
#include "../../database/user/student/StudentDBOperations.h"
#include "./student_service.h"

using namespace std;

// Define the global pointers for the linked list
student* student_head = nullptr;
student* student_tall = nullptr;

// Function to add a new student
void add_student() {
    char name[50], gender[10], department[50], pcname[50], serial[50], student_id[50];
    long long phone;

    cout << "\n=============================================" << endl;
    cout << "          Add New Student" << endl;
    cout << "=============================================" << endl;

    cout << "Enter student's name: ";
    cin.ignore();
    cin.getline(name, 50);
    if (!validateInput(name, 50)) return;

    cout << "Enter student's ID: ";
    cin.getline(student_id, 50);
    if (!validateInput(student_id, 50)) return;

    cout << "Enter student's gender (Male / Female): ";
    cin.getline(gender, 10);
    if (!validateGender(gender)) return;

    cout << "Enter student's department: ";
    cin.getline(department, 50);
    if (!validateInput(department, 50)) return;

    cout << "Enter student's phone number: ";
    cin >> phone;
    if (!validatePhoneNumber(phone)) return;
    cin.ignore();  // Ignore newline left in buffer

    cout << "Enter student's computer name: ";
    cin.getline(pcname, 50);
    if (!validateInput(pcname, 50)) return;

    cout << "Enter student's computer serial number: ";
    cin.getline(serial, 50);
    if (!validateInput(serial, 50)) return;

    add_student_to_db(name, student_id, gender, department, phone, pcname, serial);

    cout << "\n=============================================" << endl;
    cout << "        Student Added Successfully!" << endl;
    cout << "=============================================" << endl;
}

void search_student() {
    char choice;
    char student_id[50];
    char name[50];

    cout << "\n=============================================" << endl;
    cout << "          Search for Student" << endl;
    cout << "=============================================" << endl;
    cout << "Search by: " << endl;
    cout << "1. ID" << endl;
    cout << "2. Name" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    cin.ignore();  // Ignore newline left in buffer

    if (choice == '1') {
        cout << "Enter student's ID to search: ";
        cin.getline(student_id, 50);
        search_student_in_db(student_id);
    } else if (choice == '2') {
        cout << "Enter student's Name to search: ";
        cin.getline(name, 50);
        cout << "Searching by name is not yet implemented.\n";
    } else {
        cout << "\nInvalid choice. Please enter 1 or 2." << endl;
    }
}

void display_students() {
    cout << "\n=============================================" << endl;
    cout << "             Student List" << endl;
    cout << "=============================================" << endl;
    display_all_students_from_db();
}

void update_student() {
    char student_id[50];
    char name[50], gender[10], department[50], pcname[50], serial[50];
    long long phone;

    cout << "\n=============================================" << endl;
    cout << "          Update Student Information" << endl;
    cout << "=============================================" << endl;
    cout << "Enter student's ID to update: ";
    cin.ignore();
    cin.getline(student_id, 50);
    if (!validateInput(student_id, 50)) return;

    cout << "Checking if student exists...\n";
    search_student_in_db(student_id);

    cout << "\nEnter new name: ";
    cin.getline(name, 50);
    if (!validateInput(name, 50)) return;

    cout << "Enter new gender (Male / Female): ";
    cin.getline(gender, 10);
    if (!validateGender(gender)) return;

    cout << "Enter new department: ";
    cin.getline(department, 50);
    if (!validateInput(department, 50)) return;

    cout << "Enter new phone number: ";
    cin >> phone;
    if (!validatePhoneNumber(phone)) return;
    cin.ignore();  // Ignore newline left in buffer

    cout << "Enter new computer name: ";
    cin.getline(pcname, 50);
    if (!validateInput(pcname, 50)) return;

    cout << "Enter new computer serial number: ";
    cin.getline(serial, 50);
    if (!validateInput(serial, 50)) return;

    update_student_in_db(student_id, name, gender, department, phone, pcname, serial);

    cout << "\n=============================================" << endl;
    cout << "        Student Details Updated Successfully!" << endl;
    cout << "=============================================" << endl;
}

void delete_student() {
    char student_id[50];

    cout << "\n=============================================" << endl;
    cout << "          Delete Student" << endl;
    cout << "=============================================" << endl;
    cout << "Enter student's ID to delete: ";
    cin.ignore();
    cin.getline(student_id, 50);
    if (!validateInput(student_id, 50)) return;

    delete_student_from_db(student_id);

    cout << "\n=============================================" << endl;
    cout << "       Student Deleted Successfully!" << endl;
    cout << "=============================================" << endl;
}
