#ifndef NONSTAFFDBOPERATIONS_H
#define NONSTAFFDBOPERATIONS_H

#include <string>

void add_nonstaff_to_db(const std::string& name, const std::string& id, const std::string& gender, long long phone, const std::string& pcname, const std::string& serial);
void update_nonstaff_in_db(const std::string& id, const std::string& name, const std::string& gender, long long phone, const std::string& pcname, const std::string& serial);
void delete_nonstaff_from_db(const std::string& id);
void search_nonstaff_in_db(const std::string& name);
void display_all_nonstaff_from_db();
void sort_nonstaff_from_db();

#endif