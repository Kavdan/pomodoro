#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include <string>

class ConfigLoader {
public:
  static bool parseConfig(unsigned &workTime, unsigned &restTime);
  static std::string getHomeConfigPath();
};

#endif // CONFIGLOADER_H
