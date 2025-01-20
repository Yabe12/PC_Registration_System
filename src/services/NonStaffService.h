#ifndef NONSTAFF_SERVICE_H
#define NONSTAFF_SERVICE_H

#include "../models/NonStaff.h"
#include "../utils/Validation.h"
#include "../utils/Logger.h"
#include <iostream>
#include <cstring>

using namespace std; // Move it here to affect the whole file

class NonStaffService {
public:
    static void addNonStaff() {
        NonStaff* newNonStaff = new NonStaff();
        
        cout << "Enter non-staff name: ";
        cin >> newNonStaff->name;
        
        cout << "Enter non-staff ID: ";
        cin >> newNonStaff->id;
        
        do {
            cout << "Enter gender (M/F): ";
            cin >> newNonStaff->gender;
        } while (!Validation::validateGender(newNonStaff->gender));
        
        cout << "Enter department: ";
        cin >> newNonStaff->department;
        
        cout << "Enter position: ";
        cin >> newNonStaff->position;
        
        do {
            cout << "Enter phone number: ";
            cin >> newNonStaff->phone;
        } while (!Validation::validatePhoneNumber(newNonStaff->phone));
        
        cout << "Enter PC name: ";
        cin >> newNonStaff->pcname;
        
        cout << "Enter serial number: ";
        cin >> newNonStaff->serial;

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
            cout << "No non-staff registered.\n";
            return;
        }

        NonStaff* current = nonstaff_head;
        while (current) {
            cout << "\nName: " << current->name
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

    static void updateNonStaff() {
        if (!nonstaff_head) {
            cout << "No non-staff records to update.\n";
            return;
        }

        char searchId[20];
        cout << "Enter ID of non-staff to update: ";
        cin >> searchId;

        NonStaff* target = findNonStaffById(searchId);
        if (!target) {
            cout << "Non-staff with ID " << searchId << " not found.\n";
            return;
        }

        int choice;
        do {
            cout << "\nUpdate Menu:"
                 << "\n1. Update Name"
                 << "\n2. Update Gender"
                 << "\n3. Update Department"
                 << "\n4. Update Position"
                 << "\n5. Update Phone"
                 << "\n6. Update PC Name"
                 << "\n7. Update Serial Number"
                 << "\n8. Back"
                 << "\nEnter choice: ";
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
                    cout << "Enter new department: ";
                    cin >> target->department;
                    break;
                case 4:
                    cout << "Enter new position: ";
                    cin >> target->position;
                    break;
                case 5:
                    do {
                        cout << "Enter new phone number: ";
                        cin >> target->phone;
                    } while (!Validation::validatePhoneNumber(target->phone));
                    break;
                case 6:
                    cout << "Enter new PC name: ";
                    cin >> target->pcname;
                    break;
                case 7:
                    cout << "Enter new serial number: ";
                    cin >> target->serial;
                    break;
                case 8:
                    cout << "Update completed.\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 8);

        Logger::log("Updated non-staff record with ID: " + string(searchId));
    }

    static void deleteNonStaff() {
        if (!nonstaff_head) {
            cout << "No non-staff records to delete.\n";
            return;
        }

        char searchId[20];
        cout << "Enter ID of non-staff to delete: ";
        cin >> searchId;

        // If deleting first node
        if (strcmp(nonstaff_head->id, searchId) == 0) {
            NonStaff* temp = nonstaff_head;
            nonstaff_head = nonstaff_head->next;
            if (nonstaff_head) {
                nonstaff_head->prev = nullptr;
            } else {
                nonstaff_tall = nullptr;
            }
            delete temp;
            cout << "Non-staff record deleted successfully.\n";
            Logger::log("Deleted non-staff record with ID: " + string(searchId));
            return;
        }

        // Search for node to delete
        NonStaff* current = nonstaff_head;
        while (current && strcmp(current->id, searchId) != 0) {
            current = current->next;
        }

        if (!current) {
            cout << "Non-staff with ID " << searchId << " not found.\n";
            return;
        }

        // Update links
        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        } else {
            nonstaff_tall = current->prev;
        }

        delete current;
        cout << "Non-staff record deleted successfully.\n";
        Logger::log("Deleted non-staff record with ID: " + string(searchId));
    }

    static void searchNonStaff() {
        if (!nonstaff_head) {
            cout << "No non-staff records to search.\n";
            return;
        }

        int searchChoice;
        cout << "\nSearch by:"
             << "\n1. ID"
             << "\n2. Name"
             << "\n3. Department"
             << "\n4. Position"
             << "\nEnter choice: ";
        cin >> searchChoice;

        char searchTerm[50];
        cout << "Enter search term: ";
        cin >> searchTerm;

        bool found = false;
        NonStaff* current = nonstaff_head;

        while (current) {
            bool match = false;
            switch (searchChoice) {
                case 1:
                    match = (strcmp(current->id, searchTerm) == 0);
                    break;
                case 2:
                    match = (strcmp(current->name, searchTerm) == 0);
                    break;
                case 3:
                    match = (strcmp(current->department, searchTerm) == 0);
                    break;
                case 4:
                    match = (strcmp(current->position, searchTerm) == 0);
                    break;
                default:
                    cout << "Invalid search option!\n";
                    return;
            }

            if (match) {
                found = true;
                displaySingleNonStaff(current);
            }
            current = current->next;
        }

        if (!found) {
            cout << "No matching records found.\n";
        }
    }

    static void sortNonStaff(int sortChoice) {
        if (!nonstaff_head || !nonstaff_head->next) {
            return;
        }

        bool swapped;
        NonStaff *ptr1;
        NonStaff *lptr = nullptr;

        do {
            swapped = false;
            ptr1 = nonstaff_head;

            while (ptr1->next != lptr) {
                bool shouldSwap = false;

                switch (sortChoice) {
                    case 1: // Sort by name
                        shouldSwap = (strcmp(ptr1->name, ptr1->next->name) > 0);
                        break;
                    case 2: // Sort by ID
                        shouldSwap = (strcmp(ptr1->id, ptr1->next->id) > 0);
                        break;
                    case 3: // Sort by department
                        shouldSwap = (strcmp(ptr1->department, ptr1->next->department) > 0);
                        break;
                }

                if (shouldSwap) {
                    swapNonStaff(ptr1, ptr1->next);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
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
             << "\nDepartment: " << nonstaff->department
             << "\nPosition: " << nonstaff->position
             << "\nPhone: " << nonstaff->phone
             << "\nPC Name: " << nonstaff->pcname
             << "\nSerial: " << nonstaff->serial << "\n";
    }

    static void swapNonStaff(NonStaff* a, NonStaff* b) {
        // Swap data instead of pointers for simplicity
        NonStaff temp;
        strcpy(temp.name, a->name);
        strcpy(temp.id, a->id);
        temp.gender = a->gender;
        strcpy(temp.department, a->department);
        strcpy(temp.position, a->position);
        temp.phone = a->phone;
        strcpy(temp.pcname, a->pcname);
        strcpy(temp.serial, a->serial);

        strcpy(a->name, b->name);
        strcpy(a->id, b->id);
        a->gender = b->gender;
        strcpy(a->department, b->department);
        strcpy(a->position, b->position);
        a->phone = b->phone;
        strcpy(a->pcname, b->pcname);
        strcpy(a->serial, b->serial);

        strcpy(b->name, temp.name);
        strcpy(b->id, temp.id);
        b->gender = temp.gender;
        strcpy(b->department, temp.department);
        strcpy(b->position, temp.position);
        b->phone = temp.phone;
        strcpy(b->pcname, temp.pcname);
        strcpy(b->serial, temp.serial);
    }
};

#endif
