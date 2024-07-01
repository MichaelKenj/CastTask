#include "../headers/Course.h"

Course::Course(std::string courseName, std::vector<TimeSlot> preferredTimeSlots)
    : courseName(courseName), preferredTimeSlots(preferredTimeSlots)
{}

void Course::displayInfo() const
{
    std::cout << "Course Name: " << courseName << std::endl;
    std::cout << "Preferred Time Slots: " << std::endl;
    for (const auto& ts : preferredTimeSlots) 
    {
        ts.displayInfo();
    }
}