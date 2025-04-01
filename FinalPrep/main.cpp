#include <map>
#include <string>
#include <iostream>

map<int,map<string,string>> studentCourseEnrollment;
using namespace std;
// Function to add a course for a student
void addCourse(int studentID, const string& courseCode, const string& courseTitle) {
  studentCourseEnrollment[studentID][courseCode] = courseTitle;
  cout << "Added Course: " << courseTitle << " for Student " << studentID << endl;
}

// Function to enroll a student in a course
void enrollStudent(int studentID, const string& courseCode) 
{
  // Check if student exists in the system
  auto it = studentCourseEnrollment.find(studentID);
  if (it != studentCourseEnrollment.end()
  {
    auto it2 = studentCourseEnrollment[studentID].find(courseCode)!=studentCourseEnrollment[studentID].end());
    if (it2 != studentCourseEnrollment.end())
      {
        std::cout it -> first << it -> first -> first
      }
  }
}
int main() 
{
    // Adding courses for students
    addCourse(101, "CS101", "Intro to Computer Science");
    addCourse(101, "MATH201", "Calculus II");
    addCourse(102, "ENG150", "English Literature");

    // Enrolling students in courses
    enrollStudent(101, "CS101");   // Should print course details
    enrollStudent(101, "MATH201"); // Should print course details
    enrollStudent(102, "CS101");   // Should print "Course Not Found"
    enrollStudent(103, "ENG150");  // Should print "Student ID Not Found"

    return 0;
}