
#ifndef LINE_HPP
#define LINE_HPP

class Station;

class Line {
private:
    char* lineName;
    Station** stations;  // Array of station pointers
    int stationCount;
    int maxStations;

public:
    Line(const char* name, int maxStationCount = 10);
    ~Line();
    
    bool addStation(Station* station);
    const char* getName() const { return lineName; }
    int getStationCount() const { return stationCount; }
};

#endif