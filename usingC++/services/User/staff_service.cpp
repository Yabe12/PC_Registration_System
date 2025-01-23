#include <iostream>
#include "./models/users/staff.cpp"
using namespace std;

int main () {

    
void sort_staff() {
    if (staff_head == NULL) return;
    staff *current = staff_head->next;
    while (current != NULL) {
        staff *key = current;
        staff *prev = staff_head;
        while (prev != key && strcmp(prev->name, key->name) < 0) {
            prev = prev->next;
        }
        if (prev != key) {
            key->prev->next = key->next;
            if (key->next != NULL) {
                key->next->prev = key->prev;
            }
            key->next = prev->next;
            if (prev->next != NULL) {
                prev->next->prev = key;
            }
            prev->next = key;
            key->prev = prev;
        }
        current = current->next;
    }
    cout << "Staff list sorted successfully." << endl;
}


void add_staff(){
    staff *new_staff=new staff();
    cout << "Enter staff's name: ";
  cin.ignore();
  cin.getline(new_staff->name, 20);
  cout << "Enter staff's ID: ";
  cin >> new_staff->id;
  cout << "Enter staff's gender (M/F): ";
  cin >> new_staff->gender;
  cout << "Enter staff's role: ";
  cin >> new_staff->job;
 cout << "Enter staff's type of PC (personal laptop/office laptop): ";
  cin >> new_staff->typeofpc;
  cout << "Enter staff's phone number: ";
  cin >> new_staff->phone;
  cout << "Enter staff's computer name: ";
  cin >> new_staff->pcname;
  cout << "Enter staff's computer serial number: ";
  cin >> new_staff->serial;
  new_staff->next =NULL;
  new_staff->prev = staff_tall;
  if(staff_tall != NULL){staff_tall->next =new_staff;} staff_tall=new_staff;
  if(staff_head == NULL){staff_head=staff_tall; 
  }
  cout << "student added"<<endl;
  sort_staff();

  }
  void search_staff(){
  char name[10];
  cout << "Enter staff's name to search: ";
  cin >> name;
  staff *current = staff_head;
  while(current != NULL){
    if(strcmp(current->name, name) == 0){
      cout << "Staff found:" << endl;
      cout << "Name: " << current->name << endl;
      cout << "ID: " << current->id << endl;
      cout << "Gender: " << current->gender << endl;
      cout << "Role: " << current->job << endl;
      cout << "Type of PC: " << current->typeofpc << endl;
      cout << "Phone: " << current->phone << endl;
      cout << "Computer Name: " << current->pcname << endl;
      cout << "Computer Serial Number: " << current->serial << endl;
    
      return;
    }
    current = current->next;
  }
}

void display_staff(){
  staff *current = staff_head;
  cout << "Staff List:" << endl;
  while(current!= NULL){
    cout << "Name: " << current->name << endl;
    cout << "ID: " << current->id << endl;
    cout << "Gender: " << current->gender << endl;
    cout << "Role: " << current->job << endl;
    cout << "Type of PC: " << current->typeofpc << endl;
    cout << "Phone: " << current->phone << endl;
    cout << "Computer Name: " << current->pcname << endl;
    cout << "Computer Serial Number: " << current->serial << endl;
  
    current = current->next;
    cout << endl;
  }
}

void update_staff() {
    char id[20];
    cout << "Enter staff's ID to update: ";
    cin >> id;

    staff *current = staff_head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) { 
            cout << "Staff found. What would you like to update?" << endl;
            cout << "1. All details" << endl;
            cout << "2. Name" << endl;
            cout << "3. Gender" << endl;
            cout << "4. Role" << endl;
            cout << "5. Type of PC" << endl;
            cout << "6. Phone number" << endl;
            cout << "7. Computer name" << endl;
            cout << "8. Computer serial number" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    cin.ignore(); 
                    cin.getline(current->name, 50);

                    cout << "Enter new gender (M/F): ";
                    cin >> current->gender;

                    cout << "Enter new role: ";
                    cin.ignore();
                    cin.getline(current->job, 50);

                    cout << "Enter new type of PC: ";
                    cin.getline(current->typeofpc, 50);

                    cout << "Enter new phone number: ";
                    cin >> current->phone;

                    cout << "Enter new computer name: ";
                    cin.ignore(); 
                    cin.getline(current->pcname, 50);

                    cout << "Enter new computer serial number: ";
                    cin.getline(current->serial, 50);
                    break;

                case 2: 
                    cout << "Enter new name: ";
                    cin.ignore(); 
                    cin.getline(current->name, 50);
                    break;

                case 3: 
                    cout << "Enter new gender (M/F): ";
                    cin >> current->gender;
                    break;

                case 4: 
                    cout << "Enter new role: ";
                    cin.ignore(); 
                    cin.getline(current->job, 50);
                    break;

                case 5: 
                    cout << "Enter new type of PC: ";
                    cin.ignore(); 
                    cin.getline(current->typeofpc, 50);
                    break;

                case 6: 
                    cout << "Enter new phone number: ";
                    cin >> current->phone;
                    break;

                case 7: 
                    cout << "Enter new computer name: ";
                    cin.ignore(); 
                    cin.getline(current->pcname, 50);
                    break;

                case 8:
                    cout << "Enter new computer serial number: ";
                    cin.ignore(); 
                    cin.getline(current->serial, 50);
                    break;

                default:
                    cout << "Invalid choice. No updates were made." << endl;
                    return;
            }

            cout << "Staff details updated successfully!" << endl;
            return; 
        }
        current = current->next;
    }

    cout << "Staff not found." << endl;
}

void delete_staff() {
    char id[20];
    cout << "Enter staff's ID to delete: ";
    cin >> id;
    staff *current = staff_head;
    while (current != NULL && strcmp(current->id, id) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Staff not found." << endl;
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        staff_head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    delete current;
    cout << "Staff deleted successfully." << endl;
}

  
}