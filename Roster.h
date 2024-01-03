#pragma once

#include "Student.h"

class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];
public:
	Roster();
	~Roster();
	
	//Extracts data from an element in studentDataTable
	void parse(std::string row);

	//Creates student object and places it in classRosterArray
	void add(std::string studentId,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age,
		int numDaysToComplete1,
		int numDaysToComplete2,
		int numDaysToComplete3,
		DegreeProgram degreeProgram);

	//Removes student from classRosterArray
	void remove(std::string studentId);

	//Calls Print() for each student in classRosterArray
	void printAll();

	//Prints a student's average number of days in the three courses
	void printAverageDaysInCourse(std::string studentId);

	//Prints all invalid email addresses
	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);
};