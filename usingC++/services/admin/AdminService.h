#ifndef ADMIN_SERVICE_H
#define ADMIN_SERVICE_H

#include <iostream>
#include <cstring>
#include "../models/admin/admin.cpp"
#include "../controller/authentication_controller.cpp"
using namespace std;

class AdminService {
public:
    static void createAdmin() {
        if (!AuthService::isUserSuperAdmin()) {
            cout << "Access Denied! Only the superadmin can perform this action.\n";
            return;
        }

        Admin* newAdmin = new Admin();
        cout << "Enter username for new admin: ";
        cin >> newAdmin->username;
        cout << "Enter password for new admin: ";
        cin >> newAdmin->password;

        newAdmin->next = nullptr;

        if (admin_head == nullptr) {
            admin_head = newAdmin;
            admin_tall = newAdmin;
        } else {
            admin_tall->next = newAdmin;
            admin_tall = newAdmin;
        }

        cout << "Admin account created successfully.\n";
    }

    static void updateAdmin() {
        if (!AuthService::isUserSuperAdmin()) {
            cout << "Access Denied! Only the superadmin can perform this action.\n";
            return;
        }

        char username[50];
        cout << "Enter the username of the admin to update: ";
        cin >> username;

        Admin* temp = admin_head;
        while (temp) {
            if (strcmp(temp->username, username) == 0) {
                cout << "Admin found. Enter new password: ";
                cin >> temp->password;
                cout << "Password updated successfully.\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Admin with username " << username << " not found.\n";
    }

    static void deleteAdmin() {
        if (!AuthService::isUserSuperAdmin()) {
            cout << "Access Denied! Only the superadmin can perform this action.\n";
            return;
        }

        char username[50];
        cout << "Enter the username of the admin to delete: ";
        cin >> username;

        Admin *temp = admin_head, *prev = nullptr;
        while (temp) {
            if (strcmp(temp->username, username) == 0) {
                if (prev == nullptr) { // Deleting the head
                    admin_head = temp->next;
                } else {
                    prev->next = temp->next;
                }

                if (temp == admin_tall) { // Deleting the last node
                    admin_tall = prev;
                }

                delete temp;
                cout << "Admin deleted successfully.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Admin with username " << username << " not found.\n";
    }

    static void searchAdmin() {
        if (!AuthService::isUserSuperAdmin()) {
            cout << "Access Denied! Only the superadmin can perform this action.\n";
            return;
        }

        char username[50];
        cout << "Enter the username of the admin to search: ";
        cin >> username;

        Admin* temp = admin_head;
        while (temp) {
            if (strcmp(temp->username, username) == 0) {
                cout << "Admin found: \n";
                cout << "Username: " << temp->username << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Admin with username " << username << " not found.\n";
    }

    static void displayAdmins() {
        if (!AuthService::isUserSuperAdmin()) {
            cout << "Access Denied! Only the superadmin can perform this action.\n";
            return;
        }

        if (admin_head == nullptr) {
            cout << "No admins available.\n";
            return;
        }

        Admin* temp = admin_head;
        cout << "List of Admins:\n";
        while (temp) {
            cout << "Username: " << temp->username << endl;
            temp = temp->next;
        }
    }
};

#endif // ADMIN_SERVICE_H
