#include "include/appwindow.h"
#include "include/timerPresenter.h"
#include <QApplication>
#include <QString>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iostream>
#include <limits>

#define DEFAULT_WORK_TIME 25*60
#define DEFAULT_REST_TIME 5*60

bool parseConfig(const std::string& filename, unsigned& workTime, unsigned& restTime) {
    std::ifstream file(filename);
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

    if (config.find("work") == config.end() || config.find("rest") == config.end()) {
        return false;
    }

    workTime = static_cast<unsigned>(config["work"]) * 60;
    restTime = static_cast<unsigned>(config["rest"]) * 60;
    return true;
}

std::string getHomeConfigPath() {
    const char* home = std::getenv("HOME");
    if (!home) {
        //для винды
        home = std::getenv("USERPROFILE");
    }
    return std::string(home) + "/.pomodoro";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppWindow w;
    w.resize(300, 400);
    w.setWindowTitle("Pomodoro");

    unsigned workTime = DEFAULT_WORK_TIME;
    unsigned restTime = DEFAULT_REST_TIME;

    parseConfig(getHomeConfigPath(), workTime, restTime);

    w.run(workTime, restTime);
    w.show();
    return a.exec();
}
