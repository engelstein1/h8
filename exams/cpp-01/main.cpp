#include "spaceStationManagement.hpp"


using namespace std;

int main() {
    SpaceStationManager manager;
    int choice = 0;

    while (true) {
        cout << "--------------------------" << endl;
        cout << "MAIN MENU" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Add Robot" << endl;
        cout << "2. Issue Commands to Robot" << endl;
        cout << "3. Quit" << endl;
        cout << "--------------------------" << endl;
        cout << "Enter your choice: "<< endl;
        cin >> choice ;

        switch (choice) {
            case 1:
                manager.addRobot();
                break;
            case 2:
                manager.issueCommandsToRobot();
                break;
            case 3:
                cout << "Exiting program." << endl;
                return 0; 
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}







