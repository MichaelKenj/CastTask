#include "../headers/Instructor.h"

Instructor::Instructor(std::string name, std::vector<TimeSlot> availability, std::vector<Course> preferredCourses)
    : name(name), availability(availability), preferredCourses(preferredCourses) 
{}

void Instructor::displayInfo() const
{
    std::cout << "Instructor Name: " << name << std::endl;
    std::cout << "Availability: " << std::endl;
    for (const auto& ts : availability) {
        ts.displayInfo();
    }
    std::cout << "Preferred Courses: " << std::endl;
    for (const auto& course : preferredCourses) {
        course.displayInfo();
    }
}