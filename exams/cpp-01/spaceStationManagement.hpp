#include <string>
#include <vector>
#include <iostream>

class Robot{};

class SpaceStationManager
{
public:
    SpaceStationManager();
    ~SpaceStationManager();
    Robot addRobot();
protected:
    std::vector<Robot> robots;
    const std::vector<std::string> supportedModels = {"HAL900", "Tachikomas", "Johnny5","Machinenmensch"};
};





