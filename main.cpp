#include <iostream>
#include "headers/University.h"

int main() {
    // Create some sample data
    TimeSlot ts1("Monday", "09:00", "10:30");
    TimeSlot ts2("Wednesday", "11:00", "12:30");
    TimeSlot ts3("Friday", "14:00", "15:30");

    Course course1("Math", { ts1, ts2 });
    Course course2("Physics", { ts2, ts3 });

    Instructor instructor1("Dr. Smith", { ts1, ts3 }, { course1 });
    Instructor instructor2("Dr. Jones", { ts2 }, { course2 });

    University university;
    university.addTimeSlot(ts1);
    university.addTimeSlot(ts2);
    university.addTimeSlot(ts3);
    university.addCourse(course1);
    university.addCourse(course2);
    university.addInstructor(instructor1);
    university.addInstructor(instructor2);

    // Save state to file
    university.saveState("university.json");

    // Load state from file
    University university2;
    university2.loadState("university.json");

    // Schedule courses
    university2.schedule();

    return 0;
}