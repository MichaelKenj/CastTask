
# CastTask

Assignment: University Timetabling System
This assignment aims to design and implement a program that schedules courses for a university while assigning instructors to each course based on their availability and expertise. This will involve creating classes to represent courses and instructors, as well as implementing an algorithm to schedule a timetable. Exact, heuristic, or hybrid methods can be used for scheduling. The solution should be as optimal as possible. Incomplete solutions are also acceptable.

## Class Structure:

Implement the following classes:

  TimeSlot: Represents a time slot for scheduling courses
  
  Course: Represents a course that needs to be scheduled
  
  Instructor: Represents an instructor who can teach courses and has specific availability
  
  University: Represents the combination of courses, instructors, and time slots
  
Each class should have appropriate attributes and methods to manage the relationships.
Attributes:
  TimeSlot: day (string), startTime (string), endTime (string)
  Course: courseName (string), preferredTimeSlots (list of TimeSlot objects)
  Instructor: name (string), availability (list of TimeSlot objects), preferredCourses (list of Course objects)
  University: courses (list of Course objects), instructors (list of Instructor objects), timeSlots (list of TimeSlot objects)
Methods:
  TimeSlot:
    displayInfo: print time slot information
  Course:
    displayInfo: print course information
  Instructor:
    displayInfo: print instructor information
  University:
    addCourse: add a course to the university object
    addInstructor: add an instructor to the university object
    addTimeSlot: add a time slot to the university object
    saveState: save the state of the university in the file with a JSON format
    loadState: load the state of the university from the file with a JSON format
    schedule: return a correct scheduled timetable
Scheduling Constraints:
The scheduling algorithm must satisfy all hard constraints and as many soft constraints as possible.
Hard constraints:
    Each course must be scheduled exactly once in an available time slot and assigned to an instructor
    An instructor can only be assigned to a course if they are available during the corresponding time slot
    An instructor cannot be scheduled to teach more than one course in the same time slot

Soft constraints:
Courses should be scheduled in preferred time slots if possible
Instructors should be assigned to their preferred courses if possible 
Testing:
Please include test examples that we can use to verify the functionality of your code as part of your assignment submission.
