
#include "Station.hpp"
#include "Platform.hpp"
#include "Line.hpp"
#include <iostream>

int main() {
    // Create stations with different ID types
    IntegerStation* station1 = new IntegerStation(1001);
    StringStation* station2 = new StringStation("CST");
    
    // Create platforms with different types
    Platform* platform1 = new Platform(1, 600, 630, false);  // 10:00-10:30, not through
    Platform* platform2 = new Platform(2, 615, 625, true);   // 10:15-10:25, through
    
    // Add platforms to stations
    station1->addPlatform(platform1);
    station2->addPlatform(platform2);
    
    // Create a line and add stations
    Line* line = new Line("Western");
    line->addStation(station1);
    line->addStation(station2);
    
    // Some example usage
    /*int id = station1->getID();               // Get integer station ID
    const char* name = station2->getID();     // Get string station ID
    const char* lineName = line->getName();   // Get line name
    int count = line->getStationCount();  */    // Get number of stations

    int id = station1->getID();
    std::cout << "Station 1 ID: " << id << std::endl;

    const char* name = station2->getID();
    std::cout << "Station 2 ID: " << name << std::endl;

    const char* lineName = line->getName();
    std::cout << "Line Name: " << lineName << std::endl;

    int count = line->getStationCount();
    std::cout << "Number of Stations: " << count << std::endl;

    
    // Cleanup
    delete line;
    delete station1;
    delete station2;
    
    return 0;
}