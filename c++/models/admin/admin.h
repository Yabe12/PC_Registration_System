#ifndef ADMIN_H
#define ADMIN_H

struct Admin {
    char username[50];
    char password[50];
    Admin* next;
};


extern Admin* admin_head;
extern Admin* admin_tall;

#endif 
