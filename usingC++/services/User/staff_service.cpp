#include "./staff_service.h"
#include <iostream>
#include <cstring>
using namespace std;

// Define global pointers for the linked list
staff* staff_head = NULL;
staff* staff_tall = NULL;

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
    cout << "\n=============================================" << endl;
    cout << "          Staff List Sorted" << endl;
    cout << "=============================================" << endl;
}

void add_staff() {
    staff* new_staff = new staff;
    cout << "\n=============================================" << endl;
    cout << "           Add New Staff Member" << endl;
    cout << "=============================================" << endl;
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

    cout << "\n=============================================" << endl;
    cout << "  Staff added successfully!" << endl;
    cout << "=============================================" << endl;
    sort_staff();
}

void search_staff() {
    char name[20];
    cout << "\n=============================================" << endl;
    cout << "          Search for Staff Member" << endl;
    cout << "=============================================" << endl;
    cout << "Enter staff's name to search: ";
    cin.ignore();
    cin.getline(name, 20);

    staff* current = staff_head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            cout << "\n=============================================" << endl;
            cout << "            Staff Found" << endl;
            cout << "=============================================" << endl;
            cout << "Name: " << current->name << endl;
            cout << "ID: " << current->id << endl;
            cout << "Gender: " << current->gender << endl;
            cout << "Role: " << current->job << endl;
            cout << "Type of PC: " << current->typeofpc << endl;
            cout << "Phone: " << current->phone << endl;
            cout << "Computer Name: " << current->pcname << endl;
            cout << "Computer Serial Number: " << current->serial << endl;
            cout << "=============================================" << endl;
            return;
        }
        current = current->next;
    }
    cout << "\n=============================================" << endl;
    cout << "  Staff not found." << endl;
    cout << "=============================================" << endl;
}

void display_staff() {
    staff* current = staff_head;
    cout << "\n=============================================" << endl;
    cout << "             Staff List" << endl;
    cout << "=============================================" << endl;
    if (current == NULL) {
        cout << "No staff members found." << endl;
        cout << "=============================================" << endl;
        return;
    }

    while (current != NULL) {
        cout << "\n---------------------------------------------" << endl;
        cout << "Name: " << current->name << endl;
        cout << "ID: " << current->id << endl;
        cout << "Gender: " << current->gender << endl;
        cout << "Role: " << current->job << endl;
        cout << "Type of PC: " << current->typeofpc << endl;
        cout << "Phone: " << current->phone << endl;
        cout << "Computer Name: " << current->pcname << endl;
        cout << "Computer Serial Number: " << current->serial << endl;
        cout << "---------------------------------------------" << endl;
        current = current->next;
    }
    cout << "\n=============================================" << endl;
}

void update_staff() {
    char id[20];
    cout << "\n=============================================" << endl;
    cout << "        Update Staff Information" << endl;
    cout << "=============================================" << endl;
    cout << "Enter staff's ID to update: ";
    cin >> id;

    staff* current = staff_head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            cout << "\n=============================================" << endl;
            cout << "  Staff found. Enter new details:" << endl;
            cout << "=============================================" << endl;
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

            cout << "\n=============================================" << endl;
            cout << "  Staff updated successfully!" << endl;
            cout << "=============================================" << endl;
            return;
        }
        current = current->next;
    }
    cout << "\n=============================================" << endl;
    cout << "  Staff not found." << endl;
    cout << "=============================================" << endl;
}

void delete_staff() {
    char id[20];
    cout << "\n=============================================" << endl;
    cout << "        Delete Staff Member" << endl;
    cout << "=============================================" << endl;
    cout << "Enter staff's ID to delete: ";
    cin >> id;

    staff* current = staff_head;
    while (current != NULL && strcmp(current->id, id) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "\n=============================================" << endl;
        cout << "  Staff not found." << endl;
        cout << "=============================================" << endl;
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
    cout << "\n=============================================" << endl;
    cout << "  Staff deleted successfully!" << endl;
    cout << "=============================================" << endl;
}
