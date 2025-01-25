#include <iostream>
#include <cstring>
#include "../../models/users/student.h"
#include "../../middleware/input_validation.h"
#include "student_service.h"

using namespace std;

// Define global pointers for the linked list
student* student_head = NULL;
student* student_tall = NULL;

void sort_student() {
    if (student_head == NULL) return;
    student *current = student_head->next;
    while (current != NULL) {
        student *key = current;
        student *prev = student_head;
        while (prev != key && strcmp(prev->id, key->id) < 0) {
            prev = prev->next;
        }
        if (prev != key) {
            key->prev->next = key->next;
            if (key->next != NULL) {
                key->next->prev = key->prev;
            }
            key->next = prev->next;
            if (prev->next != NULL) {
                prev->next->prev = key;
            }
            prev->next = key;
            key->prev = prev;
        }
        current = current->next;
    }
    cout << "\n=============================================" << endl;
    cout << "        Student List Sorted Successfully" << endl;
    cout << "=============================================" << endl;
}

void add_student() {
    student *new_student = new student;
    cout << "\n=============================================" << endl;
    cout << "          Add New Student" << endl;
    cout << "=============================================" << endl;
    cout << "Enter student's name: ";
    cin.ignore();
    cin.getline(new_student->name, 20);
    if (!validateInput(new_student->name, 20)) return;

    cout << "Enter student's ID: ";
    cin >> new_student->id;
    if (!validateInput(new_student->id, 10)) return;

    cout << "Enter student's gender (M/F): ";
    cin >> new_student->gender;
    if (!validateGender(new_student->gender)) return;

    cout << "Enter student's department: ";
    cin >> new_student->department;
    if (!validateInput(new_student->department, 50)) return;

    cout << "Enter student's year: ";
    cin >> new_student->year;

    cout << "Enter student's phone number: ";
    cin >> new_student->phone;
    if (!validatePhoneNumber(new_student->phone)) return;

    cout << "Enter student's computer name: ";
    cin >> new_student->pcname;
    if (!validateInput(new_student->pcname, 50)) return;

    cout << "Enter student's computer serial number: ";
    cin >> new_student->serial;
    if (!validateInput(new_student->serial, 50)) return;

    new_student->next = NULL;
    new_student->prev = student_tall;
    if (student_tall != NULL) {
        student_tall->next = new_student;
    }
    student_tall = new_student;
    if (student_head == NULL) {
        student_head = student_tall;
    }

    cout << "\n=============================================" << endl;
    cout << "        Student Added Successfully!" << endl;
    cout << "=============================================" << endl;
    sort_student();
}

void search_student() {
    char choice;
    char id[10];
    char name[50];

    cout << "\n=============================================" << endl;
    cout << "          Search for Student" << endl;
    cout << "=============================================" << endl;
    cout << "Search by: " << endl;
    cout << "1. ID" << endl;
    cout << "2. Name" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    student *current = student_head;

    if (choice == '1') {
        cout << "Enter student's ID to search: ";
        cin >> id;

        while (current != NULL) {
            if (strcmp(current->id, id) == 0) {
                cout << "\n=============================================" << endl;
                cout << "            Student Found" << endl;
                cout << "=============================================" << endl;
                cout << "Name: " << current->name << endl;
                cout << "ID: " << current->id << endl;
                cout << "Gender: " << current->gender << endl;
                cout << "Department: " << current->department << endl;
                cout << "Year: " << current->year << endl;
                cout << "Phone: " << current->phone << endl;
                cout << "Computer Name: " << current->pcname << endl;
                cout << "Computer Serial Number: " << current->serial << endl;
                return;
            }
            current = current->next;
        }
        cout << "\n=============================================" << endl;
        cout << "        Student Not Found" << endl;
        cout << "=============================================" << endl;

    } else if (choice == '2') {
        cout << "Enter student's Name to search: ";
        cin.ignore();
        cin.getline(name, 50);

        while (current != NULL) {
            if (strcmp(current->name, name) == 0) {
                cout << "\n=============================================" << endl;
                cout << "            Student Found" << endl;
                cout << "=============================================" << endl;
                cout << "Name: " << current->name << endl;
                cout << "ID: " << current->id << endl;
                cout << "Gender: " << current->gender << endl;
                cout << "Department: " << current->department << endl;
                cout << "Year: " << current->year << endl;
                cout << "Phone: " << current->phone << endl;
                cout << "Computer Name: " << current->pcname << endl;
                cout << "Computer Serial Number: " << current->serial << endl;
                return;
            }
            current = current->next;
        }
        cout << "\n=============================================" << endl;
        cout << "        Student Not Found" << endl;
        cout << "=============================================" << endl;

    } else {
        cout << "\n=============================================" << endl;
        cout << "Invalid choice. Please enter 1 or 2." << endl;
        cout << "=============================================" << endl;
    }
}

void display_students() {
    student *current = student_head;
    cout << "\n=============================================" << endl;
    cout << "             Student List" << endl;
    cout << "=============================================" << endl;
    if (current == NULL) {
        cout << "No students found." << endl;
        cout << "=============================================" << endl;
        return;
    }

    while (current != NULL) {
        cout << "\n---------------------------------------------" << endl;
        cout << "Name: " << current->name << endl;
        cout << "ID: " << current->id << endl;
        cout << "Gender: " << current->gender << endl;
        cout << "Department: " << current->department << endl;
        cout << "Year: " << current->year << endl;
        cout << "Phone: " << current->phone << endl;
        cout << "Computer Name: " << current->pcname << endl;
        cout << "Computer Serial Number: " << current->serial << endl;
        current = current->next;
    }
    cout << "\n=============================================" << endl;
}

void update_student() {
    char id[20];
    cout << "\n=============================================" << endl;
    cout << "          Update Student Information" << endl;
    cout << "=============================================" << endl;
    cout << "Enter student's ID to update: ";
    cin >> id;

    student *current = student_head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            cout << "\n=============================================" << endl;
            cout << "       Student Found. What would you like to update?" << endl;
            cout << "=============================================" << endl;
            cout << "1. All details" << endl;
            cout << "2. Name" << endl;
            cout << "3. Gender" << endl;
            cout << "4. Department" << endl;
            cout << "5. Year" << endl;
            cout << "6. Phone number" << endl;
            cout << "7. Computer name" << endl;
            cout << "8. Computer serial number" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    cin.getline(current->name, 50);
                    if (!validateInput(current->name, 50)) return;

                    cout << "Enter new gender (M/F): ";
                    cin >> current->gender;
                    cin.ignore();
                    if (!validateGender(current->gender)) return;

                    cout << "Enter new department: ";
                    cin.getline(current->department, 50);
                    if (!validateInput(current->department, 50)) return;

                    cout << "Enter new year: ";
                    cin >> current->year;
                    cin.ignore();

                    cout << "Enter new phone number: ";
                    cin >> current->phone;
                    cin.ignore();
                    if (!validatePhoneNumber(current->phone)) return;

                    cout << "Enter new computer name: ";
                    cin.getline(current->pcname, 50);
                    if (!validateInput(current->pcname, 50)) return;

                    cout << "Enter new computer serial number: ";
                    cin.getline(current->serial, 50);
                    if (!validateInput(current->serial, 50)) return;
                    break;

                case 2:
                    cout << "Enter new name: ";
                    cin.getline(current->name, 50);
                    if (!validateInput(current->name, 50)) return;
                    break;

                case 3:
                    cout << "Enter new gender (M/F): ";
                    cin >> current->gender;
                    cin.ignore();
                    if (!validateGender(current->gender)) return;
                    break;

                case 4:
                    cout << "Enter new department: ";
                    cin.getline(current->department, 50);
                    if (!validateInput(current->department, 50)) return;
                    break;

                case 5:
                    cout << "Enter new year: ";
                    cin >> current->year;
                    cin.ignore();
                    break;

                case 6:
                    cout << "Enter new phone number: ";
                    cin >> current->phone;
                    cin.ignore();
                    if (!validatePhoneNumber(current->phone)) return;
                    break;

                case 7:
                    cout << "Enter new computer name: ";
                    cin.getline(current->pcname, 50);
                    if (!validateInput(current->pcname, 50)) return;
                    break;

                case 8:
                    cout << "Enter new computer serial number: ";
                    cin.getline(current->serial, 50);
                    if (!validateInput(current->serial, 50)) return;
                    break;

                default:
                    cout << "Invalid choice. No updates were made." << endl;
                    return;
            }

            cout << "\n=============================================" << endl;
            cout << "    Student Details Updated Successfully!" << endl;
            cout << "=============================================" << endl;
            return;
        }
        current = current->next;
    }

    cout << "\n=============================================" << endl;
    cout << "    Student Not Found" << endl;
    cout << "=============================================" << endl;
}

void delete_student() {
    char id[20];
    cout << "\n=============================================" << endl;
    cout << "          Delete Student" << endl;
    cout << "=============================================" << endl;
    cout << "Enter student's ID to delete: ";
    cin >> id;
    student *current = student_head;
    while (current != NULL && strcmp(current->id, id) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "\n=============================================" << endl;
        cout << "        Student Not Found" << endl;
        cout << "=============================================" << endl;
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        student_head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    delete current;
    cout << "\n=============================================" << endl;
    cout << "       Student Deleted Successfully!" << endl;
    cout << "=============================================" << endl;
}
