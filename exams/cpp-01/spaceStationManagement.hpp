#include "robot.hpp"

#include <string>
#include <vector>
#include <iostream>



class SpaceStationManager
{
public:
    SpaceStationManager() = default;
    ~SpaceStationManager() = default;
    void addRobot();
    void issueCommandsToRobot();
    void quit();
    std::vector<Robot *> robots;
    const std::vector<std::string> supportedModels = {"HAL900", "Tachikomas", "Johnny5","Machinenmensch"};
};






