#ifndef STAFF_SERVICE_H
#define STAFF_SERVICE_H

#include "../models/Staff.h"
#include <vector>

class StaffService {
public:
    static void addStaff();
    static void displayStaff();
private:
    static std::vector<Staff> staffList;
};

#endif // STAFF_SERVICE_H 