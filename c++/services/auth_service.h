#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H
#include <iostream>
#include "../models/admin/admin.h"
#include <cstring>
using namespace std;


extern Admin* admin_head;
extern Admin* admin_tall;

bool login(bool isSuper);



#endif 