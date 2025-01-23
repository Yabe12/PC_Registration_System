#ifndef ADMIN_SERVICE_H
#define ADMIN_SERVICE_H

#include "../models/admin/admin.h"

// Declare global pointers for the linked list
extern Admin* admin_head;
extern Admin* admin_tall;

// Function declarations
void add_admin();
void update_admin();
void search_admin();
void delete_admin();
void display_admin();

#endif // ADMIN_SERVICE_H