#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
#include <iostream>
#include "../models/Student.h"
#include "../models/Staff.h"
#include "../models/NonStaff.h"
#include "../models/Admin.h"
#include <cstring>
using namespace std;

class FileHandler {
public:
    static void saveStudents() {
        std::ofstream file("data/students.dat", std::ios::binary);
        if (!file) {
            std::cout << "Error opening file for writing!\n";
            return;
        }

        Student* current = student_head;
        while (current) {
            file.write(reinterpret_cast<char*>(current), sizeof(Student));
            current = current->next;
        }
        file.close();
    }

    static void loadStudents() {
        std::ifstream file("data/students.dat", std::ios::binary);
        if (!file) {
            std::cout << "No existing student data found.\n";
            return;
        }

        // Clear existing list
        while (student_head) {
            Student* temp = student_head;
            student_head = student_head->next;
            delete temp;
        }
        student_tall = nullptr;

        Student tempStudent;
        while (file.read(reinterpret_cast<char*>(&tempStudent), sizeof(Student))) {
            Student* newStudent = new Student();
            *newStudent = tempStudent;
            newStudent->next = nullptr;
            newStudent->prev = nullptr;

            if (!student_head) {
                student_head = student_tall = newStudent;
            } else {
                student_tall->next = newStudent;
                newStudent->prev = student_tall;
                student_tall = newStudent;
            }
        }
        file.close();
    }

    // Similar methods for Staff, NonStaff, and Admin data
};

#endif 