#ifndef STUDENT_DB_OPERATIONS_H
#define STUDENT_DB_OPERATIONS_H

#include <string>

bool add_student_to_db(const std::string& name, const std::string& student_id, const std::string& gender,
                       const std::string& department, long long phone, const std::string& pcname,
                       const std::string& serial);

bool update_student_in_db(const std::string& student_id, const std::string& name, const std::string& gender,
                          const std::string& department, long long phone, const std::string& pcname,
                          const std::string& serial);

void search_student_in_db(const std::string& student_id);

void delete_student_from_db(const std::string& student_id);

void display_all_students_from_db();

#endif // STUDENT_DB_OPERATIONS_H
