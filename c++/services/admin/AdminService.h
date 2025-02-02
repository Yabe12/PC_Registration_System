#ifndef ADMIN_SERVICE_H
#define ADMIN_SERVICE_H

#include "../../models/admin/admin.h"


extern Admin* admin_head;
extern Admin* admin_tall;

void add_admin();
void update_admin();
void search_admin();
void delete_admin();
void display_admin();

#endif 