#include <iostream>
#include <cstring>
#include "../../models/users/student.h"
#include "../../middleware/input_validation.h"
#include "StudentDBOperations.h"

using namespace std;

// Function to add a new student
void add_student() {
    char name[50], id[20], gender[10], department[50], pcname[50], serial[50];
    long long phone;

    cout << "\n=============================================" << endl;
    cout << "          Add New Student" << endl;
    cout << "=============================================" << endl;

    cout << "Enter student's name: ";
    cin.ignore();
    cin.getline(name, 50);
    if (!validateInput(name, 50)) return;

    cout << "Enter student's ID: ";
    cin.getline(id, 20);
    if (!validateInput(id, 20)) return;

    cout << "Enter student's gender (Male / Female): ";
    cin.getline(gender, 10);
    if (!validateGender(gender)) return;

    cout << "Enter student's department: ";
    cin.getline(department, 50);
    if (!validateInput(department, 50)) return;

    cout << "Enter student's phone number: ";
    cin >> phone;
    if (!validatePhoneNumber(phone)) return;

    cout << "Enter student's computer name: ";
    cin.ignore();
    cin.getline(pcname, 50);
    if (!validateInput(pcname, 50)) return;

    cout << "Enter student's computer serial number: ";
    cin.getline(serial, 50);
    if (!validateInput(serial, 50)) return;

    // Call function from StudentDBOperations to add student to the database
    add_student_to_db(name, id, gender, department, phone, pcname, serial);

    cout << "\n=============================================" << endl;
    cout << "        Student Added Successfully!" << endl;
    cout << "=============================================" << endl;
}

// Function to search for a student by ID or Name
void search_student() {
    char choice;
    char id[20];
    char name[50];

    cout << "\n=============================================" << endl;
    cout << "          Search for Student" << endl;
    cout << "=============================================" << endl;
    cout << "Search by: " << endl;
    cout << "1. ID" << endl;
    cout << "2. Name" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == '1') {
        cout << "Enter student's ID to search: ";
        cin >> id;

        // Call search function from StudentDBOperations
        search_student_in_db(id);
    } else if (choice == '2') {
        cout << "Enter student's Name to search: ";
        cin.ignore();
        cin.getline(name, 50);

        // Search student by name could be added here or you can modify the search function to also work for name
        cout << "Searching by name is not yet implemented.\n";
    } else {
        cout << "\nInvalid choice. Please enter 1 or 2." << endl;
    }
}

// Function to display all students
void display_students() {
    cout << "\n=============================================" << endl;
    cout << "             Student List" << endl;
    cout << "=============================================" << endl;

    // Call display function from StudentDBOperations to show all students
    display_all_students_from_db();
}

// Function to update a student's details
void update_student() {
    char id[20];
    char name[50], gender[10], department[50], pcname[50], serial[50];
    long long phone;

    cout << "\n=============================================" << endl;
    cout << "          Update Student Information" << endl;
    cout << "=============================================" << endl;
    cout << "Enter student's ID to update: ";
    cin >> id;

    // Check if student exists, if not return
    cout << "Checking if student exists...\n";
    // The search can be implemented here as well to verify student exists
    search_student_in_db(id); 

    cout << "\nEnter new name: ";
    cin.ignore();
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

    cout << "Enter new computer name: ";
    cin.ignore();
    cin.getline(pcname, 50);
    if (!validateInput(pcname, 50)) return;

    cout << "Enter new computer serial number: ";
    cin.getline(serial, 50);
    if (!validateInput(serial, 50)) return;

    // Call update function from StudentDBOperations to update the student in the database
    update_student_in_db(id, name, gender, department, phone, pcname, serial);

    cout << "\n=============================================" << endl;
    cout << "        Student Details Updated Successfully!" << endl;
    cout << "=============================================" << endl;
}

// Function to delete a student by ID
void delete_student() {
    char id[20];

    cout << "\n=============================================" << endl;
    cout << "          Delete Student" << endl;
    cout << "=============================================" << endl;
    cout << "Enter student's ID to delete: ";
    cin >> id;

    // Call function from StudentDBOperations to delete the student from the database
    delete_student_from_db(id);

    cout << "\n=============================================" << endl;
    cout << "       Student Deleted Successfully!" << endl;
    cout << "=============================================" << endl;
}
