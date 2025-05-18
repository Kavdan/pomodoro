#include "include/configLoader.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>

bool ConfigLoader::parseConfig(unsigned int &workTime, unsigned int &restTime) {
  std::ifstream file(ConfigLoader::getHomeConfigPath() );
  if (!file.is_open()) {
    std::cerr << "Failed while opening file!";
    return false;
  }

  std::string line;
  std::map<std::string, int> config;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string key, valueStr;
    if (std::getline(iss, key, '=') && std::getline(iss, valueStr)) {
      try {
        int value = std::stoi(valueStr);
        if (value <= 0 || value > 60) {
          return false;
        }
        config[key] = value;
      } catch (...) {
        std::cerr << "Invalid integer in config: " << valueStr << "\n";
        return false;
      }
    }
  }

  if (config.find("work") == config.end() ||
      config.find("rest") == config.end()) {
    return false;
  }

  workTime = static_cast<unsigned>(config["work"]) * 60;
  restTime = static_cast<unsigned>(config["rest"]) * 60;
  return true;
}

std::string ConfigLoader::getHomeConfigPath() {
  const char *home = std::getenv("HOME");
  if (!home) {
    home = std::getenv("USERPROFILE");
  }
  return std::string(home) + "/.pomodoro";
}
