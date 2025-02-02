#ifndef ADMINDATABASEOPERATIONS_H
#define ADMINDATABASEOPERATIONS_H

#include <string>
#include <libpq-fe.h>

bool add_admin_to_db(const std::string& username, const std::string& password);
bool  update_admin_in_db(const std::string& username, const std::string& password);
bool delete_admin_from_db(const std::string& username);
void search_admin_in_db(const std::string& username);
void display_admin();
bool check_admin_credentials(const std::string& username, const std::string& password);
#endif 
