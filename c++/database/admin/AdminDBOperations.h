#ifndef ADMINDATABASEOPERATIONS_H
#define ADMINDATABASEOPERATIONS_H

#include <string>
#include <libpq-fe.h>

// Database operations for admin management
void add_admin_to_db(const std::string& username, const std::string& password);
void update_admin_in_db(const std::string& username, const std::string& password);
void delete_admin_from_db(const std::string& username);
void search_admin_in_db(const std::string& username);
bool check_admin_credentials(const std::string& username, const std::string& password);
#endif // ADMINDATABASEOPERATIONS_H
