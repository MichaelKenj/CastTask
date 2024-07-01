#pragma once
#include <string>
#include "TimeSlot.h"
#include "Course.h"
#include <vector>

class Instructor {
public:
    std::string name;
    std::vector<TimeSlot> availability;
    std::vector<Course> preferredCourses;

    Instructor(std::string name, std::vector<TimeSlot> availability, std::vector<Course> preferredCourses);

    void displayInfo() const;
};
