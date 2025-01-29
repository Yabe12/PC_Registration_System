#include "NonstaffService.h"
#include ""
#include <iostream>
using namespace std;

void add_nonstaff() {
    string name, id, gender, pcname, serial, superadmin_username;
    long long phone;
    int admin_id;

    cout << "Enter nonstaff name: ";
    cin >> name;
    cout << "Enter nonstaff ID: ";
    cin >> id;
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter phone number: ";
    cin >> phone;
    cout << "Enter PC name: ";
    cin >> pcname;
    cout << "Enter PC serial number: ";
    cin >> serial;
    cout << "Enter superadmin username: ";
    cin >> superadmin_username;
    cout << "Enter admin ID: ";
    cin >> admin_id;

    add_nonstaff_to_db(name, id, gender, phone, pcname, serial, superadmin_username, admin_id);
    cout << "Nonstaff added successfully." << endl;
}

void search_nonstaff() {
    string id;
    cout << "Enter nonstaff ID to search: ";
    cin >> id;

    search_nonstaff_in_db(id);
}

void update_nonstaff() {
    string id, name, gender, pcname, serial;
    long long phone;

    cout << "Enter nonstaff ID to update: ";
    cin >> id;
    cout << "Enter new name: ";
    cin >> name;
    cout << "Enter new gender: ";
    cin >> gender;
    cout << "Enter new phone number: ";
    cin >> phone;
    cout << "Enter new PC name: ";
    cin >> pcname;
    cout << "Enter new PC serial number: ";
    cin >> serial;

    update_nonstaff_in_db(id, name, gender, phone, pcname, serial);
    cout << "Nonstaff updated successfully." << endl;
}

void delete_nonstaff() {
    string id;
    cout << "Enter nonstaff ID to delete: ";
    cin >> id;

    delete_nonstaff_from_db(id);
    cout << "Nonstaff deleted successfully." << endl;
}

void display_nonstaff() {
    display_all_nonstaff_from_db();
}
