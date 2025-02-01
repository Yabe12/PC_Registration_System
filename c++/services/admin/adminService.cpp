#include <iostream>
#include "../../models/admin/admin.h"
#include "../../middleware/input_validation.h"
#include "../../database/admin/AdminDBOperations.h"
#include "../../database/connection.h"

using namespace std;

const int MAX_LENGTH = 50;


void add_admin() {
    Admin* new_admin = new Admin;
    cout << "Enter admin username: ";
    cin >> new_admin->username;
    if (!validateInput(new_admin->username, MAX_LENGTH)) return;
    cout << "Enter admin password: ";
    cin >> new_admin->password;
    if (!validateInput(new_admin->password, MAX_LENGTH)) return;

    new_admin->next = nullptr;
    if (admin_head == nullptr) {
        admin_head = new_admin;
        admin_tall = new_admin;
    } else {
        admin_tall->next = new_admin;
        admin_tall = new_admin;
    }
    cout << "\n Admin added to temporary storage.\n";
    cout << "Would you like to save it to the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        if (add_admin_to_db(new_admin->username, new_admin->password)) {
            cout << "Admin successfully saved to the database!" << endl;
        } else {
            cout << " Failed to save admin to database!" << endl;
        }
    } else {
        cout << " Admin not saved to the database." << endl;
    }
}

void update_admin() {
    char username[MAX_LENGTH];
    cout << "Enter admin username to update: ";
    cin >> username;
    Admin* current = admin_head;
    while (current != nullptr) {
        if (strcmp(current->username, username) == 0) {
            cout << "Admin found. What would you like to update?" << endl;
            cout << "1. Username" << endl;
            cout << "2. Password" << endl;
            cout << "3. Both" << endl;

            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter new username: ";
                    cin >> current->username;
                    if (!validateInput(current->username, MAX_LENGTH)) return;
                    break;
                case 2:
                    cout << "Enter new password: ";
                    cin >> current->password;
                    if (!validateInput(current->password, MAX_LENGTH)) return;
                    break;
                case 3:
                    cout << "Enter new username: ";
                    cin >> current->username;
                    if (!validateInput(current->username, MAX_LENGTH)) return;
                    cout << "Enter new password: ";
                    cin >> current->password;
                    if (!validateInput(current->password, MAX_LENGTH)) return;
                    break;
                default:
                    cout << "Invalid choice. No updates made." << endl;
                    return;
            }
            cout << " Admin updated successfully temporary!" << endl;
             cout << "Would you like to update this from the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        if (update_admin_in_db(username, current->password)) {
            cout << " Admin successfully updated in the database!" << endl;
        } else {
            cout << " Failed to update admin in database!" << endl;
        }
    } else {
        cout << " Admin update discarded. Not saved to database." << endl;
    }
            return;
        }
        current = current->next;
    }
    cout << " Admin not found in temporary" << endl;
   
}

void search_admin(){
    char username[MAX_LENGTH];
    cout << "Enter admin username to search: ";
    cin >> username;
    if (!validateInput(username, MAX_LENGTH)) return;

    Admin* current = admin_head;
    while (current != nullptr) {
        if (strcmp(current->username, username) == 0) {
            cout << "✅ Admin found in temporary storage:" << endl;
            cout << "Username: " << current->username << endl;
            cout << "Password: " << string(strlen(current->password), '*') << endl;
            return;
        }
        current = current->next;
    }
    cout << "❌ Admin not found in temporary storage." << endl;
cout << "Would you like to search from the  this from the database? (yes/no): ";
            string confirmation;
            cin >> confirmation;
            if (confirmation == "yes" || confirmation == "y") {
                search_admin_in_db(username);
            } else {
                cout << "⚠️ Admin search discarded. Not searched in database." << endl;
            }
}
  
void delete_admin(){

    char username[MAX_LENGTH];
    cout << "Enter admin username to delete: ";
    cin >> username;
  Admin *current = admin_head;
    Admin *prev = NULL;
    while(current != NULL){
        if(strcmp(current->username, username) == 0){
            if(prev == NULL){
                admin_head = current->next;
            }else{
                prev->next = current->next;
            }
            if(current == admin_tall){
                admin_tall = prev;
            }
            delete current;
            cout << "Admin deleted successfully!" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "❌ Admin not found in temporary storage." << endl;
    delete_admin_from_db(username);
}

void display_all_admins(){
    Admin* current = admin_head;
    if (current == nullptr) {
        cout << " No admins found in temporary storage." << endl;
        return;
    }
    cout << "Admins in temporary storage:" << endl;
    while (current != nullptr) {
        cout << "Username: " << current->username << endl;
        cout << "Password: " << string(strlen(current->password), '*') << endl;
        cout << "------------------------" << endl;
        current = current->next;
    }
    current = admin_head;
    cout << "Would you like to display all admins from the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        display_admin();
    } else {
        cout << " Admins not displayed from the database." << endl;
    }
}