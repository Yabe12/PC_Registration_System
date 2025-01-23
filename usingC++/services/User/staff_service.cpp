#include <iostream>
#include <cstring> // For strcmp
#include "./models/users/student.cpp"
#include "../../models/users/staff.cpp"
using namespace std;


// Function declarations
void sort_staff();
void add_staff();
void search_staff();
void display_staff();
void update_staff();
void delete_staff();

int main() {
    int choice;
    do {
        cout << "\nStaff Management System\n";
        cout << "1. Add Staff\n";
        cout << "2. Display Staff\n";
        cout << "3. Search Staff\n";
        cout << "4. Update Staff\n";
        cout << "5. Delete Staff\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_staff();
                break;
            case 2:
                display_staff();
                break;
            case 3:
                search_staff();
                break;
            case 4:
                update_staff();
                break;
            case 5:
                delete_staff();
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

void sort_staff() {
    if (staff_head == NULL) return;

    staff* current = staff_head->next;
    while (current != NULL) {
        staff* key = current;
        staff* prev = staff_head;

        while (prev != key && strcmp(prev->name, key->name) < 0) {
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
    cout << "Staff list sorted successfully.\n";
}

void add_staff() {
    staff* new_staff = new staff();
    cout << "Enter staff's name: ";
    cin.ignore();
    cin.getline(new_staff->name, 20);
    cout << "Enter staff's ID: ";
    cin >> new_staff->id;
    cout << "Enter staff's gender (M/F): ";
    cin >> new_staff->gender;
    cout << "Enter staff's role: ";
    cin >> new_staff->job;
    cout << "Enter staff's type of PC (personal laptop/office laptop): ";
    cin >> new_staff->typeofpc;
    cout << "Enter staff's phone number: ";
    cin >> new_staff->phone;
    cout << "Enter staff's computer name: ";
    cin >> new_staff->pcname;
    cout << "Enter staff's computer serial number: ";
    cin >> new_staff->serial;

    new_staff->next = NULL;
    new_staff->prev = staff_tall;

    if (staff_tall != NULL) {
        staff_tall->next = new_staff;
    }
    staff_tall = new_staff;

    if (staff_head == NULL) {
        staff_head = staff_tall;
    }

    cout << "Staff added successfully.\n";
    sort_staff();
}

void search_staff() {
    char name[20];
    cout << "Enter staff's name to search: ";
    cin.ignore();
    cin.getline(name, 20);

    staff* current = staff_head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            cout << "Staff found:\n";
            cout << "Name: " << current->name << "\n";
            cout << "ID: " << current->id << "\n";
            cout << "Gender: " << current->gender << "\n";
            cout << "Role: " << current->job << "\n";
            cout << "Type of PC: " << current->typeofpc << "\n";
            cout << "Phone: " << current->phone << "\n";
            cout << "Computer Name: " << current->pcname << "\n";
            cout << "Computer Serial Number: " << current->serial << "\n";
            return;
        }
        current = current->next;
    }
    cout << "Staff not found.\n";
}

void display_staff() {
    staff* current = staff_head;
    cout << "Staff List:\n";
    while (current != NULL) {
        cout << "Name: " << current->name << "\n";
        cout << "ID: " << current->id << "\n";
        cout << "Gender: " << current->gender << "\n";
        cout << "Role: " << current->job << "\n";
        cout << "Type of PC: " << current->typeofpc << "\n";
        cout << "Phone: " << current->phone << "\n";
        cout << "Computer Name: " << current->pcname << "\n";
        cout << "Computer Serial Number: " << current->serial << "\n";
        cout << endl;
        current = current->next;
    }
}

void update_staff() {
    char id[20];
    cout << "Enter staff's ID to update: ";
    cin >> id;

    staff* current = staff_head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            cout << "Staff found. Updating details...\n";
            cout << "Enter new name: ";
            cin.ignore();
            cin.getline(current->name, 20);
            cout << "Enter new gender (M/F): ";
            cin >> current->gender;
            cout << "Enter new role: ";
            cin >> current->job;
            cout << "Enter new type of PC: ";
            cin >> current->typeofpc;
            cout << "Enter new phone number: ";
            cin >> current->phone;
            cout << "Enter new computer name: ";
            cin >> current->pcname;
            cout << "Enter new computer serial number: ";
            cin >> current->serial;

            cout << "Staff details updated successfully.\n";
            return;
        }
        current = current->next;
    }
    cout << "Staff not found.\n";
}

void delete_staff() {
    char id[20];
    cout << "Enter staff's ID to delete: ";
    cin >> id;

    staff* current = staff_head;
    while (current != NULL && strcmp(current->id, id) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Staff not found.\n";
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        staff_head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    delete current;
    cout << "Staff deleted successfully.\n";
}
