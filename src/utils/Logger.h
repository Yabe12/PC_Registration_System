#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;

class Logger {
public:
    static void log(const std::string& message, const std::string& level = "INFO") {
        std::ofstream logFile("logs/system.log", std::ios::app);
        if (logFile.is_open()) {
            time_t now = time(0);
            char* dt = ctime(&now);
            dt[strlen(dt) - 1] = '\0'; // Remove newline
            
            logFile << "[" << dt << "] [" << level << "] " << message << "\n";
            logFile.close();
        }
    }

    static void logError(const std::string& message) {
        log(message, "ERROR");
    }

    static void logWarning(const std::string& message) {
        log(message, "WARNING");
    }

    static void clearLogs() {
        std::ofstream logFile("logs/system.log", std::ios::trunc);
        logFile.close();
    }
};

#endif 