#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    char name[50];
    char id[20];
    char gender;
    char department[50];
    int year;
    long long phone;
    char pcname[50];
    char serial[50];
    Student* next;
    Student* prev;
};

extern Student* student_head;
extern Student* student_tall;

#endif 