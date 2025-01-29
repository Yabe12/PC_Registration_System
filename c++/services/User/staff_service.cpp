#include "staff_service.h"
#include "../../middleware/input_validation.h"
#include "../../database/user/staff/StaffDBOperations.h"
#include <iostream>
using namespace std;

void add_staff() {
    string name, id, gender, job, typeofpc, pcname, serial;
    long long phone;

    cout << "Enter staff name: ";
    cin >> name;
    // Validate name length
    if (!validateInput(name.c_str(), 50)) {
        return;
    }

    cout << "Enter staff ID: ";
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

    cout << "Enter job position: ";
    cin >> job;
    // Validate job length
    if (!validateInput(job.c_str(), 50)) {
        return;
    }

    cout << "Enter PC type: ";
    cin >> typeofpc;
    // Validate PC type length
    if (!validateInput(typeofpc.c_str(), 20)) {
        return;
    }

    cout << "Enter PC name: ";
    cin >> pcname;
    // Validate PC name length
    if (!validateInput(pcname.c_str(), 50)) {
        return;
    }

    cout << "Enter serial number: ";
    cin >> serial;
    // Validate serial number length
    if (!validateInput(serial.c_str(), 50)) {
        return;
    }

    // Add staff to database
    add_staff_to_db(name, id, gender, job,to_string(phone) , typeofpc, pcname, serial);
    cout << "Staff added successfully." << endl;
}

void search_staff() {
    string id;
    cout << "Enter staff ID to search: ";
    cin >> id;

    // Validate ID length
    if (!validateInput(id.c_str(), 20)) {
        return;
    }

    search_staff_in_db(id);
}

void update_staff() {
    string id, name, gender, job, typeofpc, pcname, serial;
    long long phone;

    cout << "Enter staff ID to update: ";
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

    cout << "Enter new job position: ";
    cin >> job;
    // Validate job length
    if (!validateInput(job.c_str(), 50)) {
        return;
    }

    cout << "Enter new PC type: ";
    cin >> typeofpc;
    // Validate PC type length
    if (!validateInput(typeofpc.c_str(), 20)) {
        return;
    }

    cout << "Enter new PC name: ";
    cin >> pcname;
    // Validate PC name length
    if (!validateInput(pcname.c_str(), 50)) {
        return;
    }

    cout << "Enter new serial number: ";
    cin >> serial;
    // Validate serial number length
    if (!validateInput(serial.c_str(), 50)) {
        return;
    }

    // Update staff in database
    update_staff_in_db(id, name, gender, job, to_string(phone), typeofpc, pcname, serial);
    cout << "Staff updated successfully." << endl;
}

void delete_staff() {
    string id;
    cout << "Enter staff ID to delete: ";
    cin >> id;

    // Validate ID length
    if (!validateInput(id.c_str(), 20)) {
        return;
    }

    delete_staff_from_db(id);
    cout << "Staff deleted successfully." << endl;
}

void display_staff() {
    display_all_staff_from_db();
}
