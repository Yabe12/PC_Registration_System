#ifndef ADMIN_H
#define ADMIN_H
#include <cstring>
#include <string>
using namespace std;
struct Admin {
    char username[50];
    char password[50];
    Admin* next;
};

extern Admin* admin_head;
extern Admin* admin_tall;

#endif