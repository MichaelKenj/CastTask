#pragma once
#include "Instructor.h"
#include "Course.h"
#include "TimeSlot.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

class University {
private:
    std::vector<Course> courses;
    std::vector<Instructor> instructors;
    std::vector<TimeSlot> timeSlots;

public:
    void addCourse(const Course& course);

    void addInstructor(const Instructor& instructor);

    void addTimeSlot(const TimeSlot& timeSlot);

    void saveState(const std::string& filename);

    void loadState(const std::string& filename);

    void schedule();
};
