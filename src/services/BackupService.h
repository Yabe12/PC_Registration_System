#ifndef BACKUP_SERVICE_H
#define BACKUP_SERVICE_H

#include <iostream>
#include <fstream>
#include <ctime>
#include "../utils/FileHandler.h"
#include "../utils/Logger.h"

class BackupService {
public:
    static void createBackup() {
        std::string backupDir = "backups/";
        std::string timestamp = getCurrentTimestamp();
        std::string backupPath = backupDir + "backup_" + timestamp;

        // Create backup directory
        system(("mkdir -p " + backupPath).c_str());

        // Backup all data files
        backupFile("data/students.dat", backupPath + "/students.dat");
        backupFile("data/staff.dat", backupPath + "/staff.dat");
        backupFile("data/nonstaff.dat", backupPath + "/nonstaff.dat");
        backupFile("data/admins.dat", backupPath + "/admins.dat");

        Logger::log("Backup created successfully: " + backupPath);
        std::cout << "Backup created successfully!\n";
    }

    static void restoreBackup(const std::string& backupPath) {
        if (!validateBackup(backupPath)) {
            std::cout << "Invalid backup directory!\n";
            return;
        }

        // Restore all data files
        restoreFile(backupPath + "/students.dat", "data/students.dat");
        restoreFile(backupPath + "/staff.dat", "data/staff.dat");
        restoreFile(backupPath + "/nonstaff.dat", "data/nonstaff.dat");
        restoreFile(backupPath + "/admins.dat", "data/admins.dat");

        // Reload data
        FileHandler::loadStudents();
        FileHandler::loadStaff();
        FileHandler::loadNonStaff();
        FileHandler::loadAdmins();

        Logger::log("Backup restored from: " + backupPath);
        std::cout << "Backup restored successfully!\n";
    }

private:
    static std::string getCurrentTimestamp() {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &tstruct);
        return std::string(buf);
    }

    static void backupFile(const std::string& source, const std::string& destination) {
        std::ifstream src(source, std::ios::binary);
        std::ofstream dst(destination, std::ios::binary);
        dst << src.rdbuf();
    }

    static void restoreFile(const std::string& source, const std::string& destination) {
        std::ifstream src(source, std::ios::binary);
        std::ofstream dst(destination, std::ios::binary);
        dst << src.rdbuf();
    }

    static bool validateBackup(const std::string& backupPath) {
        // Implement backup validation logic
        return true;
    }
};

#endif 