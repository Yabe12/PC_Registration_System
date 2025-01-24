#include "./student_service.h"

// Define global pointers for the linked list
student* student_head = NULL;
student* student_tall = NULL;

void sort_student() {
    if (student_head == NULL) return;
    student* current = student_head->next;
    while (current != NULL) {
        student* key = current;
        student* prev = student_head;
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
    cout << "Student list sorted successfully." << endl;
}

void add_student() {
    student* new_student = new student;
    cout << "Enter student's name: ";
    cin.ignore();
    cin.getline(new_student->name, 50);
    cout << "Enter student's ID: ";
    cin >> new_student->id;
    cout << "Enter student's gender (M/F): ";
    cin >> new_student->gender;
    cout << "Enter student's department: ";
    cin >> new_student->department;
    cout << "Enter student's year: ";
    cin >> new_student->year;
    cout << "Enter student's phone number: ";
    cin >> new_student->phone;
    cout << "Enter student's computer name: ";
    cin >> new_student->pcname;
    cout << "Enter student's computer serial number: ";
    cin >> new_student->serial;

    new_student->next = NULL;
    new_student->prev = student_tall;
    if (student_tall != NULL) {
        student_tall->next = new_student;
    }
    student_tall = new_student;
    if (student_head == NULL) {
        student_head = student_tall;
    }

    cout << "The student is added" << endl;
    sort_student();
}

void search_student() {
    char choice;
    char id[20];
    char name[50];

    cout << "Search by: " << endl;
    cout << "1. ID" << endl;
    cout << "2. Name" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    student* current = student_head;

    if (choice == '1') {
        cout << "Enter student's ID to search: ";
        cin >> id;

        while (current != NULL) {
            if (strcmp(current->id, id) == 0) {
                cout << "Student found:" << endl;
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
        cout << "Student not found." << endl;

    } else if (choice == '2') {
        cout << "Enter student's Name to search: ";
        cin.ignore();
        cin.getline(name, 50);

        while (current != NULL) {
            if (strcmp(current->name, name) == 0) {
                cout << "Student found:" << endl;
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
        cout << "Student not found." << endl;

    } else {
        cout << "Invalid choice. Please enter 1 or 2." << endl;
    }
}

void display_students() {
    student* current = student_head;
    cout << "Student List:" << endl;
    while (current != NULL) {
        cout << "Name: " << current->name << endl;
        cout << "ID: " << current->id << endl;
        cout << "Gender: " << current->gender << endl;
        cout << "Department: " << current->department << endl;
        cout << "Year: " << current->year << endl;
        cout << "Phone: " << current->phone << endl;
        cout << "Computer Name: " << current->pcname << endl;
        cout << "Computer Serial Number: " << current->serial << endl;
        current = current->next;
        cout << endl;
    }
}

void delete_student() {
    char id[20];
    cout << "Enter student's ID to delete: ";
    cin >> id;
    student* current = student_head;
    while (current != NULL && strcmp(current->id, id) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Student not found." << endl;
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
    cout << "Student deleted successfully." << endl;
}