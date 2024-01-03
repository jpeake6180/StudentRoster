#pragma once

#include <iostream>
#include "Degree.h"

class Student
{
public:
	const static int daysArrayLen = 3;
private:
	std::string studentId;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int numDaysToComplete[daysArrayLen];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(std::string studentId, 
		std::string firstName, 
		std::string lastName, 
		std::string emailAddress, 
		int age, 
		int numDaysToComplete[], 
		DegreeProgram degreeProgram);
	~Student();

	// Getters
	std::string getId();
	std::string getfName();
	std::string getlName();
	std::string getEmail();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegree();

	// Setters
	void setId(std::string id);
	void setfName(std::string fName);
	void setlName(std::string lName);
	void setEmail(std::string email);
	void setAge(int age);
	void setDays(int days[]);
	void setDegree(DegreeProgram degree);

	// Print
	void Print();
};