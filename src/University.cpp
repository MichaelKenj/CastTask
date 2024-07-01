#include "../headers/University.h"

void University::addCourse(const Course& course)
{
    courses.push_back(course);
}

void University::addInstructor(const Instructor& instructor)
{
    instructors.push_back(instructor);
}

void University::addTimeSlot(const TimeSlot& timeSlot)
{
    timeSlots.push_back(timeSlot);
}

void University::saveState(const std::string& filename)
{
    json j;
    j["courses"] = json::array();
    for (const auto& course : courses)
    {
        json jc;
        jc["courseName"] = course.courseName;
        jc["preferredTimeSlots"] = json::array();
        for (const auto& ts : course.preferredTimeSlots)
        {
            jc["preferredTimeSlots"].push_back({ {"day", ts.day}, {"startTime", ts.startTime}, {"endTime", ts.endTime} });
        }
        j["courses"].push_back(jc);
    }

    j["instructors"] = json::array();
    for (const auto& instructor : instructors)
    {
        json ji;
        ji["name"] = instructor.name;
        ji["availability"] = json::array();
        for (const auto& ts : instructor.availability)
        {
            ji["availability"].push_back({ {"day", ts.day}, {"startTime", ts.startTime}, {"endTime", ts.endTime} });
        }
        ji["preferredCourses"] = json::array();
        for (const auto& course : instructor.preferredCourses)
        {
            ji["preferredCourses"].push_back({ {"courseName", course.courseName} });
        }
        j["instructors"].push_back(ji);
    }

    j["timeSlots"] = json::array();
    for (const auto& ts : timeSlots)
    {
        j["timeSlots"].push_back({ {"day", ts.day}, {"startTime", ts.startTime}, {"endTime", ts.endTime} });
    }

    std::ofstream file(filename);
    file << j.dump(4);
    file.close();
}

void University::loadState(const std::string& filename)
{
    std::ifstream file(filename);
    json j;
    file >> j;

    courses.clear();
    for (const auto& jc : j["courses"])
    {
        std::vector<TimeSlot> preferredTimeSlots;
        for (const auto& ts : jc["preferredTimeSlots"])
        {
            preferredTimeSlots.push_back(TimeSlot(ts["day"], ts["startTime"], ts["endTime"]));
        }
        courses.push_back(Course(jc["courseName"], preferredTimeSlots));
    }

    instructors.clear();
    for (const auto& ji : j["instructors"])
    {
        std::vector<TimeSlot> availability;
        for (const auto& ts : ji["availability"])
        {
            availability.push_back(TimeSlot(ts["day"], ts["startTime"], ts["endTime"]));
        }
        std::vector<Course> preferredCourses;
        for (const auto& jc : ji["preferredCourses"])
        {
            // We will not have the full Course object here, just a placeholder
            preferredCourses.push_back(Course(jc["courseName"], {}));
        }
        instructors.push_back(Instructor(ji["name"], availability, preferredCourses));
    }

    timeSlots.clear();
    for (const auto& ts : j["timeSlots"])
    {
        timeSlots.push_back(TimeSlot(ts["day"], ts["startTime"], ts["endTime"]));
    }
}

void University::schedule()
{
    // Implement a basic scheduling algorithm to meet the constraints
    std::vector<std::tuple<Instructor, Course, TimeSlot>> timetable;

    for (const auto& course : courses)
    {
        for (const auto& instructor : instructors)
        {
            for (const auto& timeSlot : timeSlots)
            {
                // Check if the instructor is available during this time slot
                auto it = std::find_if(instructor.availability.begin(), instructor.availability.end(),
                    [&timeSlot](const TimeSlot& ts) {
                        return ts.day == timeSlot.day && ts.startTime == timeSlot.startTime && ts.endTime == timeSlot.endTime;
                    });

                // Check if the instructor is not already scheduled at this time slot
                auto scheduled = std::find_if(timetable.begin(), timetable.end(),
                    [&timeSlot, &instructor](const std::tuple<Instructor, Course, TimeSlot>& entry)
                    {
                        return std::get<0>(entry).name == instructor.name && std::get<2>(entry).day == timeSlot.day &&
                            std::get<2>(entry).startTime == timeSlot.startTime && std::get<2>(entry).endTime == timeSlot.endTime;
                    });

                if (it != instructor.availability.end() && scheduled == timetable.end())
                {
                    timetable.push_back(std::make_tuple(instructor, course, timeSlot));
                    break;
                }
            }
        }
    }

    // Print the timetable
    for (const auto& entry : timetable)
    {
        std::cout << "Instructor: " << std::get<0>(entry).name << " is assigned to Course: "
            << std::get<1>(entry).courseName
            << " during " << std::get<2>(entry).day << " " << std::get<2>(entry).startTime << " - "
            << std::get<2>(entry).endTime << std::endl;
    }
}