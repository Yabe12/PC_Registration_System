#include "../../models/users/non_staff.h"
#include "../../middleware/input_validation.h"
#include "../../database/user/non_staff/NonStaffDBOperations.h"
#include <iostream>

using namespace std;

nonstaff* nonstaff_head = nullptr;
nonstaff* nonstaff_tall = nullptr;
const int MAX_LENGTH = 50;

void add_nonstaff() {
   cout << "\n=============================================" << endl;
    cout << "          Add New Student" << endl;
    cout << "=============================================" << endl;
    nonstaff *new_nonstaff = new nonstaff;
    cout << "Enter nonstaff's name: ";
    cin>>new_nonstaff->name;
    if (!validateInput(new_nonstaff->name, MAX_LENGTH)) return;

    cout << "Enter nonstaff's ID: ";
     cin >> new_nonstaff->id;
     if (!validateInput(new_nonstaff->id, 20)) return;

    cout << "Enter nonstaff's gender (Male/Female): ";
        cin >> new_nonstaff->gender;
        if (!validateGender(new_nonstaff->gender)) return;

    cout << "Enter nonstaff's phone number: ";
    cin >> new_nonstaff->phone;
    if (!validatePhoneNumber(new_nonstaff->phone)) return;
    cin.ignore();

    cout << "Enter nonstaff's PC name: ";
    cin >> new_nonstaff->pcname;
    if (!validateInput(new_nonstaff->pcname, 50)) return;
    cin.ignore(); 
    cout << "Enter nonstaff's PC serial number: ";
    cin >> new_nonstaff->serial;
    if (!validateInput(new_nonstaff->serial, 50)) return;
    new_nonstaff->next =NULL;
    new_nonstaff->prev = nonstaff_tall;
    if(nonstaff_tall != NULL){nonstaff_tall->next =new_nonstaff;} nonstaff_tall=new_nonstaff;
    if(nonstaff_head == NULL){nonstaff_head=nonstaff_tall; 
    } cout << "The nonstaff is added in temporary storage "<<endl;
    cout << "Would you like to save it to the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        add_nonstaff_to_db(new_nonstaff->name, new_nonstaff->id, new_nonstaff->gender, new_nonstaff->phone, new_nonstaff->pcname, new_nonstaff->serial) ;
           
        } else {
            cout << " Failed to save nonstaff to database!" << endl;
        }
}

void search_nonstaff() {
   char nonstaff_name[MAX_LENGTH];
    cout << "Enter nonstaff name to search: ";
    cin >> nonstaff_name;
    if (!validateInput(nonstaff_name, MAX_LENGTH)) return;
    nonstaff *current=nonstaff_head;
    while (current != NULL){
        if (strcmp(current->name, nonstaff_name)==0){
            cout << "\n=============================================" << endl;
            cout << "          Nonstaff Details" << endl;
            cout << "=============================================" << endl;
            cout << "Name: " << current->name << endl;
            cout << "ID: " << 
            current->id << endl;
            cout << "Gender: " << current->gender << endl;
            cout << "Phone: " << current->phone << endl;
            cout << "Computer Name: " << current->pcname << endl;
            cout << "Computer Serial Number: " << current->serial << endl;
            return;
            }
            current = current->next;
}
cout << "Nonstaff not found in temporary." << endl;
cout << "Would you like to search from the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        search_nonstaff_in_db(nonstaff_name);
    } else {
        cout << "Nonstaff search discarded. Not searched in database." << endl;
    }
}

void update_nonstaff() {
    char nonstaff_id[MAX_LENGTH];
    cout << "\n=============================================" << endl;
    cout << "          Update Nonstaff Information" << endl;
    cout << "=============================================" << endl;
    cout << "Enter nonstaff's ID to update: ";
    cin >> nonstaff_id;
    nonstaff *current =  nonstaff_head;
    while (current != nullptr){
        if(strcmp(current->name, nonstaff_id) == 0){
            cout << "Nonstaff found: what to what to update " << endl;
            cout << "1. Name: "  << endl;
            cout << "2. ID: " << endl;
            cout << "3. Gender: " <<  endl;
            cout << "4. Phone: " << endl;
            cout << "5. Computer Name: " <<  endl;
            cout << "6. Computer Serial Number: " <<  endl;
            cout << "7.all of the above" << endl;
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
                    if (!validateInput(current->id, 20)) return;
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
                    cout << "Enter new PC name: ";
                    cin >> current->pcname;
                    if (!validateInput(current->pcname, 50)) return;
                case 6:
                    cout << "Enter new PC serial number: ";
                    cin >> current->serial;
                    if (!validateInput(current->serial, 50)) return;
                    break;
                case 7:
                    cout << "Enter new name: ";
                    cin >> current->name;
                    if (!validateInput(current->name, MAX_LENGTH)) return;
                    cout << "Enter new ID: ";
                    cin >> current->id;
                    if (!validateInput(current->id, 20)) return;
                    cout << "Enter new gender (Male/Female): ";
                    cin >> current->gender;
                    if (!validateGender(current->gender)) return;
                    cout << "Enter new phone number: ";
                    cin >> current->phone;
                    if (!validatePhoneNumber(current->phone)) return;
                    cout << "Enter new PC name: ";
                    cin >> current->pcname;
                    if (!validateInput(current->pcname, 50)) return;
                    cout << "Enter new PC serial number: ";
                    cin >> current->serial;
                    if (!validateInput(current->serial, 50)) return;
                    break;

                default:
                cout << "Invalid choice. Please try again." << endl;
                return;
                
            }
            cout << "Nonstaff information updated temporary successfully." << endl;
            cout << "Would you like to update this from the database? (yes/no): ";
            string confirmation;
            cin >> confirmation;
            if (confirmation == "yes" || confirmation == "y") {
                update_nonstaff_in_db(current->id, current->name, current->gender, current->phone, current->pcname, current->serial);
                cout << "Nonstaff information updated in database successfully." << endl;
            } else {
                cout << "Nonstaff information update discarded. Not updated in database." << endl;
            }
            return;

        }
        current = current->next;
}
cout << "Nonstaff not found in temporary storage." << endl;
}
void delete_nonstaff() {
    char nonstaff_name[MAX_LENGTH];
    cout << "Enter the name of the nonstaff to delete: ";
    cin >> nonstaff_name;
    nonstaff* current = nonstaff_head;
    nonstaff* prev = nullptr;
    while (current != nullptr) {
        if (strcmp(nonstaff_name, current->name) == 0) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                nonstaff_head = current->next;
            }
            if (current == nonstaff_tall) {
                nonstaff_tall = prev;
            }
            delete current;
            cout << "Nonstaff deleted successfully from temporary." << endl;
            cout << "Would you like to delete this nonstaff from the database as well? (yes/no): ";
            string confirmation;
            cin >> confirmation;
            if (confirmation == "yes" || confirmation == "y") {
                delete_nonstaff_from_db(nonstaff_name);
                cout << "Nonstaff deleted successfully from the database." << endl;
            } else {
                cout << "Nonstaff deletion from the database discarded." << endl;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Nonstaff not found in temporary storage." << endl;
}

void display_nonstaff() {
    cout << "\n=============================================" << endl;
    cout << "             Nonstaff List" << endl;
    cout << "=============================================" << endl;
    nonstaff *current = nonstaff_head;    
    if(current==NULL)
{
    cout << "No nonstaff found in the temporary." << endl;
     cout << "would like to connect to the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        display_all_nonstaff_from_db();
    } else {
        cout << "Nonstaff not displayed from the database." << endl;
    }
    
    return;
}
cout <<"nonstaff in the temporary storage" << endl;
while(current != NULL){
    cout << "Name: " << current->name << endl;
    cout << "ID: " << current->id << endl;
    cout << "gender: " << current->gender << endl;
    cout << "Phone: " << current->phone << endl;
    cout << "Computer Name: " << current->pcname << endl;
    cout << "Computer Serial Number: " << current->serial << endl;
    cout << "---------------------------------------------" << endl;
    current = current->next;}
    cout << "would like to connect to the database? (yes/no): ";
    string confirmation;
    cin >> confirmation;
    if (confirmation == "yes" || confirmation == "y") {
        display_all_nonstaff_from_db();
    } else {
        cout << "Nonstaff not displayed from the database." << endl;
    }
    }