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
