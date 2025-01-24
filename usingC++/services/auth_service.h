#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

#include <iostream>
#include "../models/admin/admin.h"
#include <cstring>
using namespace std;

// Declare global pointers for the linked list
extern Admin* admin_head;
extern Admin* admin_tall;

// Declare global variables
extern bool isSuperAdmin;
extern bool isAuthenticated;

// Declare super admin credentials
extern const char superAdminUsername[];
extern const char superAdminPassword[];

// Authentication Function
bool login(bool isSuper);

#endif // AUTH_SERVICE_H

