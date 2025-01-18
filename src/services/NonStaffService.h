#ifndef NONSTAFF_SERVICE_H
#define NONSTAFF_SERVICE_H

#include "../models/NonStaff.h"
#include "../utils/Validation.h"
#include <iostream>

class NonStaffService {
public:
    static void addNonStaff() {
        NonStaff* newNonStaff = new NonStaff();
        
        std::cout << "Enter non-staff name: ";
        std::cin >> newNonStaff->name;
        
        std::cout << "Enter non-staff ID: ";
        std::cin >> newNonStaff->id;
        
        do {
            std::cout << "Enter gender (M/F): ";
            std::cin >> newNonStaff->gender;
        } while (!Validation::validateGender(newNonStaff->gender));
        
        std::cout << "Enter department: ";
        std::cin >> newNonStaff->department;
        
        std::cout << "Enter position: ";
        std::cin >> newNonStaff->position;
        
        do {
            std::cout << "Enter phone number: ";
            std::cin >> newNonStaff->phone;
        } while (!Validation::validatePhoneNumber(newNonStaff->phone));
        
        std::cout << "Enter PC name: ";
        std::cin >> newNonStaff->pcname;
        
        std::cout << "Enter serial number: ";
        std::cin >> newNonStaff->serial;

        // Link list logic
        if (!nonstaff_head) {
            nonstaff_head = nonstaff_tall = newNonStaff;
        } else {
            nonstaff_tall->next = newNonStaff;
            newNonStaff->prev = nonstaff_tall;
            nonstaff_tall = newNonStaff;
        }
    }

    static void displayNonStaff() {
        if (!nonstaff_head) {
            std::cout << "No non-staff registered.\n";
            return;
        }

        NonStaff* current = nonstaff_head;
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

    // Add other non-staff-related methods like update, delete, search, etc.
};

#endif 