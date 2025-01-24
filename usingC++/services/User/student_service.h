#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H

#include <iostream>
#include <cstring>
#include "../../models/users/student.h"

using namespace std;

// Declare global pointers for the linked list
extern student* student_head;
extern student* student_tall;

// Function declarations
void sort_student();
void add_student();
void update_student();
void search_student();
void display_students();
void delete_student();

#endif // STUDENT_SERVICE_H