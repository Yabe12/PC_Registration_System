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
       
        if (line.empty() || line[0] == '#') continue;

   
        size_t delimiterPos = line.find('=');
        if (delimiterPos == std::string::npos) continue; 

      
        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);

        key.erase(0, key.find_first_not_of(" \t"));
        key.erase(key.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);


        envVars[key] = value;
    }

    envFile.close();
    return envVars;
}
