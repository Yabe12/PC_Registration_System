#include <iostream>
#include <cstring> // For C string operations like strcpy
using namespace std;

// Define structs for student, staff, and nonstaff
struct student {
    char name[20];
    char id;
    char gender;
    char department;
    int year;
    int phone;
    char pcname;
    char serial;
    char model;
    struct student *next;
    struct student *priv;
};

struct staff {
    char name[20];
    char id;
    char gender;
    char role;
    char typeofpc;
    int phone;
    char pcname;
    char serial;
    char model;
    struct staff *next;
    struct staff *priv;
};

struct nonstaff {
    char name[20];
    char id;
    char gender;
    int phone;
    char pcname;
    char serial;
    char model;
    struct nonstaff *next;
    struct nonstaff *priv;
};

// Global pointers for linked lists
student *student_head = nullptr, *student_tail = nullptr;
staff *staff_head = nullptr, *staff_tail = nullptr;
nonstaff *nonstaff_head = nullptr, *nonstaff_tail = nullptr;

int main() {
    int choice;
    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Add staff" << endl;
        cout << "3. Add non-staff" << endl;
        cout << "4. Search student by ID" << endl;
        cout << "5. Search staff by ID" << endl;
        cout << "6. Search non-staff by ID" << endl;
        cout << "7. Delete student by ID" << endl;
        cout << "8. Delete staff by ID" << endl;
        cout << "9. Delete non-staff by ID" << endl;
        cout << "10. Update student information" << endl;
        cout << "11. Update staff information" << endl;
        cout << "12. Update non-staff information" << endl;
        cout << "13. Exit" << endl;
        
        cin >> choice;

        switch (choice) {
            case 1:
                // add_student();
                break;
            case 2:
                // add_staff();
                break;
            case 3:
                // add_nonstaff();
                break;
            case 4:
                // search_student_by_id();
                break;
            case 5:
                // search_staff_by_id();
                break;
            case 6:
                // search_nonstaff_by_id();
                break;
            case 7:
                // delete_student_by_id();
                break;
            case 8:
                // delete_staff_by_id();
                break;
            case 9:
                // delete_nonstaff_by_id();
                break;
            case 10:
                // update_student_info();
                break;
            case 11:
                // update_staff_info();
                break;
            case 12:
                // update_nonstaff_info();
                break;
            case 13:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
                break; // Ensure to break after default case
        }
    }

    return 0;
}
