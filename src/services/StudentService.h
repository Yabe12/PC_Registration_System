#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H

#include "../models/Student.h"
#include "../utils/Validation.h"
#include "../utils/Logger.h"
#include <iostream>
#include <cstring>
#include <map>  // For map functionality
using namespace std;  // This allows us to avoid prefixing std:: for standard library names

class StudentService {
public:
    static void addStudent() {
        Student* newStudent = new Student();
        
        cout << "Enter student name: ";
        cin >> newStudent->name;
        
        cout << "Enter student ID: ";
        cin >> newStudent->id;
        
        do {
            cout << "Enter gender (M/F): ";
            cin >> newStudent->gender;
        } while (!Validation::validateGender(newStudent->gender));
        
        cout << "Enter department: ";
        cin >> newStudent->department;
        
        cout << "Enter year: ";
        cin >> newStudent->year;
        
        do {
            cout << "Enter phone number: ";
            cin >> newStudent->phone;
        } while (!Validation::validatePhoneNumber(newStudent->phone));
        
        cout << "Enter PC name: ";
        cin >> newStudent->pcname;
        
        cout << "Enter serial number: ";
        cin >> newStudent->serial;

        // Link list logic
        if (!student_head) {
            student_head = student_tall = newStudent;
        } else {
            student_tall->next = newStudent;
            newStudent->prev = student_tall;
            student_tall = newStudent;
        }
    }

    static void displayStudents() {
        if (!student_head) {
            cout << "No students registered.\n";
            return;
        }

        Student* current = student_head;
        while (current) {
            cout << "\nName: " << current->name
                 << "\nID: " << current->id
                 << "\nGender: " << current->gender
                 << "\nDepartment: " << current->department
                 << "\nYear: " << current->year
                 << "\nPhone: " << current->phone
                 << "\nPC Name: " << current->pcname
                 << "\nSerial: " << current->serial << "\n";
            current = current->next;
        }
    }

    static void updateStudent() {
        if (!student_head) {
            cout << "No student records to update.\n";
            return;
        }

        char searchId[20];
        cout << "Enter ID of student to update: ";
        cin >> searchId;

        Student* target = findStudentById(searchId);
        if (!target) {
            cout << "Student with ID " << searchId << " not found.\n";
            return;
        }

        int choice;
        do {
            cout << "\nUpdate Menu:"
                 << "\n1. Update Name"
                 << "\n2. Update Gender"
                 << "\n3. Update Department"
                 << "\n4. Update Year"
                 << "\n5. Update Phone"
                 << "\n6. Update PC Name"
                 << "\n7. Update Serial Number"
                 << "\n8. Back"
                 << "\nEnter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    cin >> target->name;
                    break;
                case 2:
                    do {
                        cout << "Enter new gender (M/F): ";
                        cin >> target->gender;
                    } while (!Validation::validateGender(target->gender));
                    break;
                case 3:
                    cout << "Enter new department: ";
                    cin >> target->department;
                    break;
                case 4:
                    cout << "Enter new year: ";
                    cin >> target->year;
                    break;
                case 5:
                    do {
                        cout << "Enter new phone number: ";
                        cin >> target->phone;
                    } while (!Validation::validatePhoneNumber(target->phone));
                    break;
                case 6:
                    cout << "Enter new PC name: ";
                    cin >> target->pcname;
                    break;
                case 7:
                    cout << "Enter new serial number: ";
                    cin >> target->serial;
                    break;
                case 8:
                    cout << "Update completed.\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 8);

        Logger::log("Updated student record with ID: " + string(searchId));
    }

    static void deleteStudent() {
        if (!student_head) {
            cout << "No student records to delete.\n";
            return;
        }

        char searchId[20];
        cout << "Enter ID of student to delete: ";
        cin >> searchId;

        // If deleting first node
        if (strcmp(student_head->id, searchId) == 0) {
            Student* temp = student_head;
            student_head = student_head->next;
            if (student_head) {
                student_head->prev = nullptr;
            } else {
                student_tall = nullptr;
            }
            delete temp;
            cout << "Student record deleted successfully.\n";
            Logger::log("Deleted student record with ID: " + string(searchId));
            return;
        }

        // Search for node to delete
        Student* current = student_head;
        while (current && strcmp(current->id, searchId) != 0) {
            current = current->next;
        }

        if (!current) {
            cout << "Student with ID " << searchId << " not found.\n";
            return;
        }

        // Update links
        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        } else {
            student_tall = current->prev;
        }

        delete current;
        cout << "Student record deleted successfully.\n";
        Logger::log("Deleted student record with ID: " + string(searchId));
    }

    static void searchStudent() {
        if (!student_head) {
            cout << "No student records to search.\n";
            return;
        }

        int searchChoice;
        cout << "\nSearch by:"
             << "\n1. ID"
             << "\n2. Name"
             << "\n3. Department"
             << "\n4. Year"
             << "\nEnter choice: ";
        cin >> searchChoice;

        if (searchChoice == 4) {
            int searchYear;
            cout << "Enter year to search: ";
            cin >> searchYear;
            searchByYear(searchYear);
            return;
        }

        char searchTerm[50];
        cout << "Enter search term: ";
        cin >> searchTerm;

        bool found = false;
        Student* current = student_head;

        while (current) {
            bool match = false;
            switch (searchChoice) {
                case 1:
                    match = (strcmp(current->id, searchTerm) == 0);
                    break;
                case 2:
                    match = (strcmp(current->name, searchTerm) == 0);
                    break;
                case 3:
                    match = (strcmp(current->department, searchTerm) == 0);
                    break;
                default:
                    cout << "Invalid search option!\n";
                    return;
            }

            if (match) {
                found = true;
                displaySingleStudent(current);
            }
            current = current->next;
        }

        if (!found) {
            cout << "No matching records found.\n";
        }
    }

    static void sortStudents(int sortChoice) {
        if (!student_head || !student_head->next) {
            return;
        }

        bool swapped;
        Student *ptr1;
        Student *lptr = nullptr;

        do {
            swapped = false;
            ptr1 = student_head;

            while (ptr1->next != lptr) {
                bool shouldSwap = false;

                switch (sortChoice) {
                    case 1: // Sort by name
                        shouldSwap = (strcmp(ptr1->name, ptr1->next->name) > 0);
                        break;
                    case 2: // Sort by ID
                        shouldSwap = (strcmp(ptr1->id, ptr1->next->id) > 0);
                        break;
                    case 3: // Sort by year
                        shouldSwap = (ptr1->year > ptr1->next->year);
                        break;
                    case 4: // Sort by department
                        shouldSwap = (strcmp(ptr1->department, ptr1->next->department) > 0);
                        break;
                }

                if (shouldSwap) {
                    swapStudents(ptr1, ptr1->next);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    static void generateStudentReport() {
        if (!student_head) {
            cout << "No student records to generate report.\n";
            return;
        }

        cout << "\n=== Student Report ===\n";
        int totalStudents = 0;
        map<string, int> departmentCount;
        map<int, int> yearCount;

        Student* current = student_head;
        while (current) {
            totalStudents++;
            departmentCount[current->department]++;
            yearCount[current->year]++;
            current = current->next;
        }

        cout << "\nTotal Students: " << totalStudents
             << "\n\nDepartment Distribution:";
        for (const auto& dept : departmentCount) {
            cout << "\n" << dept.first << ": " << dept.second;
        }

        cout << "\n\nYear Distribution:";
        for (const auto& year : yearCount) {
            cout << "\nYear " << year.first << ": " << year.second;
        }
        cout << "\n";
    }

private:
    static Student* findStudentById(const char* id) {
        Student* current = student_head;
        while (current) {
            if (strcmp(current->id, id) == 0) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    static void searchByYear(int year) {
        bool found = false;
        Student* current = student_head;
        
        while (current) {
            if (current->year == year) {
                found = true;
                displaySingleStudent(current);
            }
            current = current->next;
        }

        if (!found) {
            cout << "No students found in year " << year << ".\n";
        }
    }

    static void displaySingleStudent(Student* student) {
        cout << "\nName: " << student->name
             << "\nID: " << student->id
             << "\nGender: " << student->gender
             << "\nDepartment: " << student->department
             << "\nYear: " << student->year
             << "\nPhone: " << student->phone
             << "\nPC Name: " << student->pcname
             << "\nSerial: " << student->serial << "\n";
    }

    static void swapStudents(Student* a, Student* b) {
        // Swap data instead of pointers for simplicity
        Student temp;
        strcpy(temp.name, a->name);
        strcpy(temp.id, a->id);
        temp.gender = a->gender;
        strcpy(temp.department, a->department);
        temp.year = a->year;
        temp.phone = a->phone;
        strcpy(temp.pcname, a->pcname);
        strcpy(temp.serial, a->serial);

        strcpy(a->name, b->name);
        strcpy(a->id, b->id);
        a->gender = b->gender;
        strcpy(a->department, b->department);
        a->year = b->year;
        a->phone = b->phone;
        strcpy(a->pcname, b->pcname);
        strcpy(a->serial, b->serial);

        strcpy(b->name, temp.name);
        strcpy(b->id, temp.id);
        b->gender = temp.gender;
        strcpy(b->department, temp.department);
        b->year = temp.year;
        b->phone = temp.phone;
        strcpy(b->pcname, temp.pcname);
        strcpy(b->serial, temp.serial);
    }
};

#endif
