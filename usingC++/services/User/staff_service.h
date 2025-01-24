#ifndef STAFF_SERVICE_H
#define STAFF_SERVICE_H

#include <iostream>
#include <cstring>
#include "../../models/users/staff.h"

using namespace std;

// Declare global pointers for the linked list
extern staff* staff_head;
extern staff* staff_tall;

// Function declarations
void sort_staff();
void add_staff();
void search_staff();
void display_staff();
void update_staff();
void delete_staff();

#endif // STAFF_SERVICE_H