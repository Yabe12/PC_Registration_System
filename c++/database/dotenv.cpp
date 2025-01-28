// #include <fstream>
// #include <sstream>
// #include <string>
// #include <unordered_map>
// #include <iostream>
// #include <cstdlib>

// // Function to load the .env file and store key-value pairs
// std::unordered_map<std::string, std::string> loadEnvFile(const std::string& filepath) {
//     std::unordered_map<std::string, std::string> envVars;
//     std::ifstream envFile(filepath);
//     if (!envFile.is_open()) {
//         std::cerr << "Error: Unable to open .env file at " << filepath << std::endl;
//         return envVars;
//     }

//     std::string line;
//     while (std::getline(envFile, line)) {
//         // Ignore comments and empty lines
//         if (line.empty() || line[0] == '#') continue;

//         // Find the position of the '=' character
//         size_t delimiterPos = line.find('=');
//         if (delimiterPos == std::string::npos) continue; // Skip invalid lines

//         // Extract the key and value
//         std::string key = line.substr(0, delimiterPos);
//         std::string value = line.substr(delimiterPos + 1);

//         // Remove surrounding whitespace
//         key.erase(0, key.find_first_not_of(" \t"));
//         key.erase(key.find_last_not_of(" \t") + 1);
//         value.erase(0, value.find_first_not_of(" \t"));
//         value.erase(value.find_last_not_of(" \t") + 1);

//         // Store in map or set as an environment variable
//         envVars[key] = value;
//     }

//     envFile.close();
//     return envVars;
// }

// int main() {
//     // Load the .env file
//     const std::string envPath = ".env";
//     auto envVars = loadEnvFile(envPath);

//     // Access variables
//     std::string dbName = envVars["DB_NAME"];
//     std::string dbUser = envVars["DB_USER"];
//     std::string dbPassword = envVars["DB_PASSWORD"];
//     std::string dbHost = envVars["DB_HOST"];
//     std::string dbPort = envVars["DB_PORT"];

//     // Print database details (For demonstration purposes, avoid printing passwords in production)
//     std::cout << "Database Name: " << dbName << std::endl;
//     std::cout << "Database User: " << dbUser << std::endl;
//     std::cout << "Database Password: " << dbPassword << std::endl;
//     std::cout << "Database Host: " << dbHost << std::endl;
//     std::cout << "Database Port: " << dbPort << std::endl;

//     // Use the database details in your application (e.g., connect to PostgreSQL)

//     return 0;
// }


#include "dotenv.h"

std::unordered_map<std::string, std::string> loadEnvFile(const std::string& filepath) {
    std::unordered_map<std::string, std::string> envVars;
    std::ifstream envFile(filepath);
    if (!envFile.is_open()) {
        std::cerr << "Error: Unable to open .env file at " << filepath << std::endl;
        return envVars;
    }

    std::string line;
    while (std::getline(envFile, line)) {
        // Ignore comments and empty lines
        if (line.empty() || line[0] == '#') continue;

        // Find the position of the '=' character
        size_t delimiterPos = line.find('=');
        if (delimiterPos == std::string::npos) continue; // Skip invalid lines

        // Extract the key and value
        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);

        // Remove surrounding whitespace
        key.erase(0, key.find_first_not_of(" \t"));
        key.erase(key.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);

        // Store in map or set as an environment variable
        envVars[key] = value;
    }

    envFile.close();
    return envVars;
}