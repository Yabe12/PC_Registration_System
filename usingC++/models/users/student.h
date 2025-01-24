#ifndef STUDENT_H
#define STUDENT_H

struct student {
    char name[50];
    char id[20];
    char gender;
    char department[50];
    int year;
    long long phone;
    char pcname[50];
    char serial[50];
    student* next;
    student* prev;
};

#endif // STUDENT_H
