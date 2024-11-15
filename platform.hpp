

#ifndef PLATFORM_HPP
#define PLATFORM_HPP

class Platform {
private:
    int platformNumber;
    int arrivalTime;    // in minutes from midnight
    int departureTime;  // in minutes from midnight
    bool isThrough;     // true if it's a through train platform
    
public:
    Platform(int number, int arrival, int departure, bool through);
    bool isTimeSlotAvailable(int requestedTime) const;
    int getNumber() const { return platformNumber; }
    int getArrival() const { return arrivalTime; }
    int getDeparture() const { return departureTime; }
};

#endif