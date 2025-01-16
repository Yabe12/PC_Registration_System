#include <iostream>
#include <cstring>


using namespace std;

struct student {
    char name[50];
    char id[20];
    char gender;
    char department[50];
    int year;
    long long phone;
    char pcname[50];
    char serial[50];
    char model[50]; //to be removed
    student *next;
    student *prev;

struct student {
    char name[50];
    char id[20];
    char gender;
    char department[50];
    int year;
    long long phone;
    char pcname[50];
    char serial[50];
    char model[50]; //to be removed
    student *next;
    student *prev;
};

struct staff {
    char name[50];
    char id[20];
    char gender;
    char role[50]; //change to job
    char typeofpc[50]; //to be removed
    long long phone;
    char pcname[50];
    char serial[50];
    char model[50]; //to be removed
    staff *next;
    staff *prev;
struct staff {
    char name[50];
    char id[20];
    char gender;
    char role[50]; //change to job
    char typeofpc[50]; //to be removed
    long long phone;
    char pcname[50];
    char serial[50];
    char model[50]; //to be removed
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
    char model[50]; //to be removed
    nonstaff *next;
    nonstaff *prev;
struct nonstaff {
    char name[50];
    char id[20];
    char gender;
    long long phone;
    char pcname[50];
    char serial[50];
    char model[50]; //to be removed
    nonstaff *next;
    nonstaff *prev;
};

// Global linked list heads
student *student_head = nullptr;
staff *staff_head = nullptr;
nonstaff *nonstaff_head = nullptr;

// 🔹 Add User
void add_user(int type) {
    if (type == 1) {  // Student
        student *new_student = new student;
        cout << "Enter student's name: ";
        cin.ignore();
        cin.getline(new_student->name, 50);
        cout << "Enter student's ID: ";
        cin.getline(new_student->id, 20);
        cout << "Enter student's gender (M/F): ";
        cin >> new_student->gender;
        cin.ignore();
        cout << "Enter student's department: ";
        cin.getline(new_student->department, 50);
        cout << "Enter student's year: ";
        cin >> new_student->year;
        cout << "Enter student's phone number: ";
        cin >> new_student->phone;
        cin.ignore();
        cout << "Enter student's computer name: ";
        cin.getline(new_student->pcname, 50);
        cout << "Enter student's computer serial number: ";
        cin.getline(new_student->serial, 50);
        cout << "Enter student's computer model: ";
        cin.getline(new_student->model, 50);

        new_student->next = student_head;
        if (student_head) student_head->prev = new_student;
        student_head = new_student;
    }
    // Similar implementations for staff & nonstaff (Use same pattern)
}

// 🔹 Search User
void search_user(int type) {
    char query[50];
    cout << "Enter search keyword (ID for student, Name for others): ";
    cin.ignore();
    cin.getline(query, 50);

    if (type == 1) {  // Student search by ID
        student *temp = student_head;
        while (temp) {
            if (strcmp(temp->id, query) == 0) {
                cout << "Student Found: " << temp->name << " | ID: " << temp->id << endl;
                return;
            }
            temp = temp->next;
        }
    }
    // Implement Student search by name 

    // Implement similar logic for staff & nonstaff using name
}

// 🔹 Update User
void update_user(int type) {
    char query[50];
    cout << "Enter the ID or Name of the user to update: ";
    cin.ignore();
    cin.getline(query, 50);

    if (type == 1) {  // Student update by ID
        student *temp = student_head;
        while (temp) {
            if (strcmp(temp->id, query) == 0) {
                cout << "Enter new name: ";
                cin.getline(temp->name, 50);
                cout << "Update successful!\n";
                return;
            }
            temp = temp->next;
        }
    }
    // Implement Student search and update by name 

    // Implement similar logic for staff & nonstaff
}

// 🔹 Delete User
void delete_user(int type) {
    char query[50];
    cout << "Enter the ID or Name of the user to delete: ";
    cin.ignore();
    cin.getline(query, 50);

    if (type == 1) {  // Student delete by ID
        student *temp = student_head, *prev = nullptr;
        while (temp) {
            if (strcmp(temp->id, query) == 0) {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == student_head) student_head = temp->next;
                delete temp;
                cout << "Student deleted successfully!\n";
                return;
            }
            temp = temp->next;
        }
    }
    // Implement Student search and delete by name 

    // Implement similar logic for staff & nonstaff
}

// 🔹 Main Menu
int main() {
    int choice;
    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Add User\n";
        cout << "2. Search User\n";
        cout << "3. Update User\n";
        cout << "4. Delete User\n";
        //add display all users menu
        cout << "5. Exit\n";
        cin >> choice;

        int userType;
        if (choice != 5) {
            cout << "Select user type:\n1. Student\n2. Staff\n3. Nonstaff\n";
            cin >> userType;
        }

        switch (choice) {
            case 1: add_user(userType); break;
            case 2: search_user(userType); break;
            case 3: update_user(userType); break;
            case 4: delete_user(userType); break;
            case 5: return 0;
            default: cout << "Invalid choice, try again.\n";
        }
    }
}

/*

- First create (just put in the code) SuperAdmin password and username and that SuperAdmin can create other Admins with username and password,
- and those admins can create,update,search but can't delete user(student, staff, non-staff) data, only the super admin can do that,
- and we our system will have only one superAdmin and as much as Admin and user ,
- and the admin or superAdmin have to login (Authenticated) first befor the can use the system
- super admin can do view(by search and all at once),create,update,delete for both user and Admin 

*/

/*

- First create (just put in the code) SuperAdmin password and username and that SuperAdmin can create other Admins with username and password,
- and those admins can create,update,search but can't delete user(student, staff, non-staff) data, only the super admin can do that,
- and we our system will have only one superAdmin and as much as Admin and user ,
- and the admin or superAdmin have to login (Authenticated) first befor the can use the system
- super admin can do view(by search and all at once),create,update,delete for both user and Admin 
- show the the searched result and let the SuperAdmin to confirm (go forward or search again ) befor he proceed to delete during deletion of user or admin


*/  