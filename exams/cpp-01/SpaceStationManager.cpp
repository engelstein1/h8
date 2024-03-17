#include "spaceStationManagement.hpp"
#include "robot.hpp"
#include "robot.cpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;






Robot SpaceStationManager::addRobot() {
    
    cout << "Enter robot name: ";
    string name;
    cin >> name;
    
    cout << "Choose robot model from the list of supported models:" << endl;
    for (const auto& model : supportedModels) {
        cout << "- " << model << endl;
    }
    string model;
    cin >> model;
    
    cout << "Enter robot callsign ID: ";
    string callsignID;
    cin >> callsignID;
    
    bool status;
    double successProbability = rand() / static_cast<double>(RAND_MAX);
    if (successProbability <= 0.8) {
        status = true;
    } else {
        status = false;
    }

    HAL900 newRobot(name, model, callsignID,status);
    
    robots.push_back(newRobot);
    
    cout << "New robot properties:" << endl;
    cout << "Name: " << name << endl;
    cout << "Model: " << model << endl;
    cout << "Callsign ID: " << callsignID << endl;
    if (status)
        {
            cout << "State: " << "ACTIVE" << endl;
            
        } else 
        {
           cout << "State: " << "FAILING" << endl; 
        }
    
    return newRobot;
}