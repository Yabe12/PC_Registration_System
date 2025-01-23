#include <iostream>
#include <cstring>
#include "../models/admin/admin.h"
#include "../auth_service.h"
using namespace std;

void add_admin();
void update_admin();
void search_admin();
void delete_admin();
void display_admin();

Admin* admin_head = nullptr;
Admin* admin_tall = nullptr;

int main() {
    int choice;
    do {
        cout << "\nAdmin Management System\n";
        cout << "1. Add Admin\n";
        cout << "2. Update Admin\n";
        cout << "3. Search Admin\n";
        cout << "4. Delete Admin\n";
        cout << "5. Display Admins\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_admin();
                break;
            case 2:
                update_admin();
                break;
            case 3:
                search_admin();
                break;
            case 4:
                delete_admin();
                break;
            case 5:
                display_admin();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void add_admin() {
    Admin* new_admin = new Admin;
    cout << "Enter admin username: ";
    cin >> new_admin->username;
    cout << "Enter admin password: ";
    cin >> new_admin->password;

 
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

    Admin* current = admin_head;
    while (current != nullptr) {
        if (strcmp(current->username, username) == 0) {
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
                    break;
                case 2:
                    cout << "Enter new password: ";
                    cin >> current->password;
                    break;
                case 3:
                    cout << "Enter new username: ";
                    cin >> current->username;
                    cout << "Enter new password: ";
                    cin >> current->password;
                    break;
                default:
                    cout << "Invalid choice. No updates made." << endl;
                    return;
            }
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

    Admin* current = admin_head;
    while (current != nullptr) {
        if (strcmp(current->username, username) == 0) {
            cout << "Admin found:" << endl;
            cout << "Username: " << current->username << endl;
            cout << "Password: " << string(strlen(current->password), '*') << endl;
            return;
        }
        current = current->next;
    }
    cout << "Admin not found." << endl;
}

void delete_admin() {
    char username[50];
    cout << "Enter admin username to delete: ";
    cin >> username;

    Admin* current = admin_head;
    Admin* prev = nullptr;

    while (current != nullptr) {
        if (strcmp(current->username, username) == 0) {
            if (prev == nullptr) {
                admin_head = current->next;
            } else {
                prev->next = current->next;
            }

            if (current == admin_tall) {
                admin_tall = prev;
            }

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