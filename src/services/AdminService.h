#ifndef ADMIN_SERVICE_H
#define ADMIN_SERVICE_H

#include "../models/Admin.h"
#include "../utils/Validation.h"
#include <iostream>
#include <cstring>

class AdminService {
public:
    static void addAdmin() {
        Admin* newAdmin = new Admin();
        
        std::cout << "Enter admin username: ";
        std::cin >> newAdmin->username;
        
        std::cout << "Enter admin password: ";
        std::cin >> newAdmin->password;

        newAdmin->next = nullptr;

        if (!admin_head) {
            admin_head = admin_tall = newAdmin;
        } else {
            admin_tall->next = newAdmin;
            admin_tall = newAdmin;
        }

        std::cout << "Admin added successfully!\n";
    }

    static void displayAdmins() {
        if (!admin_head) {
            std::cout << "No admins registered.\n";
            return;
        }

        Admin* current = admin_head;
        int count = 1;
        while (current) {
            std::cout << "\nAdmin #" << count++ << ":"
                     << "\nUsername: " << current->username << "\n";
            current = current->next;
        }
    }

    static void updateAdmin() {
        if (!admin_head) {
            std::cout << "No admins to update.\n";
            return;
        }

        char username[50];
        std::cout << "Enter username to update: ";
        std::cin >> username;

        Admin* current = admin_head;
        while (current) {
            if (strcmp(current->username, username) == 0) {
                std::cout << "Enter new password: ";
                std::cin >> current->password;
                std::cout << "Admin updated successfully!\n";
                return;
            }
            current = current->next;
        }

        std::cout << "Admin not found!\n";
    }

    static void deleteAdmin() {
        if (!admin_head) {
            std::cout << "No admins to delete.\n";
            return;
        }

        char username[50];
        std::cout << "Enter username to delete: ";
        std::cin >> username;

        if (strcmp(admin_head->username, username) == 0) {
            Admin* temp = admin_head;
            admin_head = admin_head->next;
            if (admin_head == nullptr) admin_tall = nullptr;
            delete temp;
            std::cout << "Admin deleted successfully!\n";
            return;
        }

        Admin* current = admin_head;
        while (current->next) {
            if (strcmp(current->next->username, username) == 0) {
                Admin* temp = current->next;
                current->next = current->next->next;
                if (current->next == nullptr) admin_tall = current;
                delete temp;
                std::cout << "Admin deleted successfully!\n";
                return;
            }
            current = current->next;
        }

        std::cout << "Admin not found!\n";
    }
};

#endif 