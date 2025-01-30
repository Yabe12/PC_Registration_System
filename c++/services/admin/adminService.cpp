#include <iostream>
#include <cstring>
#include "../../models/admin/admin.h"
#include "../../middleware/input_validation.h"
#include "../../database/admin/AdminDBOperations.h"  // Include the new header for DB operations
#include "../../database/connection.h"  // Include the connection header

using namespace std;

// Global pointers for the linked list
Admin* admin_head = nullptr;
Admin* admin_tall = nullptr;

void add_admin() {
    Admin* new_admin = new Admin;
    cout << "Enter admin username: ";
    cin >> new_admin->username;
    if (!validateInput(new_admin->username, 50)) return;

    cout << "Enter admin password: ";
    cin >> new_admin->password;
    if (!validateInput(new_admin->password, 50)) return;

    // Add admin to the database
    add_admin_to_db(new_admin->username, new_admin->password);

    // Add admin to the linked list
    new_admin->next = nullptr;
    if (admin_head == nullptr) {
        admin_head = new_admin;
        admin_tall = new_admin;
    } else {
        admin_tall->next = new_admin;
        admin_tall = new_admin;
    }
    cout << "Admin added successfully!" << endl;
}

void update_admin() {
    char username[50];
    cout << "Enter admin username to update: ";
    cin >> username;
    if (!validateInput(username, 50)) return;

    Admin* current = admin_head;
    while (current != nullptr) {
        if (current->username == username) {
            cout << "Admin found. What would you like to update?" << endl;
            cout << "1. Username" << endl;
            cout << "2. Password" << endl;
            cout << "3. Both" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter new username: ";
                    cin >> current->username;
                    if (!validateInput(current->username, 50)) return;
                    break;
                case 2:
                    cout << "Enter new password: ";
                    cin >> current->password;
                    if (!validateInput(current->password, 50)) return;
                    break;
                case 3:
                    cout << "Enter new username: ";
                    cin >> current->username;
                    if (!validateInput(current->username, 50)) return;
                    cout << "Enter new password: ";
                    cin >> current->password;
                    if (!validateInput(current->password, 50)) return;
                    break;
                default:
                    cout << "Invalid choice. No updates made." << endl;
                    return;
            }

            // Update admin in the database
            update_admin_in_db(current->username, current->password);

            cout << "Admin updated successfully!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Admin not found." << endl;
}

void search_admin() {
    char username[50];
    cout << "Enter admin username to search: ";
    cin >> username;
    if (!validateInput(username, 50)) return;

    Admin* current = admin_head;
    while (current != nullptr) {
        if (current->username == username) {
            cout << "Admin found in linked list:" << endl;
            cout << "Username: " << current->username << endl;
            cout << "Password: " << string(strlen(current->password), '*') << endl;
            return;
        }
        current = current->next;
    }

    // Admin not found in linked list, search in the database
    search_admin_in_db(username);
}

void delete_admin() {
    char username[50];
    cout << "Enter admin username to delete: ";
    cin >> username;
    if (!validateInput(username, 50)) return;

    Admin* current = admin_head;
    Admin* prev = nullptr;

    while (current != nullptr) {
        if (current->username == username) {
            if (prev == nullptr) {
                admin_head = current->next;
            } else {
                prev->next = current->next;
            }

            if (current == admin_tall) {
                admin_tall = prev;
            }

            // Delete admin from the database
            delete_admin_from_db(username);

            delete current;
            cout << "Admin deleted successfully!" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Admin not found." << endl;
}

void display_admin() {
    if (admin_head == nullptr) {
        cout << "No admins found in the system." << endl;
        return;
    }

    Admin* current = admin_head;
    int count = 1;
    cout << "\nAdmin List:" << endl;
    cout << "------------------------" << endl;

    while (current != nullptr) {
        cout << count << ". Username: " << current->username << endl;
        cout << "   Password: " << string(strlen(current->password), '*') << endl;
        cout << "------------------------" << endl;
        current = current->next;
        count++;
    }
}
