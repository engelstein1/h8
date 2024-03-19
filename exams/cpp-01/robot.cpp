#include "robot.hpp"

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

void Robot::performWork()
{
    for (auto tool : getTools())
    {
        tool->use(); // Use the tool
        if (tool->getState() == ToolState::MALFUNCTION)
        {
            failing();
            setState(RobotState::FAILING); // Update robot state if tool malfunctions
            break;                         // Stop work if a tool malfunctions
        }
    }
}

void Robot::dispatch()
{
    if (getState() != RobotState::ACTIVE)
    {
        std::cout << "Robot " << getName() << " is not active" << std::endl;
        return;
    }
    performWork();

    working();

    int shiftDuration = rand() % 151 + 30;
    std::cout << "Duty shift cycle duration: " << shiftDuration << " seconds" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(shiftDuration));
    active();
    std::cout << "Robot " << getName() << " is back in active duty " << getModel() << std::endl;
}

void Robot::rebooting()
{
    reboot();
    int rebootDuration = rand() % 5 + 1;
    std::cout << "Reboot duration: " << rebootDuration << " seconds" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(rebootDuration));
    active();
}

void Robot::selfDiagnostics()
{
    if (this->getState() != RobotState::FAILING)
    {
        cout << "Self-diagnostics can only be performed when the robot is in a FAILING state." << endl;
        return;
    }

    for (auto &tool : this->getTools())
    {
        if (tool->getState() == ToolState::MALFUNCTION)
        {
            cout << "Starting self-healing on tool " << tool->getName() << "..." << endl;

            int selfHealingTime = rand() % 11 + 10; 
            std::cout << "Self-healing duration: " << selfHealingTime << " seconds" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(selfHealingTime));

            if (rand() % 10 < 9)
            {
                cout << "Self-healing on tool " << tool->getName() << " completed successfully." << endl;
                tool->setState(ToolState::READY);
            }
            else
            {
                cout << "Self-healing on tool " << tool->getName() << " failed." << endl;
            }
        }
    }
}

HAL900::HAL900(std::string const &name, std::string const &callsign, RobotState status)
    : m_name(name)
    , m_model("HAL900")
    , m_callsignID(callsign)
    , m_status(status)
{
    m_tools.push_back(new LaserCutter);
    m_tools.push_back(new Disruptor);
    m_tools.push_back(new Replicator);
}

void HAL900::active()
{
    std::cout << "HAL900 is now active" << std::endl;
    m_status = RobotState::ACTIVE;
}

void HAL900::reboot()
{
    std::cout << "HAL900 is rebooting" << std::endl;
    m_status = RobotState::REBOOTING;
}

void HAL900::working()
{
    std::cout << "HAL900 is working" << std::endl;
    m_status = RobotState::WORKING;
}

void HAL900::failing()
{
    std::cout << "HAL900 has encountered a failure" << std::endl;
    m_status = RobotState::FAILING;
}

Tachikomas::Tachikomas(std::string const &name, std::string const &callsign, RobotState status)
    : m_name(name)
    , m_model("Tachikomas")
    , m_callsignID(callsign)
    , m_status(status)
{
    m_tools.push_back(new LaserCutter);
    m_tools.push_back(new Disruptor);
}

void Tachikomas::active()
{
    std::cout << "Tachikomas is now active" << std::endl;
    m_status = RobotState::ACTIVE;
}

void Tachikomas::reboot()
{
    std::cout << "Tachikomas is rebooting" << std::endl;
    m_status = RobotState::REBOOTING;
}

void Tachikomas::working()
{
    std::cout << "Tachikomas is working" << std::endl;
    m_status = RobotState::WORKING;
}

void Tachikomas::failing()
{
    std::cout << "Tachikomas has encountered a failure" << std::endl;
    m_status = RobotState::FAILING;
}

Johnny5::Johnny5(std::string const &name, std::string const &callsign, RobotState status)
    : m_name(name)
    , m_model("Johnny5")
    , m_callsignID(callsign)
    , m_status(status)
{
    m_tools.push_back(new LaserCutter);
    m_tools.push_back(new StaticBrush);
}

void Johnny5::active()
{
    std::cout << "Johnny5 is now active" << std::endl;
    m_status = RobotState::ACTIVE;
}

void Johnny5::reboot()
{
    std::cout << "Johnny5 is rebooting" << std::endl;
    m_status = RobotState::REBOOTING;
}

void Johnny5::working()
{
    std::cout << "Johnny5 is working" << std::endl;
    m_status = RobotState::WORKING;
}

void Johnny5::failing()
{
    std::cout << "Johnny5 has encountered a failure" << std::endl;
    m_status = RobotState::FAILING;
}

Machinenmensch::Machinenmensch(std::string const &name, std::string const &callsign, RobotState status)
    : m_name(name)
    , m_model("Machinenmensch")
    , m_callsignID(callsign)
    , m_status(status)
{
    m_tools.push_back(new Disruptor);
    m_tools.push_back(new Replicator);
}

void Machinenmensch::active()
{
    std::cout << "Machinenmensch is now active" << std::endl;
    m_status = RobotState::ACTIVE;
}

void Machinenmensch::reboot()
{
    std::cout << "Machinenmensch is rebooting" << std::endl;
    m_status = RobotState::REBOOTING;
}

void Machinenmensch::working()
{
    std::cout << "Machinenmensch is working" << std::endl;
    m_status = RobotState::WORKING;
}

void Machinenmensch::failing()
{
    std::cout << "Machinenmensch has encountered a failure" << std::endl;
    m_status = RobotState::FAILING;
}