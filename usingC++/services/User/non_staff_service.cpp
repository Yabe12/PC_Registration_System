#include "./non_staff_service.h"
#include "../../middleware/input_validation.h"
#include <iostream>
#include <cstring>

using namespace std;

// Define global pointers for the linked list
nonstaff* nonstaff_head = NULL;
nonstaff* nonstaff_tall = NULL;

void sort_nonstaff() {
    if (nonstaff_head == NULL) return;

    nonstaff *current = nonstaff_head->next;
    while (current != NULL) {
        nonstaff *key = current;
        nonstaff *prev = current->prev;
        while (prev != NULL && strcmp(prev->name, key->name) > 0) {
            prev = prev->prev;
        }
        current = current->next;
        if (key->prev != NULL) {
            key->prev->next = key->next;
        }
        if (key->next != NULL) {
            key->next->prev = key->prev;
        }
        if (prev == NULL) {
            key->next = nonstaff_head;
            nonstaff_head->prev = key;
            nonstaff_head = key;
            key->prev = NULL;
        } else {
            key->next = prev->next;
            if (prev->next != NULL) {
                prev->next->prev = key;
            }
            prev->next = key;
            key->prev = prev;
        }
    }
    cout << "\n=============================================" << endl;
    cout << "          Nonstaff List Sorted" << endl;
    cout << "=============================================" << endl;
}

void add_nonstaff() {
    nonstaff *new_nonstaff = new nonstaff;
    cout << "\n=============================================" << endl;
    cout << "           Add New Nonstaff Member" << endl;
    cout << "=============================================" << endl;
    cout << "Enter nonstaff's name: ";
    cin.ignore();
    cin.getline(new_nonstaff->name, 50);
    if (!validateInput(new_nonstaff->name, 50)) return;

    cout << "Enter nonstaff's ID: ";
    cin >> new_nonstaff->id;
    if (!validateInput(new_nonstaff->id, 20)) return;

    cout << "Enter nonstaff's gender (M/F): ";
    cin >> new_nonstaff->gender;
    if (!validateGender(new_nonstaff->gender)) return;

    cout << "Enter nonstaff's phone: ";
    cin >> new_nonstaff->phone;
    if (!validatePhoneNumber(new_nonstaff->phone)) return;

    cout << "Enter nonstaff computer name: ";
    cin.ignore();
    cin.getline(new_nonstaff->pcname, 50);
    if (!validateInput(new_nonstaff->pcname, 50)) return;

    cout << "Enter nonstaff computer serial number: ";
    cin.getline(new_nonstaff->serial, 50);
    if (!validateInput(new_nonstaff->serial, 50)) return;

    new_nonstaff->next = NULL;
    new_nonstaff->prev = nonstaff_tall;
    if (nonstaff_tall != NULL) {
        nonstaff_tall->next = new_nonstaff;
    }
    nonstaff_tall = new_nonstaff;
    if (nonstaff_head == NULL) {
        nonstaff_head = nonstaff_tall;
    }

    cout << "\n=============================================" << endl;
    cout << "  Nonstaff added successfully!" << endl;
    cout << "=============================================" << endl;
    sort_nonstaff();
}

void search_nonstaff() {
    char name[50];
    cout << "\n=============================================" << endl;
    cout << "          Search for Nonstaff Member" << endl;
    cout << "=============================================" << endl;
    cout << "Enter nonstaff's name to search: ";
    cin.ignore();
    cin.getline(name, 50);

    nonstaff *current = nonstaff_head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            cout << "\n=============================================" << endl;
            cout << "            Nonstaff Found" << endl;
            cout << "=============================================" << endl;
            cout << "Name: " << current->name << endl;
            cout << "ID: " << current->id << endl;
            cout << "Gender: " << current->gender << endl;
            cout << "Phone: " << current->phone << endl;
            cout << "Computer Name: " << current->pcname << endl;
            cout << "Computer Serial Number: " << current->serial << endl;
            cout << "=============================================" << endl;
            return;
        }
        current = current->next;
    }
    cout << "\n=============================================" << endl;
    cout << "  Nonstaff not found." << endl;
    cout << "=============================================" << endl;
}

void display_nonstaff() {
    nonstaff *current = nonstaff_head;
    cout << "\n=============================================" << endl;
    cout << "             Nonstaff List" << endl;
    cout << "=============================================" << endl;
    if (current == NULL) {
        cout << "No nonstaff members found." << endl;
        cout << "=============================================" << endl;
        return;
    }

    while (current != NULL) {
        cout << "\n---------------------------------------------" << endl;
        cout << "Name: " << current->name << endl;
        cout << "ID: " << current->id << endl;
        cout << "Gender: " << current->gender << endl;
        cout << "Phone: " << current->phone << endl;
        cout << "Computer Name: " << current->pcname << endl;
        cout << "Computer Serial Number: " << current->serial << endl;
        current = current->next;
    }
    cout << "\n=============================================" << endl;
}

void update_nonstaff() {
    char id[20];
    cout << "\n=============================================" << endl;
    cout << "        Update Nonstaff Information" << endl;
    cout << "=============================================" << endl;
    cout << "Enter ID to update: ";
    cin >> id;

    nonstaff *current = nonstaff_head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            cout << "\nNonstaff found. Enter new details:" << endl;
            cout << "Enter new name: ";
            cin.ignore();
            cin.getline(current->name, 50);
            if (!validateInput(current->name, 50)) return;

            cout << "Enter new gender (M/F): ";
            cin >> current->gender;
            if (!validateGender(current->gender)) return;

            cout << "Enter new phone: ";
            cin >> current->phone;
            if (!validatePhoneNumber(current->phone)) return;

            cout << "Enter new computer name: ";
            cin.ignore();
            cin.getline(current->pcname, 50);
            if (!validateInput(current->pcname, 50)) return;

            cout << "Enter new computer serial number: ";
            cin.getline(current->serial, 50);
            if (!validateInput(current->serial, 50)) return;

            cout << "\n=============================================" << endl;
            cout << "  Nonstaff updated successfully!" << endl;
            cout << "=============================================" << endl;
            return;
        }
        current = current->next;
    }
    cout << "\n=============================================" << endl;
    cout << "  Nonstaff not found." << endl;
    cout << "=============================================" << endl;
}

void delete_nonstaff() {
    char id[20];
    cout << "\n=============================================" << endl;
    cout << "        Delete Nonstaff Member" << endl;
    cout << "=============================================" << endl;
    cout << "Enter nonstaff's ID to delete: ";
    cin >> id;

    nonstaff *current = nonstaff_head;
    while (current != NULL && strcmp(current->id, id) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "\n=============================================" << endl;
        cout << "  Nonstaff not found." << endl;
        cout << "=============================================" << endl;
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        nonstaff_head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    delete current;
    cout << "\n=============================================" << endl;
    cout << "  Nonstaff deleted successfully!" << endl;
    cout << "=============================================" << endl;
}
