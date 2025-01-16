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
student *student_head = nullptr;
staff *staff_head = nullptr;
nonstaff *nonstaff_head = nullptr;
Admin *admin_head = nullptr;

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

void menu_superadmin();
void menu_admin();
void menu_work_on_users();
void menu_work_on_admins();
void add_user();
void search();
void display();
void Update();
void Delete();
int main() {
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

    return 0;
}

void menu_superadmin() {
    int choice;
    while (true) {
        cout << "\nSuperAdmin Menu:\n";
        cout << "1. Work on User\n";
        cout << "2. Work on Admin\n";
        cout << "3. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: menu_work_on_users(); break;
            case 2: menu_work_on_admins(); break;
            case 3: return;
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
            case 2: Update(); break;
            case 3: Delete(); break;
            case 4: search(); break;
            case 5: display(); break;
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
            case 1: cout << "Creating admin...\n"; break;
            case 2: cout << "Updating admin...\n"; break;
            case 3: cout << "Deleting admin...\n"; break;
            case 4: cout << "Searching admin...\n"; break;
            case 5: cout << "Displaying all admins...\n"; break;
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
    //   add_student();
      break;
    }else if(choice == 2){
    //   add_staff();
      break;
    } else if(choice == 3){
    //   add_nonstaff();
      break;
    }else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }

}
// function for search functionaily
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
    //   search_student();
      break;
    } else if(choice == 2){
    //   search_staff();
      break;
    } else if(choice == 3){
    //   search_nonstaff();
      break;
    } else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }
}
// function for display functinally
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
      // display_student();
      break;
    } else if(choice == 2){
      // display_staff();
      break;
    } else if(choice == 3){
      // display_nonstaff();
      break;
    } else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }
}
// function for update functionally
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
      // update_student();
      break;
    } else if(choice == 2){
      // update_staff();
      break;
    } else if(choice == 3){
      // update_nonstaff();
      break;
    } else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }
};
// function for delete functionally
void Delete(){
    int choice;
  while(true){
    cout << "Choose a type of user to delete :" << endl;
    cout << "1. student" << endl;
    cout << "2. staff" << endl;
    cout << "3. nonstaff" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if(choice == 1){
      // display_student();
      break;
    } else if(choice == 2){
      // display_staff();
      break;
    } else if(choice == 3){
      // display_nonstaff();
      break;
    } else if(choice == 4){
      return;
    } else{
      cout << "Invalid choice. Please try again." << endl;
    }
  }

}
