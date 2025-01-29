#include <iostream>
#include <cstring>
#include "Staff_Service.h"
#include "../../middleware/input_validation.h"
#include "../../models/users/Staff.h" // Include the header file where Staff is defined
#include "../../database/user/staff/StaffDBOperations.h"

using namespace std;

// Global pointers for the linked list
staff* staff_head = nullptr;
staff* staff_tail = nullptr;

void add_staff() {
    staff* new_staff = new staff;

    cout << "Enter staff name: ";
    cin.ignore(); 
    cin.getline(new_staff->name, 50);
    if (!validateInput(new_staff->name, 50)) return;

    cout << "Enter staff ID: ";
    cin.getline(new_staff->id, 20);
    if (!validateInput(new_staff->id, 20)) return;

    cout << "Enter gender (Male/Female): ";
    cin.getline(new_staff->gender, 10);
    if (strcmp(new_staff->gender, "Male") != 0 && strcmp(new_staff->gender, "Female") != 0) {
        cout << "Invalid gender. Please enter 'Male' or 'Female'." << endl;
        return;
    }

    cout << "Enter job position: ";
    cin.getline(new_staff->job, 50);
    if (!validateInput(new_staff->job, 50)) return;

    cout << "Enter phone number: ";
    cin >> new_staff->phone;
    cin.ignore();

    cout << "Enter PC type: ";
    cin.getline(new_staff->typeofpc, 20);
    if (!validateInput(new_staff->typeofpc, 20)) return;

    cout << "Enter PC name: ";
    cin.getline(new_staff->pcname, 50);
    if (!validateInput(new_staff->pcname, 50)) return;

    cout << "Enter serial number: ";
    cin.getline(new_staff->serial, 50);
    if (!validateInput(new_staff->serial, 50)) return;

    // Add to database
    add_staff_to_db(new_staff->name, new_staff->id, new_staff->gender, new_staff->job, 
                    to_string(new_staff->phone), new_staff->typeofpc, new_staff->pcname, new_staff->serial);

    // Add to linked list
    new_staff->next = nullptr;
    if (staff_head == nullptr) {
        staff_head = new_staff;
        staff_tail = new_staff;
    } else {
        staff_tail->next = new_staff;
        staff_tail = new_staff;
    }
    cout << "✅ Staff added successfully!" << endl;
}

void update_staff() {
    char id[20];
    cout << "Enter staff ID to update: ";
    cin.getline(id, 20);
    if (!validateInput(id, 20)) return;

    staff* current = staff_head;
    while (current != nullptr) {
        if (strcmp(current->id, id) == 0) {
            cout << "Staff found. What would you like to update?" << endl;
            cout << "1. Name\n2. Gender\n3. Job\n4. Phone\n5. PC Type\n6. PC Name\n7. Serial\n8. All" << endl;

            int choice;
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    cin.getline(current->name, 50);
                    if (!validateInput(current->name, 50)) return;
                    break;
                case 2:
                    cout << "Enter new gender (Male/Female): ";
                    cin.getline(current->gender, 10);
                    if (strcmp(current->gender, "Male") != 0 && strcmp(current->gender, "Female") != 0) {
                        cout << "Invalid gender." << endl;
                        return;
                    }
                    break;
                case 3:
                    cout << "Enter new job: ";
                    cin.getline(current->job, 50);
                    if (!validateInput(current->job, 50)) return;
                    break;
                case 4:
                    cout << "Enter new phone number: ";
                    cin >> current->phone;
                    cin.ignore();
                    break;
                case 5:
                    cout << "Enter new PC type: ";
                    cin.getline(current->typeofpc, 20);
                    if (!validateInput(current->typeofpc, 20)) return;
                    break;
                case 6:
                    cout << "Enter new PC name: ";
                    cin.getline(current->pcname, 50);
                    if (!validateInput(current->pcname, 50)) return;
                    break;
                case 7:
                    cout << "Enter new serial: ";
                    cin.getline(current->serial, 50);
                    if (!validateInput(current->serial, 50)) return;
                    break;
                case 8:
                    update_staff();
                    return;
                default:
                    cout << "❌ Invalid choice." << endl;
                    return;
            }

            // Update in database
            update_staff_in_db(current->id, current->name, current->gender, current->job, 
                               to_string(current->phone), current->typeofpc, current->pcname, current->serial);
            cout << "✅ Staff updated successfully!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "❌ Staff not found." << endl;
}

void search_staff() {
    char id[20];
    cout << "Enter staff ID to search: ";
    cin.getline(id, 20);
    if (!validateInput(id, 20)) return;

    staff* current = staff_head;
    while (current != nullptr) {
        if (strcmp(current->id, id) == 0) {
            cout << "✅ Staff found in linked list:\nName: " << current->name << "\nID: " << current->id << endl;
            return;
        }
        current = current->next;
    }

    // Search in database
    search_staff_in_db(id);
}

void delete_staff() {
    char id[20];
    cout << "Enter staff ID to delete: ";
    cin.getline(id, 20);
    if (!validateInput(id, 20)) return;

    staff* current = staff_head;
    staff* prev = nullptr;

    while (current != nullptr) {
        if (strcmp(current->id, id) == 0) {
            if (prev == nullptr) {
                staff_head = current->next;
                if (staff_tail == current) {
                    staff_tail = nullptr;
                }
            } else {
                prev->next = current->next;
                if (staff_tail == current) {
                    staff_tail = prev;
                }
            }

            // Delete from database
            delete_staff_from_db(id);

            delete current;
            cout << "✅ Staff deleted successfully!" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "❌ Staff not found." << endl;
}

void display_staff() {
    cout << "\n=============================================" << endl;
    cout << "             Staff List" << endl;
    cout << "=============================================" << endl;

    // Call display function from StaffDBOperations to show all staff
    display_all_staff_from_db();  // No arguments needed
}
