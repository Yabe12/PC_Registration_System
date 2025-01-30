#ifndef STUDENT_DB_OPERATIONS_H
#define STUDENT_DB_OPERATIONS_H

#include <string>

void add_student_to_db(const std::string& name, const std::string& id, const std::string& gender, 
                       const std::string& department, long long phone, const std::string& pcname, 
                       const std::string& serial);

void search_student_in_db(const std::string& id);
void update_student_in_db(const std::string& id, const std::string& name, const std::string& gender, 
                          const std::string& department, long long phone, const std::string& pcname, 
                          const std::string& serial);

void delete_student_from_db(const std::string& id);
void display_all_students_from_db();
#endif
