#include <iostream>
#include <cstring>
using namespace std;

// Define the structure for nonstaff
struct nonstaff {
    char name[50];
    char id[20];
    char gender;
    char phone[15];
    char pcname[50];
    char serial[50];
    nonstaff *next;
    nonstaff *prev;
};

// Global variables for the linked list
nonstaff *nonstaff_head = NULL;
nonstaff *nonstaff_tall = NULL;

// Function declarations
void sort_nonstaff();
void add_nonstaff();
void search_nonstaff();
void display_nonstaff();
void update_nonstaff();
void delete_nonstaff();

int main() {
    int choice;
    do {
        cout << "\nNonstaff Management System\n";
        cout << "1. Add Nonstaff\n";
        cout << "2. Search Nonstaff\n";
        cout << "3. Display Nonstaff\n";
        cout << "4. Update Nonstaff\n";
        cout << "5. Delete Nonstaff\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_nonstaff();
                break;
            case 2:
                search_nonstaff();
                break;
            case 3:
                display_nonstaff();
                break;
            case 4:
                update_nonstaff();
                break;
            case 5:
                delete_nonstaff();
                break;
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

// Function definitions
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
    cout << "Nonstaff list sorted successfully." << endl;
}

void add_nonstaff() {
    nonstaff *new_nonstaff = new nonstaff;
    cout << "Enter nonstaff's name: ";
    cin.ignore();
    cin.getline(new_nonstaff->name, 50);
    cout << "Enter nonstaff's ID: ";
    cin >> new_nonstaff->id;
    cout << "Enter nonstaff's gender (M/F): ";
    cin >> new_nonstaff->gender;
    cout << "Enter nonstaff's phone: ";
    cin >> new_nonstaff->phone;
    cout << "Enter nonstaff computer name: ";
    cin.ignore();
    cin.getline(new_nonstaff->pcname, 50);
    cout << "Enter nonstaff computer serial number: ";
    cin.getline(new_nonstaff->serial, 50);

    new_nonstaff->next = NULL;
    new_nonstaff->prev = nonstaff_tall;
    if (nonstaff_tall != NULL) {
        nonstaff_tall->next = new_nonstaff;
    }
    nonstaff_tall = new_nonstaff;
    if (nonstaff_head == NULL) {
        nonstaff_head = nonstaff_tall;
    }

    cout << "Nonstaff added successfully." << endl;
    sort_nonstaff();
}

void search_nonstaff() {
    char name[50];
    cout << "Enter nonstaff's name to search: ";
    cin.ignore();
    cin.getline(name, 50);

    nonstaff *current = nonstaff_head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            cout << "Nonstaff found:" << endl;
            cout << "Name: " << current->name << endl;
            cout << "ID: " << current->id << endl;
            cout << "Gender: " << current->gender << endl;
            cout << "Phone: " << current->phone << endl;
            cout << "Computer Name: " << current->pcname << endl;
            cout << "Computer Serial Number: " << current->serial << endl;
            return;
        }
        current = current->next;
    }
    cout << "Nonstaff not found." << endl;
}

void display_nonstaff() {
    nonstaff *current = nonstaff_head;
    if (current == NULL) {
        cout << "No nonstaff members found." << endl;
        return;
    }

    cout << "Nonstaff List:" << endl;
    while (current != NULL) {
        cout << "Name: " << current->name << endl;
        cout << "ID: " << current->id << endl;
        cout << "Gender: " << current->gender << endl;
        cout << "Phone: " << current->phone << endl;
        cout << "Computer Name: " << current->pcname << endl;
        cout << "Computer Serial Number: " << current->serial << endl;
        cout << "---------------------------------" << endl;
        current = current->next;
    }
}

void update_nonstaff() {
    char id[20];
    cout << "Enter ID to update: ";
    cin >> id;

    nonstaff *current = nonstaff_head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            cout << "Nonstaff found. Enter new details:" << endl;
            cout << "Enter new name: ";
            cin.ignore();
            cin.getline(current->name, 50);
            cout << "Enter new gender (M/F): ";
            cin >> current->gender;
            cout << "Enter new phone: ";
            cin >> current->phone;
            cout << "Enter new computer name: ";
            cin.ignore();
            cin.getline(current->pcname, 50);
            cout << "Enter new computer serial number: ";
            cin.getline(current->serial, 50);

            cout << "Nonstaff updated successfully." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Nonstaff not found." << endl;
}

void delete_nonstaff() {
    char id[20];
    cout << "Enter nonstaff's ID to delete: ";
    cin >> id;

    nonstaff *current = nonstaff_head;
    while (current != NULL && strcmp(current->id, id) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Nonstaff not found." << endl;
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
    cout << "Nonstaff deleted successfully." << endl;
}
