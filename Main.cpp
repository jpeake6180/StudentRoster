#include <iostream>
#include "Student.h"
#include "Roster.h"

int main()
{
    std::cout << "Course Title: C867: Scripting and Programming - Applications" << std::endl;
    std::cout << "Programming Language Used: C++" << std::endl;
    std::cout << "Student ID: 010678004" << std::endl;
    std::cout << "Name: Jacob Peake\n" << std::endl;

    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jacob,Peake,jpeake2@wgu.edu,23,22,21,27,SOFTWARE"
    };

    Roster classRoster;
    
     for (int i = 0; i < sizeof(studentData) / sizeof(std::string); i++)
    {
        classRoster.parse(studentData[i]);
    }

    std::cout << "Current Class Roster:" << std::endl;
    classRoster.printAll();

    std::cout << "\nInvalid Email Addresses:" << std::endl;
    classRoster.printInvalidEmails();

    std::cout << "\nAverage Days in Course:" << std::endl;
    for (int i = 0; i < sizeof(studentData) / sizeof(std::string); i++)
    {
        std::string studentId = studentData[i].substr(0, 2);
        classRoster.printAverageDaysInCourse(studentId);
    }

    std::cout << "\nCurrent Software Students:" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    
    std::cout << '\n';
    classRoster.remove("A3");
    
    std::cout << "\nCurrent Class Roster:" << std::endl;
    classRoster.printAll();

    std::cout << '\n';
    classRoster.remove("A3");
    
    classRoster.~Roster();

	std::cin.get();
}