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
    char model[50];
    student *next;
    student *prev;
};

struct staff {
    char name[50];
    char id[20];
    char gender;
    char role[50];
    char typeofpc[50];
    long long phone;
    char pcname[50];
    char serial[50];
    char model[50];
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
    char model[50];
    nonstaff *next;
    nonstaff *prev;
};

// Global linked list heads
student *student_head = nullptr;
staff *staff_head = nullptr;
nonstaff *nonstaff_head = nullptr;

// 🔹 Add Student
void add_student() {
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
    student_head = new_student;
}

// 🔹 Add Staff
void add_staff() {
    staff *new_staff = new staff;
    cout << "Enter staff's name: ";
    cin.ignore();
    cin.getline(new_staff->name, 50);
    cout << "Enter staff's ID: ";
    cin.getline(new_staff->id, 20);
    cout << "Enter staff's gender (M/F): ";
    cin >> new_staff->gender;
    cin.ignore();
    cout << "Enter staff's role: ";
    cin.getline(new_staff->role, 50);
    cout << "Enter staff's type of PC (laptop/desktop): ";
    cin.getline(new_staff->typeofpc, 50);
    cout << "Enter staff's phone number: ";
    cin >> new_staff->phone;
    cin.ignore();
    cout << "Enter staff's computer name: ";
    cin.getline(new_staff->pcname, 50);
    cout << "Enter staff's computer serial number: ";
    cin.getline(new_staff->serial, 50);
    cout << "Enter staff's computer model: ";
    cin.getline(new_staff->model, 50);

    new_staff->next = staff_head;
    staff_head = new_staff;
}

// 🔹 Add Nonstaff
void add_nonstaff() {
    nonstaff *new_nonstaff = new nonstaff;
    cout << "Enter nonstaff's name: ";
    cin.ignore();
    cin.getline(new_nonstaff->name, 50);
    cout << "Enter nonstaff's ID: ";
    cin.getline(new_nonstaff->id, 20);
    cout << "Enter nonstaff's gender (M/F): ";
    cin >> new_nonstaff->gender;
    cin.ignore();
    cout << "Enter nonstaff's phone number: ";
    cin >> new_nonstaff->phone;
    cin.ignore();
    cout << "Enter nonstaff's computer name: ";
    cin.getline(new_nonstaff->pcname, 50);
    cout << "Enter nonstaff's computer serial number: ";
    cin.getline(new_nonstaff->serial, 50);
    cout << "Enter nonstaff's computer model: ";
    cin.getline(new_nonstaff->model, 50);

    new_nonstaff->next = nonstaff_head;
    nonstaff_head = new_nonstaff;
}

// 🔹 Add User Menu
void add_user() {
    int choice;
    while (true) {
        cout << "\nChoose user type to add:\n";
        cout << "1. Student\n";
        cout << "2. Staff\n";
        cout << "3. Nonstaff\n";
        cout << "4. Back to Main Menu\n";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: add_student(); break;
            case 2: add_staff(); break;
            case 3: add_nonstaff(); break;
            case 4: return;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}

// 🔹 Delete Student
void delete_student() {
    char id[20];
    cout << "Enter student ID to delete: ";
    cin.ignore();
    cin.getline(id, 20);

    student *temp = student_head, *prev = nullptr;
    while (temp) {
        if (strcmp(temp->id, id) == 0) {
            if (prev) prev->next = temp->next;
            else student_head = temp->next;
            delete temp;
            cout << "Student deleted successfully!\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Student not found!\n";
}

// 🔹 Delete Staff
void delete_staff() {
    char name[50];
    cout << "Enter staff name to delete: ";
    cin.ignore();
    cin.getline(name, 50);

    staff *temp = staff_head, *prev = nullptr;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            if (prev) prev->next = temp->next;
            else staff_head = temp->next;
            delete temp;
            cout << "Staff deleted successfully!\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Staff not found!\n";
}

// 🔹 Delete User Menu
void delete_user() {
    int choice;
    while (true) {
        cout << "\nChoose user type to delete:\n";
        cout << "1. Student\n";
        cout << "2. Staff\n";
        cout << "3. Nonstaff\n";
        cout << "4. Back to Main Menu\n";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: delete_student(); break;
            case 2: delete_staff(); break;
            case 3: cout << "Delete nonstaff function not implemented yet!\n"; break;
            case 4: return;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}

// 🔹 Main Menu
int main() {
    int choice;
    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Add User\n";
        cout << "2. Delete User\n";
        cout << "3. Exit\n";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: add_user(); break;
            case 2: delete_user(); break;
            case 3: return 0;
            default: cout << "Invalid choice, try again.\n";
        }
    }
}
