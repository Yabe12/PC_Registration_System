#ifndef STAFF_H
#define STAFF_H

struct staff {
    char name[50];
    char id[20];
    char gender;
    char job[50];
    long long phone;
    char typeofpc[20];
    char pcname[50];
    char serial[50];
    staff *next;
    staff *prev;
};

// Global pointers for the linked list
extern staff* staff_head;
extern staff* staff_tall;

#endif // STAFF_H
