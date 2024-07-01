#pragma once
#include <string>
#include <iostream>

class TimeSlot {
public:
    std::string day;
    std::string startTime;
    std::string endTime;

    TimeSlot(std::string day, std::string startTime, std::string endTime);
        
    void displayInfo() const;
};
