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
    getline(cin, new_staff->name);
    if (!validateInput(new_staff->name, 50)) return;

    cout << "Enter staff ID: ";
    getline(cin, new_staff->id);
    if (!validateInput(new_staff->id, 20)) return;

    cout << "Enter gender (Male/Female): ";
    getline(cin, new_staff->gender);
    if (new_staff->gender != "Male" && new_staff->gender != "Female") {
        cout << "Invalid gender. Please enter 'Male' or 'Female'." << endl;
        return;
    }

    cout << "Enter job position: ";
    getline(cin, new_staff->job);
    if (!validateInput(new_staff->job, 50)) return;

    cout << "Enter phone number: ";
    cin >> new_staff->phone;
    cin.ignore();

    cout << "Enter PC type: ";
    getline(cin, new_staff->typeofpc);
    if (!validateInput(new_staff->typeofpc, 20)) return;

    cout << "Enter PC name: ";
    getline(cin, new_staff->pcname);
    if (!validateInput(new_staff->pcname, 50)) return;

    cout << "Enter serial number: ";
    getline(cin, new_staff->serial);
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
    string id;
    cout << "Enter staff ID to update: ";
    cin >> id;
    if (!validateInput(id.c_str(), 20)) return;

    staff* current = staff_head;
    while (current != nullptr) {
        if (current->id == id) {
            cout << "Staff found. What would you like to update?" << endl;
            cout << "1. Name\n2. Gender\n3. Job\n4. Phone\n5. PC Type\n6. PC Name\n7. Serial\n8. All" << endl;

            int choice;
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    getline(cin, current->name);
                    if (!validateInput(current->name, 50)) return;
                    break;
                case 2:
                    cout << "Enter new gender (Male/Female): ";
                    getline(cin, current->gender);
                    if (current->gender != "Male" && current->gender != "Female") {
                        cout << "Invalid gender." << endl;
                        return;
                    }
                    break;
                case 3:
                    cout << "Enter new job: ";
                    getline(cin, current->job);
                    if (!validateInput(current->job, 50)) return;
                    break;
                case 4:
                    cout << "Enter new phone number: ";
                    cin >> current->phone;
                    cin.ignore();
                    break;
                case 5:
                    cout << "Enter new PC type: ";
                    getline(cin, current->typeofpc);
                    if (!validateInput(current->typeofpc, 20)) return;
                    break;
                case 6:
                    cout << "Enter new PC name: ";
                    getline(cin, current->pcname);
                    if (!validateInput(current->pcname, 50)) return;
                    break;
                case 7:
                    cout << "Enter new serial: ";
                    getline(cin, current->serial);
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
                               current->phone, current->typeofpc, current->pcname, current->serial);
            cout << "✅ Staff updated successfully!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "❌ Staff not found." << endl;
}

void search_staff() {
    string id;
    cout << "Enter staff ID to search: ";
    cin >> id;
    if (!validateInput(id, 20)) return;

    staff* current = staff_head;
    while (current != nullptr) {
        if (current->id == id) {
            cout << "✅ Staff found in linked list:\nName: " << current->name << "\nID: " << current->id << endl;
            return;
        }
        current = current->next;
    }

    // Search in database
    search_staff_in_db(id);
}

void delete_staff() {
    string id;
    cout << "Enter staff ID to delete: ";
    cin >> id;
    if (!validateInput(id, 20)) return;

    staff* current = staff_head;
    staff* prev = nullptr;

    while (current != nullptr) {
        if (current->id == id) {
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
    display_all_staff_from_db();
}
