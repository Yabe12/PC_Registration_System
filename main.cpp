// --- main.cpp ---
#include "menus/main_menu.cpp"

int main() {
    mainMenu();
    return 0;
}


//

#include <iostream>
#include <cstring>

using namespace std;

struct Admin {
    char username[50];
    char password[50];
    Admin *next;
};

struct student {
    char name[50];
    char id[20];
    char gender;
    char department[50];
    int year;
    long long phone;
    char pcname[50];
    char serial[50];
    student *next;
    student *prev;
};

struct staff {
    char name[50];
    char id[20];
    char gender;
    char job[50];
    long long phone;
    char typeofpc[20];
    char pcname[50];
    char serial[50];
    staff *next;
    staff *prev;
};

struct nonstaff {
    char name[50];
    char id[20];
    char gender;
    long long phone;
    char pcname[50];
    char serial[50];
    nonstaff *next;
    nonstaff *prev;
};

// Global linked list heads
student *student_head = NULL, *student_tall =NULL;
staff *staff_head = NULL, *staff_tall = NULL;
nonstaff *nonstaff_head = NULL, *nonstaff_tall = NULL;
Admin *admin_head = NULL, *admin_tall =NULL;

const char superAdminUsername[] = "superadmin";
const char superAdminPassword[] = "admin123";
bool isSuperAdmin = false;
bool isAuthenticated = false;

// Authentication Function
bool login(bool isSuper) {
    char username[50], password[50];
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (isSuper && strcmp(username, superAdminUsername) == 0 && strcmp(password, superAdminPassword) == 0) {
        isSuperAdmin = true;
        isAuthenticated = true;
        return true;
    }

    if (!isSuper) {
        Admin *temp = admin_head;
        while (temp) {
            if (strcmp(temp->username, username) == 0 && strcmp(temp->password, password) == 0) {
                isSuperAdmin = false;
                isAuthenticated = true;
                return true;
            }
            temp = temp->next;
        }
    }

    cout << "Invalid credentials!\n";
    return false;
}

bool validateInput(const char* str, int maxLength) {
    if (strlen(str) >= maxLength) {
        cout << "Input too long. Maximum length is " << maxLength-1 << " characters." << endl;
        return false;
    }
    return true;
}

bool validateGender(char gender) {
    gender = toupper(gender);
    if (gender != 'M' && gender != 'F') {
        cout << "Invalid gender. Please enter M or F." << endl;
        return false;
    }
    return true;
}

bool validatePhoneNumber(long long phone) {
    // Assuming phone numbers should be between 8 and 15 digits
    int digits = 0;
    long long temp = phone;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }
    if (digits < 8 || digits > 15) {
        cout << "Invalid phone number length." << endl;
        return false;
    }
    return true;
}

void menu_superadmin();
void menu_admin();
void menu_work_on_users();
void menu_work_on_admins();
void add_user();
void search();
void display();
void Update();
void Delete();
void add_admin();
void update_admin();
void search_admin();
void delete_admin();
void display_admin();
int main() {
    while (true) {
        char roleChoice;
        cout << "Choose your role:\nA. I am SuperAdmin\nB. I am Admin\n";
        cin >> roleChoice;

        if (roleChoice == 'A' || roleChoice == 'a') {
            if (!login(true)) return 0;
            menu_superadmin();
        } else if (roleChoice == 'B' || roleChoice == 'b') {
            if (!login(false)) return 0;
            menu_admin();
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

void menu_superadmin() {
    int choice;
    while (true) {
        cout << "\nSuperAdmin Menu:\n";
        cout << "1. Work on User\n";
        cout << "2. Work on Admin\n";
        cout << "3. Back\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: menu_work_on_users(); break;
            case 2: menu_work_on_admins(); break;
            case 3: return; // Return to main menu
            case 4: exit(0);
            default: cout << "Invalid choice, try again.\n";
        }
    }
}

void menu_work_on_users() {
    int choice;
    while (true) {
        cout << "\nWork on Users:\n";
        cout << "1. Add User\n";
        cout << "2. Update User\n";
        cout << "3. Delete User\n";
        cout << "4. Search and Display\n";
        cout << "5. Display All\n";
        cout << "6. Back\n";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Adding user...\n"; add_user(); break; 
            case 2: cout << "Update user...\n"; Update(); break;
            case 3: cout << "Delete user...\n"; Delete(); break;
            case 4:  cout << "search user...\n";search(); break;
            case 5: cout << "display user...\n"; display(); break;
            case 6:
            return;
            default: cout << "Invalid choice, try again.\n";
        }
    }
}

void menu_work_on_admins() {
    int choice;
    while (true) {
        cout << "\nWork on Admins:\n";
        cout << "1. Create Admin\n";
        cout << "2. Update Admin\n";
        cout << "3. Delete Admin\n";
        cout << "4. Search and Display\n";
        cout << "5. Display All Admins\n";
        cout << "6. Back\n";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Creating admin...\n";add_admin(); break;
            case 2: cout << "Updating admin...\n";update_admin(); break;
            case 3: cout << "Deleting admin...\n";delete_admin(); break;
            case 4: cout << "Searching admin...\n";search_admin(); break;
            case 5: cout << "Displaying all admins...\n";display_admin(); break;
            case 6: 
            return;
            default: cout << "Invalid choice, try again.\n";
        }
    }
}

void menu_admin() {
    int choice;
    while (true) {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add User\n";
        cout << "2. Update User\n";
        cout << "3. Search and Display\n";
        cout << "4. Display All\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                add_user();
                break; 
            case 2: 
               Update();
               break;
            case 3:
               search();
               break;
            case 4: 
               display();
               break;
            case 5: 
            return;
            default: cout << "Invalid choice, try again.\n";
        }
    }
}

void add_admin() {
    Admin *new_admin = new Admin;
    cout << "Enter admin username: ";
    cin >> new_admin->username;
    cout << "Enter admin password: ";
    cin >> new_admin->password;

    // Add to the end of the list
    new_admin->next = NULL;
    if (admin_head == NULL) {
        admin_head = new_admin;
        admin_tall = new_admin;
    } else {
        admin_tall->next = new_admin;
        admin_tall = new_admin;
    }
    cout << "Admin added successfully!" << endl;
}

void update_admin() {
    char username[50];
    cout << "Enter admin username to update: ";
    cin >> username;

    Admin *current = admin_head;
    while (current != NULL) {
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
                    break;
                case 2:
                    cout << "Enter new password: ";
                    cin >> current->password;
                    break;
                case 3:
                    cout << "Enter new username: ";
                    cin >> current->username;
                    cout << "Enter new password: ";
                    cin >> current->password;
                    break;
                default:
                    cout << "Invalid choice. No updates made." << endl;
                    return;
            }
            cout << "Admin updated successfully!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Admin not found." << endl;
}

void search_admin() {
    char username[50];
    cout << "Enter admin username to search: ";
    cin >> username;

    Admin *current = admin_head;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            cout << "Admin found:" << endl;
            cout << "Username: " << current->username << endl;
            cout << "Password: " << string(strlen(current->password), '*') << endl;
            return;
        }
        current = current->next;
    }
    cout << "Admin not found." << endl;
}

void delete_admin() {
    char username[50];
    cout << "Enter admin username to delete: ";
    cin >> username;

    Admin *current = admin_head;
    Admin *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            if (prev == NULL) {
                admin_head = current->next;
            } else {
                prev->next = current->next;
            }
            
            if (current == admin_tall) {
                admin_tall = prev;
            }
            
            delete current;
            cout << "Admin deleted successfully!" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Admin not found." << endl;
}

void display_admin() {
    if (admin_head == NULL) {
        cout << "No admins found in the system." << endl;
        return;
    }

    Admin *current = admin_head;
    int count = 1;
    cout << "\nAdmin List:" << endl;
    cout << "------------------------" << endl;
    
    while (current != NULL) {
        cout << count << ". Username: " << current->username << endl;
        cout << "   Password: " << string(strlen(current->password), '*') << endl;
        cout << "------------------------" << endl;
        current = current->next;
        count++;
    }
}

void sort_student() {
    if (student_head == NULL) return;
    student *current = student_head->next;
    while (current != NULL) {
        student *key = current;
        student *prev = student_head;
        while (prev != key && strcmp(prev->id, key->id) < 0) {
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
    cout << "Student list sorted successfully." << endl;
}

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

void sort_nonstaff() {
    if (nonstaff_head == NULL) return;
    nonstaff *current = nonstaff_head->next;
    while (current != NULL) {
        nonstaff *key = current;
        nonstaff *prev = current->prev;
        while (prev != NULL && strcmp(prev->name, key->name) > 0) {
            prev = prev->prev;
        }
        current = current->next;
        if (key->prev != NULL) {
            key->prev->next = key->next;
        }
        if (key->next != NULL) {
            key->next->prev = key->prev;
        }
        if (prev == NULL) {
            key->next = nonstaff_head;
            nonstaff_head->prev = key;
            nonstaff_head = key;
            key->prev = NULL;
        } else {
            key->next = prev->next;
            if (prev->next != NULL) {
                prev->next->prev = key;
            }
            prev->next = key;
            key->prev = prev;
        }
    }
    cout << "Non-staff list sorted successfully." << endl;
}

void add_student(){
      
  student *new_student = new student;
  cout << "Enter student's name: ";
  cin.ignore();
  cin.getline(new_student->name, 20);
  cout << "Enter student's ID: ";
  cin >> new_student->id;
  cout << "Enter student's gender (M/F): ";
  cin >> new_student->gender;
  cout << "Enter student's department: ";
  cin >> new_student->department;
  cout << "Enter student's year: ";
  cin >> new_student->year;
  cout << "Enter student's phone number: ";
  cin >> new_student->phone;
  cout << "Enter student's computer name: ";
  cin >> new_student->pcname;
  cout << "Enter student's computer serial number: ";
  cin >> new_student->serial;
new_student->next =NULL;
  new_student->prev = student_tall;
  if(student_tall != NULL){student_tall->next =new_student;} student_tall=new_student;
  if(student_head == NULL){student_head=student_tall; 
  }
  cout << "The student is added"<<endl;
  sort_student();
 
  };
  void add_nonstaff(){
    nonstaff *new_nonstaff = new nonstaff;
    cout << "Enter nonstaff's name: ";
    cin.ignore();
    cin.getline(new_nonstaff->name, 20);
    cout << "Enter nonstaff's ID: ";
    cin >> new_nonstaff->id;
    cout << "Enter nonstaff's gender (M/F): ";
    cin >> new_nonstaff->gender;
    cout << "Enter nonstaff phone: " ;
    cin >> new_nonstaff->phone;
    cout << "Enter nonstaff computer name: ";
    cin >> new_nonstaff->pcname;
    cout << "Enter nonstaff computer serial number: ";
    cin >> new_nonstaff->serial;
  new_nonstaff->next =NULL;
  new_nonstaff->prev = nonstaff_tall;
  if(nonstaff_tall != NULL){nonstaff_tall->next =new_nonstaff;} nonstaff_tall=new_nonstaff;
  if(nonstaff_head == NULL){nonstaff_head=nonstaff_tall; 
  }
  cout << "student added"<<endl;
  sort_nonstaff();
 


  };
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


  };
void add_user(){
  int choice;
  while(true){
    cout << "Choose a type of user:" << endl;
    cout << "1. student" << endl;
    cout << "2. staff" << endl;
    cout << "3. nonstaff" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if(choice == 1){
      add_student();
      break;
    }else if(choice == 2){
      add_staff();
      break;
    } else if(choice == 3){
      add_nonstaff();
      break;
    }else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }

}
// function for search functionaily


void search_student() {
    char choice;
    char id[10];
    char name[50];
    
    cout << "Search by: " << endl;
    cout << "1. ID" << endl;
    cout << "2. Name" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    student *current = student_head;

    if (choice == '1') {
        cout << "Enter student's ID to search: ";
        cin >> id;
        
        while (current != NULL) {
            if (strcmp(current->id, id) == 0) {
                cout << "Student found:" << endl;
                cout << "Name: " << current->name << endl;
                cout << "ID: " << current->id << endl;
                cout << "Gender: " << current->gender << endl;
                cout << "Department: " << current->department << endl;
                cout << "Year: " << current->year << endl;
                cout << "Phone: " << current->phone << endl;
                cout << "Computer Name: " << current->pcname << endl;
                cout << "Computer Serial Number: " << current->serial << endl;
                return;
            }
            current = current->next;
        }
        cout << "Student not found." << endl;

    } else if (choice == '2') {
        
        cout << "Enter student's Name to search: ";
        cin.ignore(); 
        cin.getline(name, 50); 
        
        while (current != NULL) {
            if (strcmp(current->name, name) == 0) { 
                cout << "Student found:" << endl;
                cout << "Name: " << current->name << endl;
                cout << "ID: " << current->id << endl;
                cout << "Gender: " << current->gender << endl;
                cout << "Department: " << current->department << endl;
                cout << "Year: " << current->year << endl;
                cout << "Phone: " << current->phone << endl;
                cout << "Computer Name: " << current->pcname << endl;
                cout << "Computer Serial Number: " << current->serial << endl;
                return;
            }
            current = current->next;
        }
        cout << "Student not found." << endl;

    } else {
        cout << "Invalid choice. Please enter 1 or 2." << endl;
    }
}

void search_nonstaff(){
  char name[100];
  cout << "Enter nonstaff's name to search: ";
  cin >> name;
  nonstaff *current = nonstaff_head;
  while(current != NULL){
    if(strcmp(current->name, name) == 0){
      cout << "Nonstaff found:" << endl;
      cout << "Name: " << current->name << endl;
      cout << "ID: " << current->id << endl;
      cout << "Gender: " << current->gender << endl;
      cout << "Phone: " << current->phone << endl;
      cout << "Computer Name: " << current->pcname << endl;
      cout << "Computer Serial Number: " << current->serial << endl;
    
      return;
    }
    current = current->next;
  }
  cout << "Nonstaff not found." << endl;
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
void search(){
  int choice;
  while(true){
    cout << "Choose a type of user to search and display:" << endl;
    cout << "1. student" << endl;
    cout << "2. staff" << endl;
    cout << "3. nonstaff" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if(choice == 1){
      search_student();
      break;
    } else if(choice == 2){
      search_staff();
      break;
    } else if(choice == 3){
      search_nonstaff();
      break;
    } else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }
}

// function for display functinally

void display_student(){
  student *current = student_head;
  cout << "Student List:" << endl;
  while(current!= NULL){
    cout << "Name: " << current->name << endl;
    cout << "ID: " << current->id << endl;
    cout << "Gender: " << current->gender << endl;
    cout << "Department: " << current->department << endl;
    cout << "Year: " << current->year << endl;
    cout << "Phone: " << current->phone << endl;
    cout << "Computer Name: " << current->pcname << endl;
    cout << "Computer Serial Number: " << current->serial << endl;
    current = current->next;
    cout << endl;
  }
}
void display_nonstaff(){
  nonstaff *current = nonstaff_head;
  cout << "Nonstaff List:" << endl;
  while(current!= NULL){
    cout << "Name: " << current->name << endl;
    cout << "ID: " << current->id << endl;
    cout << "Gender: " << current->gender << endl;
    cout << "Phone: " << current->phone << endl;
    cout << "Computer Name: " << current->pcname << endl;
    cout << "Computer Serial Number: " << current->serial << endl;
    
    current = current->next;
    cout << endl;
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

void display(){
  int choice;
  while(true){
    cout << "Choose a type of user to search and display:" << endl;
    cout << "1. student" << endl;
    cout << "2. staff" << endl;
    cout << "3. nonstaff" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if(choice == 1){
      display_student();
      break;
    } else if(choice == 2){
      display_staff();
      break;
    } else if(choice == 3){
      display_nonstaff();
      break;
    } else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }
}
// function for update functionally
void update_student() {
    char id[20];
    cout << "Enter student's ID to update: ";
    cin >> id;

    student *current = student_head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            cout << "Student found. What would you like to update?" << endl;
            cout << "1. All details" << endl;
            cout << "2. Name" << endl;
            cout << "3. Gender" << endl;
            cout << "4. Department" << endl;
            cout << "5. Year" << endl;
            cout << "6. Phone number" << endl;
            cout << "7. Computer name" << endl;
            cout << "8. Computer serial number" << endl;
            cout << "Enter your choice: ";
            
            int choice;
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    cin.getline(current->name, 50);

                    cout << "Enter new gender (M/F): ";
                    cin >> current->gender;
                    cin.ignore(); 

                    cout << "Enter new department: ";
                    cin.getline(current->department, 50);

                    cout << "Enter new year: ";
                    cin >> current->year;
                    cin.ignore(); 

                    cout << "Enter new phone number: ";
                    cin >> current->phone;
                    cin.ignore();

                    cout << "Enter new computer name: ";
                    cin.getline(current->pcname, 50);

                    cout << "Enter new computer serial number: ";
                    cin.getline(current->serial, 50);
                    break;

                case 2:
                    cout << "Enter new name: ";
                    cin.getline(current->name, 50);
                    break;

                case 3:
                    cout << "Enter new gender (M/F): ";
                    cin >> current->gender;
                    cin.ignore(); 
                    break;

                case 4:
                    cout << "Enter new department: ";
                    cin.getline(current->department, 50);
                    break;

                case 5:
                    cout << "Enter new year: ";
                    cin >> current->year;
                    cin.ignore(); 
                    break;

                case 6:
                    cout << "Enter new phone number: ";
                    cin >> current->phone;
                    cin.ignore(); 
                    break;

                case 7:
                    cout << "Enter new computer name: ";
                    cin.getline(current->pcname, 50);
                    break;

                case 8:
                    cout << "Enter new computer serial number: ";
                    cin.getline(current->serial, 50);
                    break;

                default:
                    cout << "Invalid choice. No updates were made." << endl;
                    return;
            }

            cout << "Student details updated successfully!" << endl;
            return;
        }
        current = current->next;
    }

    cout << "Student not found." << endl;
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
void update_nonstaff() {
    char id[20];
    cout << "Enter ID to update: ";
    cin >> id;

    nonstaff *current = nonstaff_head; 
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) { 
            cout << "Non-staff entity found. What would you like to update?" << endl;
            cout << "1. All details" << endl;
            cout << "2. Name" << endl;
            cout << "3. Gender" << endl;
            cout << "4. Phone number" << endl;
            cout << "5. Computer name" << endl;
            cout << "6. Computer serial number" << endl;
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
                    cout << "Enter new phone number: ";
                    cin >> current->phone;
                    break;

                case 5: 
                    cout << "Enter new computer name: ";
                    cin.ignore(); 
                    cin.getline(current->pcname, 50);
                    break;

                case 6:
                    cout << "Enter new computer serial number: ";
                    cin.ignore();
                    cin.getline(current->serial, 50);
                    break;

                default:
                    cout << "Invalid choice. No updates were made." << endl;
                    return;
            }

            cout << "Non-staff details updated successfully!" << endl;
            return;
        }
        current = current->next;
    }

    cout << "Non-staff entity not found." << endl;
}


void Update(){
  int choice;
  while(true){
    cout << "Choose a type of user to update :" << endl;
    cout << "1. student" << endl;
    cout << "2. staff" << endl;
    cout << "3. nonstaff" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if(choice == 1){
      update_student();
      break;
    } else if(choice == 2){
      update_staff();
      break;
    } else if(choice == 3){
      update_nonstaff();
      break;
    } else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }
};
// function for delete functionally


void delete_student() {
    char id[20];
    cout << "Enter student's ID to delete: ";
    cin >> id;
    student *current = student_head;
    while (current != NULL && strcmp(current->id, id) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Student not found." << endl;
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        student_head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    delete current;
    cout << "Student deleted successfully." << endl;
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

void delete_nonstaff() {
    char id[20];
    cout << "Enter nonstaff's ID to delete: ";
    cin >> id;
    nonstaff *current = nonstaff_head;
    while (current != NULL && strcmp(current->id, id) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Nonstaff not found." << endl;
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        nonstaff_head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    delete current;
    cout << "Nonstaff deleted successfully." << endl;
}

void Delete() {
    int choice;
    while (true) {
        cout << "Choose a type of user to delete:" << endl;
        cout << "1. student" << endl;
        cout << "2. staff" << endl;
        cout << "3. nonstaff" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        if (choice == 1) {
            delete_student();
            break;
        } else if (choice == 2) {
            delete_staff();
            break;
        } else if (choice == 3) {
            delete_nonstaff();
            break;
        } else if (choice == 4) {
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
