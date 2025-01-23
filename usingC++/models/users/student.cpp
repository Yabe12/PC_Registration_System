#include <iostream>
using namespace std;

// Define the structure for a student
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

// Declare global pointers for the linked list
student* student_head = NULL;
student* student_tall = NULL;
