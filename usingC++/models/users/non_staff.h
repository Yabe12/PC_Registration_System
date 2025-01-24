<<<<<<< HEAD
#include <iostream>
using namespace std;
int main () {
    struct nonstaff {
=======
#ifndef NON_STAFF_H
#define NON_STAFF_H

struct nonstaff {
>>>>>>> feature/modular_structure
    char name[50];
    char id[20];
    char gender;
    long long phone;
    char pcname[50];
    char serial[50];
<<<<<<< HEAD
    nonstaff *next;
    nonstaff *prev;
};
nonstaff *nonstaff_head = NULL, *nonstaff_tall = NULL;

}

=======
    nonstaff* next;
    nonstaff* prev;
};

// Global pointers for the linked list
extern nonstaff* nonstaff_head;
extern nonstaff* nonstaff_tall;

#endif // NON_STAFF_H
>>>>>>> feature/modular_structure
