#ifndef DOTENV_H
#define DOTENV_H

#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iostream>
#include <cstdlib>

// Function to load the .env file and store key-value pairs
std::unordered_map<std::string, std::string> loadEnvFile(const std::string& filepath);

#endif 