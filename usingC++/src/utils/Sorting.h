#ifndef SORTING_H
#define SORTING_H

#include "../models/Student.h"
#include "../models/Staff.h"
#include "../models/NonStaff.h"
#include <cstring>
using namespace std;

class Sorting {
public:
    static void sortStudentsByName() {
        if (!student_head || !student_head->next) return;
        
        bool swapped;
        Student* ptr1;
        Student* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = student_head;

            while (ptr1->next != lptr) {
                if (strcmp(ptr1->name, ptr1->next->name) > 0) {
                    swapStudents(ptr1, ptr1->next);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    static void sortStaffByName() {
        // Similar implementation for staff
    }

    static void sortNonStaffByName() {
        // Similar implementation for non-staff
    }

private:
    static void swapStudents(Student* a, Student* b) {
        // Implement swap logic for doubly linked list
    }
};

#endif 