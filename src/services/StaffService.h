#ifndef STAFF_SERVICE_H
#define STAFF_SERVICE_H

#include "../models/Staff.h"
#include "../utils/Validation.h"
#include <iostream>

class StaffService {
public:
    static void addStaff() {
        Staff* newStaff = new Staff();
        
        std::cout << "Enter staff name: ";
        std::cin >> newStaff->name;
        
        std::cout << "Enter staff ID: ";
        std::cin >> newStaff->id;
        
        do {
            std::cout << "Enter gender (M/F): ";
            std::cin >> newStaff->gender;
        } while (!Validation::validateGender(newStaff->gender));
        
        std::cout << "Enter department: ";
        std::cin >> newStaff->department;
        
        std::cout << "Enter position: ";
        std::cin >> newStaff->position;
        
        do {
            std::cout << "Enter phone number: ";
            std::cin >> newStaff->phone;
        } while (!Validation::validatePhoneNumber(newStaff->phone));
        
        std::cout << "Enter PC name: ";
        std::cin >> newStaff->pcname;
        
        std::cout << "Enter serial number: ";
        std::cin >> newStaff->serial;

        // Link list logic
        if (!staff_head) {
            staff_head = staff_tall = newStaff;
        } else {
            staff_tall->next = newStaff;
            newStaff->prev = staff_tall;
            staff_tall = newStaff;
        }
    }

    static void displayStaff() {
        if (!staff_head) {
            std::cout << "No staff registered.\n";
            return;
        }

        Staff* current = staff_head;
        while (current) {
            std::cout << "\nName: " << current->name
                     << "\nID: " << current->id
                     << "\nGender: " << current->gender
                     << "\nDepartment: " << current->department
                     << "\nPosition: " << current->position
                     << "\nPhone: " << current->phone
                     << "\nPC Name: " << current->pcname
                     << "\nSerial: " << current->serial << "\n";
            current = current->next;
        }
    }

    // Add other staff-related methods like update, delete, search, etc.
};

#endif 