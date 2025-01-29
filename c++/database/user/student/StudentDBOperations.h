#ifndef STUDENTDBOPERATIONS_H
#define STUDENTDBOPERATIONS_H

#include "student.h"

// Function prototypes for student database operations
void add_student_to_db(const char* name, const char* id, const char* gender, const char* department,
                       long long phone, const char* pcname, const char* serial);
void update_student_in_db(const char* id, const char* name, const char* gender, const char* department,
                          long long phone, const char* pcname, const char* serial);
void delete_student_from_db(const char* id);
void search_student_in_db(const char* id);
void display_all_students_from_db();

#endif // STUDENTDBOPERATIONS_H
