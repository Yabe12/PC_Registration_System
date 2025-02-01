#ifndef STAFF_DB_OPERATIONS_H
#define STAFF_DB_OPERATIONS_H

#include <string>

// StaffDBOperations.h
void add_staff_to_db(const std::string& name, const std::string& id, const std::string& gender,
                     const std::string& job, long long phone, const std::string& typeofpc,
                     const std::string& pcname, const std::string& serial);

void update_staff_in_db(const std::string& id, const std::string& name, const std::string& gender,
                        const std::string& job, long long phone, const std::string& typeofpc,
                        const std::string& pcname, const std::string& serial);

void delete_staff_from_db(const std::string& id);
void display_all_staff_from_db();
void search_staff_in_name(const std::string& name);

#endif // STAFF_DB_OPERATIONS_H
