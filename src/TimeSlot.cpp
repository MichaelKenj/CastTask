#include "../headers/TimeSlot.h"

TimeSlot::TimeSlot(std::string day, std::string startTime, std::string endTime) : 
	day(day), startTime(startTime), endTime(endTime)
{}

void TimeSlot::displayInfo() const
{
    std::cout << "Day: " << day << ", Start Time: " << startTime << ", End Time: " << endTime << std::endl;
}