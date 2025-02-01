#ifndef STUDENT_H
#define STUDENT_H

struct student {
    char name[50];
    char id[20];
    char gender[10];
    char department[50];
    long long phone;
    char pcname[50];
    char serial[50];
    student* next;
    student* prev;

};
    extern student* student_head;
extern student* student_tall;
#endif 
