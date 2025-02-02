#include "../../models/users/staff.h"
#include "../../middleware/input_validation.h"
#include "../../database/user/staff/StaffDBOperations.h"
#include <iostream>
using namespace std;

staff* staff_head = nullptr;
staff* staff_tall = nullptr;
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
    char staff_name[MAX_LENGTH];
    cout << "Enter the name of the staff to update: ";
    cin >> staff_name;
    if (!validateInput(staff_name, MAX_LENGTH)) return;

    staff* current = staff_head;
    while (current != nullptr) {
        if (strcmp(staff_name, current->name) == 0) {
            cout << "Staff found. What would you like to update?" << endl;
            cout << "1. Name" << endl;
            cout << "2. ID" << endl;
            cout << "3. Gender" << endl;
            cout << "4. Phone Number" << endl;
            cout << "5. Job Title" << endl;
            cout << "6. PC Type" << endl;
            cout << "7. Computer Name" << endl;
            cout << "8. Computer Serial Number" << endl;
            cout << "9. All of the above" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    cin >> current->name;
                    if (!validateInput(current->name, MAX_LENGTH)) return;
                    break;
                case 2:
                    cout << "Enter new ID: ";
                    cin >> current->id;
                    if (!validateInput(current->id, MAX_LENGTH)) return;
                    break;
                case 3:
                    cout << "Enter new gender (Male/Female): ";
                    cin >> current->gender;
                    if (!validateGender(current->gender)) return;
                    break;
                case 4:
                    cout << "Enter new phone number: ";
                    cin >> current->phone;
                    if (!validatePhoneNumber(current->phone)) return;
                    break;
                case 5:
                    cout << "Enter new job title: ";
                    cin >> current->job;
                    if (!validateInput(current->job, MAX_LENGTH)) return;
                    break;
                case 6:
                    cout << "Enter new PC type: ";
                    cin >> current->typeofpc;
                    if (!validateInput(current->typeofpc, MAX_LENGTH)) return;
                    break;
                case 7:
                    cout << "Enter new computer name: ";
                    cin >> current->pcname;
                    if (!validateInput(current->pcname, MAX_LENGTH)) return;
                    break;
                case 8:
                    cout << "Enter new computer serial number: ";
                    cin >> current->serial;
                    if (!validateInput(current->serial, MAX_LENGTH)) return;
                    break;
                case 9:
                    cout << "Enter new name: ";
                    cin >> current->name;
                    if (!validateInput(current->name, MAX_LENGTH)) return;
                    
                    cout << "Enter new ID: ";
                    cin >> current->id;
                    if (!validateInput(current->id, MAX_LENGTH)) return;
                    
                    cout << "Enter new gender (Male/Female): ";
                    cin >> current->gender;
                    if (!validateGender(current->gender)) return;
                    
                    cout << "Enter new phone number: ";
                    cin >> current->phone;
                    if (!validatePhoneNumber(current->phone)) return;
                    
                    cin.ignore();  // Clear the input buffer
                    
                    cout << "Enter new job title: ";
                    cin >> current->job;
                    if (!validateInput(current->job, MAX_LENGTH)) return;
                    
                    cout << "Enter new PC type: ";
                    cin >> current->typeofpc;
                    if (!validateInput(current->typeofpc, MAX_LENGTH)) return;
                    
                    cout << "Enter new computer name: ";
                    cin >> current->pcname;
                    if (!validateInput(current->pcname, MAX_LENGTH)) return;
                    
                    cout << "Enter new computer serial number: ";
                    cin >> current->serial;
                    if (!validateInput(current->serial, MAX_LENGTH)) return;
                    break;
                default:
                    cout << " Invalid choice. No updates made." << endl;
                    return;
            }
            
            cout << "Staff information updated successfully." << endl;
            cout << "Would you like to update the database? (yes/no): ";
            string confirmation;
            cin >> confirmation;
            if (confirmation == "yes" || confirmation == "y") {
                update_staff_in_db(current->name, current->id, 
                                current->gender, 
                                current->job, 
                                current->phone, 
                                current->typeofpc, 
                                current->pcname, 
                                current->serial);
                cout << "Staff information updated in the database." << endl;
            } else {
                cout << "Staff update discarded. Not updated in database." << endl;
            }
            return;
        }
        current = current->next;
    }
    cout << "Staff not found in temporary storage." << endl;
    cout << "Would you like to search for the staff in the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        search_staff_in_name(staff_name);
    } else {
        cout << "Staff search discarded. Not searched in database." << endl;
    }
}


void delete_staff() {
    char staff_name[MAX_LENGTH];
    cout << "Enter the name of the staff to delete: ";
    cin >> staff_name;
    
    staff* current = staff_head;
    staff* prev = nullptr;
    
    while (current != nullptr) {
        if (strcmp(staff_name, current->name) == 0) {
          
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                staff_head = current->next;
            }
            if (current == staff_tall) {
                staff_tall = prev;
            }
            delete current;
            cout << "Staff deleted successfully from temporary." << endl;

            
            cout << "Would you like to delete this staff member from the database as well? (yes/no): ";
            string confirmation;
            cin >> confirmation;
            if (confirmation == "yes" || confirmation == "y") {
                delete_staff_from_db(staff_name);
                cout << "Staff deleted successfully from the database." << endl;
            } else {
                cout << "Staff deletion from the database discarded." << endl;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Staff not found in temporary storage." << endl;
}

void display_staff() {
    cout << "\n=============================================" << endl;
    cout << "             Staff List" << endl;
    cout << "=============================================" << endl;

    staff* current = staff_head;
    if (current == nullptr) {
        cout << "No staff found in the temporary list." << endl;
           cout << "Would you like to display all staff from the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        display_all_staff_from_db();
    } else {
        cout << "Staff display discarded. Not displayed from database." << endl;
    }
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
