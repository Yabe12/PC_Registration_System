#ifndef ADMIN_SERVICE_H
#define ADMIN_SERVICE_H

#include <cstring>
#include <iostream>
#include "../models/Admin.h"
#include "../utils/Validation.h"

using std::cin;
using std::cout;
using std::endl;

class AdminService {
public:
    static void addAdmin() {
        Admin* newAdmin = new Admin();
        
        cout << "Enter admin username: ";
        cin >> newAdmin->username;
        
        cout << "Enter admin password: ";
        cin >> newAdmin->password;

        newAdmin->next = nullptr;

        if (!admin_head) {
            admin_head = admin_tall = newAdmin;
        } else {
            admin_tall->next = newAdmin;
            admin_tall = newAdmin;
        }

        cout << "Admin added successfully!\n";
    }

    static void displayAdmins() {
        if (!admin_head) {
            cout << "No admins registered.\n";
            return;
        }

        Admin* current = admin_head;
        int count = 1;
        while (current) {
            cout << "\nAdmin #" << count++ << ":"
                 << "\nUsername: " << current->username << "\n";
            current = current->next;
        }
    }

    static void updateAdmin() {
        if (!admin_head) {
            cout << "No admins to update.\n";
            return;
        }

        char username[50];
        cout << "Enter username to update: ";
        cin >> username;

        Admin* current = admin_head;
        while (current) {
            if (strcmp(current->username, username) == 0) {
                cout << "Enter new password: ";
                cin >> current->password;
                cout << "Admin updated successfully!\n";
                return;
            }
            current = current->next;
        }

        cout << "Admin not found!\n";
    }

    static void deleteAdmin() {
        if (!admin_head) {
            cout << "No admins to delete.\n";
            return;
        }

        char username[50];
        cout << "Enter username to delete: ";
        cin >> username;

        if (strcmp(admin_head->username, username) == 0) {
            Admin* temp = admin_head;
            admin_head = admin_head->next;
            if (admin_head == nullptr) admin_tall = nullptr;
            delete temp;
            cout << "Admin deleted successfully!\n";
            return;
        }

        Admin* current = admin_head;
        while (current->next) {
            if (strcmp(current->next->username, username) == 0) {
                Admin* temp = current->next;
                current->next = current->next->next;
                if (current->next == nullptr) admin_tall = current;
                delete temp;
                cout << "Admin deleted successfully!\n";
                return;
            }
            current = current->next;
        }

        cout << "Admin not found!\n";
    }
};

#endif // ADMIN_SERVICE_H