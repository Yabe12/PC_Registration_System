#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H

#include <iostream>
#include <cstring>
#include "../../models/users/student.h"  // Ensure this path is correct

using namespace std;


extern student* student_head;
extern student* student_tall;

void sort_student();
void add_student();
void update_student();
void search_student();
void display_students();
void delete_student();

#endif
