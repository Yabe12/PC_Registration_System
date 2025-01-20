#ifndef NONSTAFF_SERVICE_H
#define NONSTAFF_SERVICE_H

#include "../models/NonStaff.h"
#include "../utils/Validation.h"
#include "../utils/Logger.h"
#include <iostream>
#include <cstring>

using namespace std;

class NonStaffService {
public:
    static void registerNonStaff() {
        NonStaff* newNonStaff = new NonStaff();

        cout << "Enter non-staff name: ";
        cin >> newNonStaff->name;

        cout << "Enter non-staff ID: ";
        cin >> newNonStaff->id;

        do {
            cout << "Enter gender (M/F): ";
            cin >> newNonStaff->gender;
        } while (!Validation::validateGender(newNonStaff->gender));

        do {
            cout << "Enter phone number: ";
            cin >> newNonStaff->phone;
        } while (!Validation::validatePhoneNumber(newNonStaff->phone));

        cout << "Enter PC name: ";
        cin >> newNonStaff->pcname;

        cout << "Enter serial number: ";
        cin >> newNonStaff->serial;

        // Add to linked list
        if (!nonstaff_head) {
            nonstaff_head = nonstaff_tall = newNonStaff;
        } else {
            nonstaff_tall->next = newNonStaff;
            newNonStaff->prev = nonstaff_tall;
            nonstaff_tall = newNonStaff;
        }

        cout << "Non-staff member registered successfully.\n";
        Logger::log("Registered non-staff with ID: " + string(newNonStaff->id));
    }

    static void displayNonStaff() {
        if (!nonstaff_head) {
            cout << "No non-staff records available.\n";
            return;
        }

        NonStaff* current = nonstaff_head;
        while (current) {
            displaySingleNonStaff(current);
            current = current->next;
        }
    }

    static void updateNonStaff() {
        if (!nonstaff_head) {
            cout << "No non-staff records available to update.\n";
            return;
        }

        char searchId[20];
        cout << "Enter the ID of the non-staff member to update: ";
        cin >> searchId;

        NonStaff* target = findNonStaffById(searchId);
        if (!target) {
            cout << "Non-staff member with ID " << searchId << " not found.\n";
            return;
        }

        int choice;
        do {
            cout << "\nUpdate Menu:"
                 << "\n1. Update Name"
                 << "\n2. Update Gender"
                 << "\n3. Update Phone"
                 << "\n4. Update PC Name"
                 << "\n5. Update Serial"
                 << "\n6. Exit"
                 << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    cin >> target->name;
                    break;
                case 2:
                    do {
                        cout << "Enter new gender (M/F): ";
                        cin >> target->gender;
                    } while (!Validation::validateGender(target->gender));
                    break;
                case 3:
                    do {
                        cout << "Enter new phone number: ";
                        cin >> target->phone;
                    } while (!Validation::validatePhoneNumber(target->phone));
                    break;
                case 4:
                    cout << "Enter new PC name: ";
                    cin >> target->pcname;
                    break;
                case 5:
                    cout << "Enter new serial number: ";
                    cin >> target->serial;
                    break;
                case 6:
                    cout << "Update process completed.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 6);

        Logger::log("Updated non-staff record with ID: " + string(searchId));
    }

    static void searchNonStaff() {
        if (!nonstaff_head) {
            cout << "No non-staff records available to search.\n";
            return;
        }

        char searchId[20];
        cout << "Enter the ID of the non-staff member to search: ";
        cin >> searchId;

        NonStaff* target = findNonStaffById(searchId);
        if (target) {
            displaySingleNonStaff(target);
        } else {
            cout << "Non-staff member with ID " << searchId << " not found.\n";
        }
    }

    static void deleteNonStaff() {
        if (!nonstaff_head) {
            cout << "No non-staff records available to delete.\n";
            return;
        }

        char searchId[20];
        cout << "Enter the ID of the non-staff member to delete: ";
        cin >> searchId;

        NonStaff* target = findNonStaffById(searchId);
        if (!target) {
            cout << "Non-staff member with ID " << searchId << " not found.\n";
            return;
        }

        // Update linked list pointers
        if (target->prev) {
            target->prev->next = target->next;
        } else {
            nonstaff_head = target->next;
        }

        if (target->next) {
            target->next->prev = target->prev;
        } else {
            nonstaff_tall = target->prev;
        }

        delete target;
        cout << "Non-staff member deleted successfully.\n";
        Logger::log("Deleted non-staff record with ID: " + string(searchId));
    }

private:
    static NonStaff* findNonStaffById(const char* id) {
        NonStaff* current = nonstaff_head;
        while (current) {
            if (strcmp(current->id, id) == 0) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    static void displaySingleNonStaff(NonStaff* nonstaff) {
        cout << "\nName: " << nonstaff->name
             << "\nID: " << nonstaff->id
             << "\nGender: " << nonstaff->gender
             << "\nPhone: " << nonstaff->phone
             << "\nPC Name: " << nonstaff->pcname
             << "\nSerial: " << nonstaff->serial << "\n";
    }
};

#endif
