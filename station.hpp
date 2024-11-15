// Station.h
#ifndef STATION_HPP
#define STATION_HPP

class Platform;

class Station {
protected:
    Platform** platforms;  // Array of platform pointers
    int platformCount;
    int maxPlatforms;

public:
    Station(int maxPlatformCount = 10);
    virtual ~Station();
    
    bool addPlatform(Platform* platform);
    virtual void displayID() const = 0;  // Pure virtual function
};

class IntegerStation : public Station {
private:
    int stationId;

public:
    IntegerStation(int id, int maxPlatforms = 10);
    void displayID() const override;
    int getID() const { return stationId; }
};

class StringStation : public Station {
private:
    char* stationId;

public:
    StringStation(const char* id, int maxPlatforms = 10);
    ~StringStation();
    void displayID() const override;
    const char* getID() const { return stationId; }
};

#endif