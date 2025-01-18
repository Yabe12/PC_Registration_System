#ifndef NONSTAFF_H
#define NONSTAFF_H

struct NonStaff {
    char name[50];
    char id[20];
    char gender;
    char department[50];
    char position[50];
    long long phone;
    char pcname[50];
    char serial[50];
    NonStaff* next;
    NonStaff* prev;
};

extern NonStaff* nonstaff_head;
extern NonStaff* nonstaff_tall;

#endif 