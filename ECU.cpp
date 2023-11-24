#include <iostream>

class EngineControlUnit {
private:
    bool hydraulicJacksActivated;
    bool gripTiresActivated;
    bool infraredLightsActivated;

    void actuateHydraulicJacks() {
        hydraulicJacksActivated = !hydraulicJacksActivated;
        std::cout << "Hydraulic Jacks " << (hydraulicJacksActivated ? "activated" : "deactivated") << std::endl;

        if (hydraulicJacksActivated) {
            gripTiresActivated = false;
            std::cout << "Grip Tires deactivated." << std::endl;
        }
    }

    void actuateGripTires() {
        gripTiresActivated = !gripTiresActivated;
        std::cout << "Grip Tires " << (gripTiresActivated ? "activated" : "deactivated") << std::endl;

        if (gripTiresActivated) {
            hydraulicJacksActivated = false;
            std::cout << "Hydraulic Jacks deactivated." << std::endl;
        }
    }

    void actuateInfraredLights() {
        infraredLightsActivated = !infraredLightsActivated;
        std::cout << "Infrared Driving Lights " << (infraredLightsActivated ? "activated" : "deactivated") << std::endl;
    }

public:
    EngineControlUnit() : hydraulicJacksActivated(false), gripTiresActivated(false), infraredLightsActivated(false) {}

    ~EngineControlUnit() {
        std::cout << "ECU Shutdown" << std::endl;
    }

    void handleCommand(char button) {
        switch (button) {
            case 'A':
                actuateHydraulicJacks();
                break;
            case 'B':
                actuateGripTires();
                break;
            case 'E':
                actuateInfraredLights();
                break;
            default:
                std::cout << "Invalid command. Please press A, B, E, or X to turn off ignition." << std::endl;
        }
    }
};

int main() {
    EngineControlUnit ecu;

    while (true) {
        std::cout << "(A)" << std::endl;
        std::cout << "(B)" << std::endl;
        std::cout << "(E)" << std::endl;
        std::cout << "Press X to turn off ignition or enter a steering wheel button (A,B,E): ";
        char button;
        std::cin >> button;

        if (button == 'X') {
            break; 
        }

        ecu.handleCommand(button);
    }

    return 0;
}