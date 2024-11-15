

#include "Line.hpp"
#include "Station.hpp"
#include <cstring>

Line::Line(const char* name, int maxStationCount) 
    : stationCount(0), maxStations(maxStationCount) {
    lineName = new char[strlen(name) + 1];
    strcpy(lineName, name);
    
    stations = new Station*[maxStations];
    for(int i = 0; i < maxStations; i++) {
        stations[i] = nullptr;
    }
}

Line::~Line() {
    delete[] lineName;
    // Note: We don't delete the stations here as they might be shared
    // between lines. Memory management should be handled by the user program
    delete[] stations;
}

bool Line::addStation(Station* station) {
    if (stationCount >= maxStations) {
        return false;
    }
    stations[stationCount++] = station;
    return true;
}