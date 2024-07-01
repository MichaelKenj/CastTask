#pragma once
#include <string>
#include <vector>
#include "TimeSlot.h"

class Course {
public:
    std::string courseName;
    std::vector<TimeSlot> preferredTimeSlots;

    Course(std::string courseName, std::vector<TimeSlot> preferredTimeSlots);

    void displayInfo() const;
};
