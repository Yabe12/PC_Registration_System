#include <iostream>
#include <cstring>
#include "../models/admin/admin.cpp"
using namespace std;

int  main () {
    
void add_admin() {
    Admin *new_admin = new Admin;
    cout << "Enter admin username: ";
    cin >> new_admin->username;
    cout << "Enter admin password: ";
    cin >> new_admin->password;

    // Add to the end of the list
    new_admin->next = NULL;
    if (admin_head == NULL) {
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

    Admin *current = admin_head;
    while (current != NULL) {
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

    Admin *current = admin_head;
    while (current != NULL) {
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

    Admin *current = admin_head;
    Admin *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            if (prev == NULL) {
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
    if (admin_head == NULL) {
        cout << "No admins found in the system." << endl;
        return;
    }

    Admin *current = admin_head;
    int count = 1;
    cout << "\nAdmin List:" << endl;
    cout << "------------------------" << endl;
    
    while (current != NULL) {
        cout << count << ". Username: " << current->username << endl;
        cout << "   Password: " << string(strlen(current->password), '*') << endl;
        cout << "------------------------" << endl;
        current = current->next;
        count++;
    }
}

}
