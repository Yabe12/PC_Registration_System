#ifndef NON_STAFF_H
#define NON_STAFF_H

struct nonstaff {
    char name[50];
    char id[20];
    char gender[10];
    long long phone;
    char pcname[50];
    char serial[50];
    nonstaff* next;
    nonstaff* prev;
};


extern nonstaff* nonstaff_head;
extern nonstaff* nonstaff_tall;

#endif 
