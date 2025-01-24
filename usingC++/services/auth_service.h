#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

#include <iostream>
#include <cstring>
using namespace std;

// Declare global variables
extern bool isSuperAdmin;
extern bool isAuthenticated;

// Declare super admin credentials
extern const char superAdminUsername[];
extern const char superAdminPassword[];

// Declare your Admin structure or class if it's not already defined
struct Admin {
    char username[50];
    char password[50];
    Admin* next;
};

// Global pointers for the linked list
extern Admin* admin_head;

// Authentication Function
bool login(bool isSuper);

#endif // AUTH_SERVICE_H

