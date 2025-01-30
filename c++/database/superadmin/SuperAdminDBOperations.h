#ifndef SUPERADMIN_DB_OPERATIONS_H
#define SUPERADMIN_DB_OPERATIONS_H

#include <string>

bool checkSuperAdminCredentials(const std::string& username, const std::string& password);

#endif