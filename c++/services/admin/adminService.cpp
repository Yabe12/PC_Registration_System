#include <iostream>
#include <cstring>
#include <openssl/sha.h>  // For password hashing
#include <sstream>        // For stringstream
#include <iomanip>        // For setw, setfill
#include "../../models/admin/admin.h"
#include "../../middleware/input_validation.h"
#include "../../database/admin/AdminDBOperations.h"
#include "../../database/connection.h"

using namespace std;

const int MAX_LENGTH = 50;

// Function to hash a password using SHA-256
string hashPassword(const string &password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)password.c_str(), password.length(), hash);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void add_admin() {
    Admin* new_admin = new Admin;
    cout << "Enter admin username: ";
    cin >> new_admin->username;
    if (!validateInput(new_admin->username, MAX_LENGTH)) return;
    cout << "Enter admin password: ";
    cin >> new_admin->password;
    if (!validateInput(new_admin->password, MAX_LENGTH)) return;
  string Password = hashPassword(new_admin->password);
new_admin->next=nullptr;
if(admin_head == nullptr) {
    admin_head = new_admin;
    admin_tall = new_admin;
}else{
    admin_tall->next=new_admin;
    admin_tall = new_admin;
}
   cout << "\n✅ Admin added to temporary storage.\n";
    cout << "Would you like to save it to the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
     if (confirmation == "yes" || confirmation == "y") {
        if (add_admin_to_db(new_admin->username, Password)) {
            cout << "✅ Admin successfully saved to the database!" << endl;
        } else {
            cout << "❌ Failed to save admin to database!" << endl;
        }}else {
            cout << "�� Admin not saved to the database." << endl;
        }
}

void update_admin() {
    char username[MAX_LENGTH];
    cout << "Enter admin username to update: ";
    cin >> username;
    if (!validateInput(username, MAX_LENGTH)) return;

    Admin* current = admin_head;
    while (current != nullptr) {
        if (strcmp(current->username, username) == 0) {
            cout << "Admin found. What would you like to update?" << endl;
            cout << "1. Username" << endl;
            cout << "2. Password" << endl;
            cout << "3. Both" << endl;

            int choice;
            cin >> choice;
            string new_username, new_password;

            switch (choice) {
                case 1:
                    cout << "Enter new username: ";
                    cin >> new_username;
                    if (!validateInput(new_username, MAX_LENGTH)) return;
                    break;
                case 2:
                    cout << "Enter new password: ";
                    cin >> new_password;
                    if (!validateInput(new_password, MAX_LENGTH)) return;
                    new_password = hashPassword(new_password);
                    break;
                case 3:
                    cout << "Enter new username: ";
                    cin >> new_username;
                    if (!validateInput(new_username, MAX_LENGTH)) return;
                    cout << "Enter new password: ";
                    cin >> new_password;
                    if (!validateInput(new_password, MAX_LENGTH)) return;
                    new_password = hashPassword(new_password);
                    break;
                default:
                    cout << "❌ Invalid choice. No updates made." << endl;
                    return;
            }

            // Update admin in the database
            if (update_admin_in_db(username, new_username, new_password)) {
                strcpy(current->username, new_username.c_str());
                strcpy(current->password, new_password.c_str());
                cout << "✅ Admin updated successfully!" << endl;
            } else {
                cout << "❌ Failed to update admin!" << endl;
            }
            return;
        }
        current = current->next;
    }
    cout << "❌ Admin not found." << endl;
}

void delete_admin() {
    char username[MAX_LENGTH];
    cout << "Enter admin username to delete: ";
    cin >> username;
    if (!validateInput(username, MAX_LENGTH)) return;

    Admin* current = admin_head;
    Admin* prev = nullptr;

    while (current != nullptr) {
        if (strcmp(current->username, username) == 0) {
            if (prev == nullptr) {
                admin_head = current->next;
            } else {
                prev->next = current->next;
            }

            if (current == admin_tall) {
                admin_tall = prev;
            }

            // Delete from the database
            if (delete_admin_from_db(username)) {
                delete current;
                cout << "✅ Admin deleted successfully!" << endl;
            } else {
                cout << "❌ Failed to delete admin!" << endl;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "❌ Admin not found." << endl;
}
