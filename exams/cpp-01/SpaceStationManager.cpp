#include "spaceStationManagement.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void SpaceStationManager::addRobot()
{
    cout << "Enter robot name: ";
    string name;
    cin >> name;

    cout << "Choose robot model from the list of supported models:" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (const auto &model : supportedModels)
    {
        cout << "- " << model << endl;
    }
    string model;
    cin >> model;

    cout << "Enter robot callsign ID: ";
    string callsignID;
    cin >> callsignID;

    RobotState status;
    if (rand() % 10 < 8)
    {
        status = RobotState::FAILING;
    }
    else
    {
        status = RobotState::FAILING;
    }

    Robot *newRobot = nullptr;

    if (model == "HAL900")
    {
        newRobot = new HAL900(name, callsignID, status);
    }
    else if (model == "Tachikomas")
    {
        newRobot = new Tachikomas(name, callsignID, status);
    }
    else if (model == "Johnny5")
    {
        newRobot = new Johnny5(name, callsignID, status);
    }
    else if (model == "Machinenmensch")
    {
        newRobot = new Machinenmensch(name, callsignID, status);
    }
    else
    {
        cout << "Unsupported model selected." << endl;
        return;
    }

    robots.push_back(newRobot);

    cout << "New robot properties:" << endl;
    cout << "Name: " << name << endl;
    cout << "Model: " << model << endl;
    cout << "Callsign ID: " << callsignID << endl;
    if (status == RobotState::ACTIVE)
    {
        cout << "State: "
             << "ACTIVE" << endl;
    }
    else
    {
        cout << "State: "
             << "FAILING" << endl;
    }
}

void SpaceStationManager::issueCommandsToRobot()
{
    cout << "Available robots:" << endl;
    for (const auto &robot : robots)
    {
        cout << "- " << robot->getCallsignID() << endl;
    }

    cout << "Enter the callsign ID of the robot you want to issue commands to: ";
    string selectedCallsign;
    cin >> selectedCallsign;

    Robot *selectedRobot = nullptr;
    for (const auto &robot : robots)
    {
        if (robot->getCallsignID() == selectedCallsign)
        {
            selectedRobot = robot;
            break;
        }
    }

    if (selectedRobot == nullptr)
    {
        cout << "Robot with callsign ID '" << selectedCallsign << "' not found." << endl;
        return;
    }

    cout << "Selected robot details:" << endl;
    cout << "Name: " << selectedRobot->getName() << endl;
    cout << "Model: " << selectedRobot->getModel() << endl;
    cout << "Callsign ID: " << selectedRobot->getCallsignID() << endl;

    cout << "Choose an action:" << endl;
    cout << "1. Dispatch" << endl;
    cout << "2. Reboot" << endl;
    cout << "3. Self-Diagnostics" << endl;
    cout << "4. Delete" << endl;
    cout << "5. Back to main menu" << endl;

    int action;
    cout << "Enter your choice: ";
    cin >> action;

    switch (action)
    {
    case 1:
        selectedRobot->dispatch();
        break;
    case 2:
        selectedRobot->rebooting();
        break;
    case 3:
        selectedRobot->selfDiagnostics();
        break;
    case 4:
    for (auto it = robots.begin(); it != robots.end(); ++it) {
        if (*it == selectedRobot) {
            delete *it; 
            robots.erase(it);
            break;
        }
    }
    cout << "Robot deleted." << endl;
        break;
    case 5:
         
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}