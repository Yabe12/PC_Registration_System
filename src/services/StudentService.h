#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H

#include "../models/Student.h"
#include "../utils/Validation.h"
#include <iostream>

class StudentService {
public:
    static void addStudent() {
        Student* newStudent = new Student();
        
        std::cout << "Enter student name: ";
        std::cin >> newStudent->name;
        
        std::cout << "Enter student ID: ";
        std::cin >> newStudent->id;
        
        do {
            std::cout << "Enter gender (M/F): ";
            std::cin >> newStudent->gender;
        } while (!Validation::validateGender(newStudent->gender));
        
        std::cout << "Enter department: ";
        std::cin >> newStudent->department;
        
        std::cout << "Enter year: ";
        std::cin >> newStudent->year;
        
        do {
            std::cout << "Enter phone number: ";
            std::cin >> newStudent->phone;
        } while (!Validation::validatePhoneNumber(newStudent->phone));
        
        std::cout << "Enter PC name: ";
        std::cin >> newStudent->pcname;
        
        std::cout << "Enter serial number: ";
        std::cin >> newStudent->serial;

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
            std::cout << "No students registered.\n";
            return;
        }

        Student* current = student_head;
        while (current) {
            std::cout << "\nName: " << current->name
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

    // Add other student-related methods like update, delete, search, etc.
};

#endif 