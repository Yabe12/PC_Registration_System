#include "../../models/users/staff.h"
#include "../../middleware/input_validation.h"
#include "../../database/user/staff/StaffDBOperations.h"
#include <iostream>
using namespace std;
const int MAX_LENGTH = 50;
void add_staff() {
    staff* new_staff = new staff;
    cout << "Enter new staff name: ";
    cin >> new_staff->name;
    if (!validateInput(new_staff->name, MAX_LENGTH)) return;
    cout << "Enter new staff ID: ";
    cin >> new_staff->id;
    if (!validateInput(new_staff->id, MAX_LENGTH)) return;
    cout << "Enter new staff gender (Male/Female): ";
    cin >> new_staff->gender;
    if (!validateGender(new_staff->gender)) return;
    cout << "Enter new staff phone number: ";
    cin >> new_staff->phone;
    if (!validatePhoneNumber(new_staff->phone)) return;
    cin.ignore();
    cout << "Enter new staff job title: ";
    cin >> new_staff->job;
    if (!validateInput(new_staff->job, MAX_LENGTH)) return;
    cout << "Enter new staff PC type: ";
    cin >> new_staff->typeofpc;
    if (!validateInput(new_staff->typeofpc, MAX_LENGTH)) return;
    cout << "Enter new staff computer name: ";
    cin >> new_staff->pcname;
    if (!validateInput(new_staff->pcname, MAX_LENGTH)) return;
    cout << "Enter new staff computer serial number: ";
    cin >> new_staff->serial;
    if (!validateInput(new_staff->serial, MAX_LENGTH)) return;

    new_staff->next = nullptr;
    new_staff->prev = staff_tall;
    if (staff_tall != nullptr) {
        staff_tall->next = new_staff;
    }
    staff_tall = new_staff;
    if (staff_head == nullptr) {
        staff_head = staff_tall;
    }
    cout << "New staff is only added to temporary storage." << endl;
    cout << "Would you like to add to the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        add_staff_to_db(new_staff->name, new_staff->id, 
            new_staff->gender, 
            new_staff->job,
            new_staff->phone,
            new_staff->typeofpc, 
            new_staff->pcname,
            new_staff->serial);
    } else {
        cout << "Staff not saved to database." << endl;
    }
}

void search_staff() {
    char staff_name[MAX_LENGTH];
    cout << "Enter the name of the staff to search: ";
    cin >> staff_name;
    if (!validateInput(staff_name, MAX_LENGTH)) return;

    staff* current = staff_head;
    while (current != nullptr) {
        if (strcmp(current->name, staff_name) == 0) {
            cout << "\n================================================================" << endl;
            cout << "          Staff Details" << endl;
            cout << "=============================================" << endl;
            cout << "Name: " << current->name << endl;
            cout << "ID: " << current->id << endl;
            cout << "Gender: " << current->gender << endl;
            cout << "Job Title: " << current->job << endl;
            cout << "PC Type: " << current->typeofpc << endl;
            cout << "Computer Name: " << current->pcname << endl;
            cout << "Computer Serial Number: " << current->serial << endl;
            return;
        }
        current = current->next;
    }
    cout << "Staff not found in temporary." << endl;
    cout << "Would you like to search from the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        search_staff_in_name(staff_name);
    } else {
        cout << "Staff search discarded. Not searched in database." << endl;
    }
}

void update_staff() {
    
}

void delete_staff() {

}
void display_staff() {
    cout << "\n=============================================" << endl;
    cout << "             Staff List" << endl;
    cout << "=============================================" << endl;

    staff* current = staff_head;
    if (current == nullptr) {
        cout << "No staff found in the temporary list." << endl;
        return; 
    }

    cout << "Staff in temporary storage:" << endl;
    while (current != nullptr) {
        cout << "Name: " << current->name << endl;
        cout << "ID: " << current->id << endl;
        cout << "Job: " << current->job << endl;
        cout << "PC Type: " << current->typeofpc << endl;
        cout << "Computer Name: " << current->pcname << endl;
        cout << "Computer Serial Number: " << current->serial << endl;
        cout << "------------------------" << endl;
        current = current->next;
    }

    cout << "Would you like to display all staff from the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        display_all_staff_from_db();
    } else {
        cout << "Staff display discarded. Not displayed from database." << endl;
    }
}
