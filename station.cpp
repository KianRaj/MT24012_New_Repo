
#include "Station.hpp"
#include "Platform.hpp"
#include <cstring>

// Base Station Implementation
Station::Station(int maxPlatformCount) 
    : platformCount(0), maxPlatforms(maxPlatformCount) {
    platforms = new Platform*[maxPlatforms];
    for(int i = 0; i < maxPlatforms; i++) {
        platforms[i] = nullptr;
    }
}

Station::~Station() {
    for(int i = 0; i < platformCount; i++) {
        delete platforms[i];
    }
    delete[] platforms;
}

bool Station::addPlatform(Platform* platform) {
    if (platformCount >= maxPlatforms) {
        return false;
    }
    platforms[platformCount++] = platform;
    return true;
}

// Integer Station Implementation
IntegerStation::IntegerStation(int id, int maxPlatforms) 
    : Station(maxPlatforms), stationId(id) {}

void IntegerStation::displayID() const {
    // In a real implementation, you'd want to handle output properly
    // For now, we'll just access the ID
    getID();
}

// String Station Implementation
StringStation::StringStation(const char* id, int maxPlatforms) 
    : Station(maxPlatforms) {
    stationId = new char[strlen(id) + 1];
    strcpy(stationId, id);
}

StringStation::~StringStation() {
    delete[] stationId;
}

void StringStation::displayID() const {
    // In a real implementation, you'd want to handle output properly
    // For now, we'll just access the ID
    getID();
}