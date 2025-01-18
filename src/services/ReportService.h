#ifndef REPORT_SERVICE_H
#define REPORT_SERVICE_H

#include <iostream>
#include <fstream>
#include "../models/Student.h"
#include "../models/Staff.h"
#include "../models/NonStaff.h"

class ReportService {
public:
    static void generateSystemReport() {
        std::ofstream report("reports/system_report.txt");
        if (!report.is_open()) {
            std::cout << "Error creating report file!\n";
            return;
        }

        report << "=== System Report ===\n\n";
        
        // Count statistics
        int studentCount = countStudents();
        int staffCount = countStaff();
        int nonstaffCount = countNonStaff();
        
        report << "Total Records:\n";
        report << "Students: " << studentCount << "\n";
        report << "Staff: " << staffCount << "\n";
        report << "Non-Staff: " << nonstaffCount << "\n\n";

        report << "Department Statistics:\n";
        generateDepartmentStats(report);

        report.close();
        std::cout << "Report generated successfully!\n";
    }

    static void exportToCSV(const char* type) {
        std::string filename = "reports/";
        filename += type;
        filename += "_data.csv";

        std::ofstream csv(filename);
        if (!csv.is_open()) {
            std::cout << "Error creating CSV file!\n";
            return;
        }

        if (strcmp(type, "students") == 0) {
            csv << "Name,ID,Gender,Department,Year,Phone,PC Name,Serial\n";
            Student* current = student_head;
            while (current) {
                csv << current->name << ","
                    << current->id << ","
                    << current->gender << ","
                    << current->department << ","
                    << current->year << ","
                    << current->phone << ","
                    << current->pcname << ","
                    << current->serial << "\n";
                current = current->next;
            }
        }
        // Similar implementations for staff and non-staff

        csv.close();
        std::cout << "CSV export completed!\n";
    }

private:
    static int countStudents() {
        int count = 0;
        Student* current = student_head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    static int countStaff() {
        int count = 0;
        Staff* current = staff_head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    static int countNonStaff() {
        int count = 0;
        NonStaff* current = nonstaff_head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    static void generateDepartmentStats(std::ofstream& report) {
        // Implementation for department statistics
    }
};

#endif