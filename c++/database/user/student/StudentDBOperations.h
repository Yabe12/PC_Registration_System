#ifndef STUDENT_DB_OPERATIONS_H
#define STUDENT_DB_OPERATIONS_H

#include <string>

// Function to add a student to the database
void add_student_to_db(const std::string& name, const std::string& student_id, const std::string& gender, 
                        const std::string& department, long long phone, const std::string& pcname, 
                        const std::string& serial);


// Function to search for a student in the database
void search_student_in_db( const std::string student_id) ;

void update_student_in_db(const std::string student_id, const std::string& name, const std::string& gender, 
                          const std::string& department, long long phone, const std::string& pcname, 
                          const std::string& serial) ;

// Function to delete a student from the database
void delete_student_from_db( const std::string student_id) ;

// Function to display all students from the database
void display_all_students_from_db();

#endif // STUDENT_DB_OPERATIONS_H
