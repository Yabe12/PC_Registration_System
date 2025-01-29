#include "non_staff_service.h"
#include "../../middleware/input_validation.h"
#include "../../database/user/non_staff/NonstaffDBOperations.h"
#include <iostream>
using namespace std;

void add_nonstaff() {
    string name, id, gender, pcname, serial, superadmin_username;
    long long phone;
    int admin_id;

    cout << "Enter nonstaff name: ";
    cin >> name;
    // Validate name length
    if (!validateInput(name.c_str(), 50)) {
        return;
    }

    cout << "Enter nonstaff ID: ";
    cin >> id;
    // Validate ID length
    if (!validateInput(id.c_str(), 20)) {
        return;
    }

    cout << "Enter gender (Male/Female): ";
    cin >> gender;
    // Validate gender
    if (!validateGender(gender.c_str())) {
        return;
    }

    cout << "Enter phone number: ";
    cin >> phone;
    // Validate phone number length
    if (!validatePhoneNumber(phone)) {
        return;
    }

    cout << "Enter PC name: ";
    cin >> pcname;
    // Validate PC name length
    if (!validateInput(pcname.c_str(), 50)) {
        return;
    }

    cout << "Enter PC serial number: ";
    cin >> serial;
    // Validate serial number length
    if (!validateInput(serial.c_str(), 50)) {
        return;
    }

    cout << "Enter superadmin username: ";
    cin >> superadmin_username;
    // Validate superadmin username length
    if (!validateInput(superadmin_username.c_str(), 50)) {
        return;
    }

    cout << "Enter admin ID: ";
    cin >> admin_id;

    add_nonstaff_to_db(name, id, gender, to_string(phone), pcname, serial);
    cout << "Nonstaff added successfully." << endl;
}

void search_nonstaff() {
    string id;
    cout << "Enter nonstaff ID to search: ";
    cin >> id;

    // Validate ID length
    if (!validateInput(id.c_str(), 20)) {
        return;
    }

    search_nonstaff_in_db(id);
}

void update_nonstaff() {
    string id, name, gender, pcname, serial;
    long long phone;

    cout << "Enter nonstaff ID to update: ";
    cin >> id;
    // Validate ID length
    if (!validateInput(id.c_str(), 20)) {
        return;
    }

    cout << "Enter new name: ";
    cin >> name;
    // Validate name length
    if (!validateInput(name.c_str(), 50)) {
        return;
    }

    cout << "Enter new gender (Male/Female): ";
    cin >> gender;
    // Validate gender
    if (!validateGender(gender.c_str())) {
        return;
    }

    cout << "Enter new phone number: ";
    cin >> phone;
    // Validate phone number length
    if (!validatePhoneNumber(phone)) {
        return;
    }

    cout << "Enter new PC name: ";
    cin >> pcname;
    // Validate PC name length
    if (!validateInput(pcname.c_str(), 50)) {
        return;
    }

    cout << "Enter new PC serial number: ";
    cin >> serial;
    // Validate serial number length
    if (!validateInput(serial.c_str(), 50)) {
        return;
    }

    update_nonstaff_in_db(id, name, gender, to_string(phone), pcname, serial);
    cout << "Nonstaff updated successfully." << endl;
}

void delete_nonstaff() {
    string id;
    cout << "Enter nonstaff ID to delete: ";
    cin >> id;

    // Validate ID length
    if (!validateInput(id.c_str(), 20)) {
        return;
    }

    delete_nonstaff_from_db(id);
    cout << "Nonstaff deleted successfully." << endl;
}

void display_nonstaff() {
    display_all_nonstaff_from_db();
}
