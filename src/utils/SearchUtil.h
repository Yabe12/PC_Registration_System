#ifndef SEARCH_UTIL_H
#define SEARCH_UTIL_H

#include "../models/Student.h"
#include "../models/Staff.h"
#include "../models/NonStaff.h"
#include <cstring>
using namespace std;

class SearchUtil {
public:
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

    static Staff* findStaffById(const char* id) {
        Staff* current = staff_head;
        while (current) {
            if (strcmp(current->id, id) == 0) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    static NonStaff* findNonStaffById(const char* id) {
        NonStaff* current = nonstaff_head;
        while (current) {
            if (strcmp(current->id, id) == 0) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    static bool isSerialNumberUnique(const char* serial) {
        // Check in students
        Student* student = student_head;
        while (student) {
            if (strcmp(student->serial, serial) == 0) return false;
            student = student->next;
        }

        // Check in staff
        Staff* staff = staff_head;
        while (staff) {
            if (strcmp(staff->serial, serial) == 0) return false;
            staff = staff->next;
        }

        // Check in non-staff
        NonStaff* nonstaff = nonstaff_head;
        while (nonstaff) {
            if (strcmp(nonstaff->serial, serial) == 0) return false;
            nonstaff = nonstaff->next;
        }

        return true;
    }
};

#endif cu