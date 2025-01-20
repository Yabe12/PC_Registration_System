#ifndef STAFF_H
#define STAFF_H
#include <cstring>
#include <string>
using namespace std;
struct Staff {
    char name[50];
    char id[20];
    char gender;
    char department[50];
    char position[50];
    long long phone;
    char pcname[50];
    char serial[50];
    Staff* next;
    Staff* prev;
};

extern Staff* staff_head;
extern Staff* staff_tall;

#endif 