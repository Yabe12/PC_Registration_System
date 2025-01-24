#ifndef NON_STAFF_SERVICE_H
#define NON_STAFF_SERVICE_H

#include <iostream>
#include <cstring>
#include "../../models/users/non_staff.h"

using namespace std;

// Declare global pointers for the linked list
extern nonstaff* nonstaff_head;
extern nonstaff* nonstaff_tall;

// Function declarations

void sort_nonstaff();
void add_nonstaff();
void search_nonstaff();
void display_nonstaff();
void update_nonstaff();
void delete_nonstaff();

#endif // NON_STAFF_SERVICE_H