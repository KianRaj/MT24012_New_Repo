

#include "Station.hpp"
#include "Platform.hpp"
#include "Line.hpp"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdexcept>  // For handling exceptions
#include <limits>  // For input validation

// Function to test adding stations and platforms
void testAddStationAndPlatform() {
    int stationId;
    char stationName[50];
    int stationType;

    try {
        std::cout << "Enter station ID (Integer) or Name (String):\n";
        std::cout << "Enter '1' for Integer Station or '2' for String Station: ";
        std::cin >> stationType;
        if (std::cin.fail()) throw std::invalid_argument("Invalid station type input.");

        Station* station;
        if (stationType == 1) {
            std::cout << "Enter Integer Station ID: ";
            std::cin >> stationId;
            if (std::cin.fail()) throw std::invalid_argument("Invalid station ID input.");
            station = new IntegerStation(stationId);
        } else if (stationType == 2) {
            std::cout << "Enter String Station Name: ";
            std::cin >> stationName;
            station = new StringStation(stationName);
        } else {
            throw std::invalid_argument("Invalid station type choice.");
        }

        Platform* platform1 = new Platform(1, 600, 630, false);  // 10:00-10:30, not through
        Platform* platform2 = new Platform(2, 615, 625, true);   // 10:15-10:25, through

        // Add platforms to station
        if (station->addPlatform(platform1)) {
            std::cout << "Platform 1 added successfully to station.\n";
        } else {
            std::cout << "Failed to add Platform 1 to station.\n";
        }

        if (station->addPlatform(platform2)) {
            std::cout << "Platform 2 added successfully to station.\n";
        } else {
            std::cout << "Failed to add Platform 2 to station.\n";
        }

        // Create a line and add the station
        Line* line = new Line("Western");
        if (line->addStation(station)) {
            std::cout << "Station added to line successfully.\n";
        } else {
            std::cout << "Failed to add Station to line.\n";
        }

        // Clean up
        delete line;
        delete station;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        // Clean up in case of error
        std::cin.clear();  // Clear input error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore bad input
    }
}

// Function to test if platform limit is exceeded
void testExceedPlatformLimit() {
    int stationId;
    try {
        std::cout << "Enter station ID to test platform limit: ";
        std::cin >> stationId;
        if (std::cin.fail()) throw std::invalid_argument("Invalid station ID input.");

        Station* station = new IntegerStation(stationId);

        Platform* platform1 = new Platform(1, 600, 630, false);  // Valid platform
        Platform* platform2 = new Platform(2, 615, 625, true);   // Another valid platform

        station->addPlatform(platform1);
        station->addPlatform(platform2);

        // Attempt to add more platforms than allowed
        Platform* platform3 = new Platform(3, 630, 660, false);  // Invalid, exceeds max
        if (!station->addPlatform(platform3)) {
            std::cout << "Failed to add more platforms than allowed.\n";
        }

        // Clean up
        delete station;
        delete platform1;
        delete platform2;
        delete platform3;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void testPlatformTimeAvailability() {
    int platformID, arrivalTime, departureTime;
    char isThroughChar;
    
    try {
        // Prompt for user input for platform availability check
        std::cout << "Enter platform ID, arrival time (minutes from midnight), departure time (minutes from midnight), and whether it's through (y/n):\n";
        std::cin >> platformID >> arrivalTime >> departureTime >> isThroughChar;

        if (std::cin.fail()) throw std::invalid_argument("Invalid input format for platform details.");

        // Check if platform is through (y/n)
        bool isThrough = (isThroughChar == 'y' || isThroughChar == 'Y');

        Platform* platform = new Platform(platformID, arrivalTime, departureTime, isThrough);

        int requestedTime;
        std::cout << "Enter requested time (in minutes from midnight): ";
        std::cin >> requestedTime;

        if (std::cin.fail()) throw std::invalid_argument("Invalid input format for requested time.");

        // Check availability for the requested time
        if (platform->isTimeSlotAvailable(requestedTime)) {
            std::cout << "Platform is available for the requested time.\n";
        } else {
            std::cout << "Platform is NOT available for the requested time.\n";
        }

        // Clean up
        delete platform;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void testInvalidStationID() {
    char stationName[50];

    try {
        std::cout << "Enter station name to test invalid ID: ";
        std::cin >> stationName;

        if (std::cin.fail()) throw std::invalid_argument("Invalid input for station name.");

        // Check if the input station name is valid
        if (stationName[0] == '\0') {
            std::cout << "Invalid station name: cannot be empty." << std::endl;
        } else {
            StringStation* invalidStation = new StringStation(stationName);
            std::cout << "Created station with ID: " << invalidStation->getID() << std::endl;
            delete invalidStation;  // Clean up
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    int choice;

    while (true) {
        try {
            // Menu options
            std::cout << "Choose a test to run:\n";
            std::cout << "1. Test Platform Time Availability\n";
            std::cout << "2. Test Add Station and Platform\n";
            std::cout << "3. Test Exceed Platform Limit\n";
            std::cout << "4. Test Invalid Station ID\n";
            std::cout << "5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (std::cin.fail()) throw std::invalid_argument("Invalid choice input.");

            switch (choice) {
                case 1:
                    testPlatformTimeAvailability();
                    break;
                case 2:
                    testAddStationAndPlatform();
                    break;
                case 3:
                    testExceedPlatformLimit();
                    break;
                case 4:
                    testInvalidStationID();
                    break;
                case 5:
                    std::cout << "Exiting program...\n";
                    return 0;  // Exit the program
                default:
                    std::cout << "Invalid choice, please try again.\n";
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}
