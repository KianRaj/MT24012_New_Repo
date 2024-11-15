
#include "Platform.hpp"

Platform::Platform(int number, int arrival, int departure, bool through) 
    : platformNumber(number), arrivalTime(arrival), 
      departureTime(departure), isThrough(through) {}

bool Platform::isTimeSlotAvailable(int requestedTime) const {
    // Check if the requested time conflicts with existing schedule
    int minGap = isThrough ? 10 : 30;  // minutes
    
    if (requestedTime < arrivalTime - minGap || requestedTime > departureTime + minGap) {
        return true;
    }
    return false;
}
