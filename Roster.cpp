#include "Roster.h"

Roster::Roster() 
{ 
	std::cout << "--Creating Roster--\n" << std::endl;
}

Roster::~Roster()
{
	std::cout << "\n--Destroying Roster--" << std::endl;
}

//Extracts data from an element in studentDataTable
void Roster::parse(std::string row)
{
	int rhs = row.find(",");
	std::string studentId = row.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string emailAddress = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int numDaysToComplete1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int numDaysToComplete2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int numDaysToComplete3 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string degree = row.substr(lhs, rhs - lhs);
	DegreeProgram degreeProgram;
	if (degree == "SECURITY") { degreeProgram = SECURITY; }
	else if (degree == "NETWORK") { degreeProgram = NETWORK; }
	else degreeProgram = SOFTWARE;

	this->add(studentId,
		firstName,
		lastName,
		emailAddress,
		age,
		numDaysToComplete1,
		numDaysToComplete2,
		numDaysToComplete3,
		degreeProgram);
}

//Creates student object and places it in classRosterArray
void Roster::add(std::string studentId,
	std::string firstName,
	std::string lastName,
	std::string emailAddress,
	int age,
	int numDaysToComplete1,
	int numDaysToComplete2,
	int numDaysToComplete3,
	DegreeProgram degreeProgram)
{
	int numDaysToComplete[3] = { numDaysToComplete1, numDaysToComplete2, numDaysToComplete3 };

	classRosterArray[++lastIndex] = new Student(studentId,
		firstName,
		lastName,
		emailAddress,
		age,
		numDaysToComplete,
		degreeProgram);
}

//Removes student from classRosterArray
void Roster::remove(std::string studentId)
{
	bool validId = false;
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i] == nullptr) { break; }
		else if (classRosterArray[i]->getId() == studentId)
		{ 
			classRosterArray[i] = nullptr; 
			validId = true;
			std::cout << "Removing Student: " << studentId << std::endl;
		}
	}
	if (!(validId)) { std::cout << "Error: StudentId is Invalid" << std::endl; }
}

//Calls Print() for each student in classRosterArray
void Roster::printAll()
{
	for (int i = 0; i <= lastIndex; i++) 
	{ 
		if (classRosterArray[i] != nullptr) { classRosterArray[i]->Print(); }
	}
}

//Prints a student's average number of days in the three courses
void Roster::printAverageDaysInCourse(std::string studentId)
{
	for (int i = 0; i <= lastIndex; i++)
	{
		if (classRosterArray[i] == nullptr) { continue; }
		else if (classRosterArray[i]->getId() == studentId)
		{
			int averageDays = 0;
			int numCourses = 0;
			for (int j = 0; j < classRosterArray[i]->daysArrayLen; j++)
			{
				averageDays += classRosterArray[i]->getDaysToComplete()[j];
				numCourses += 1;
			}
			averageDays /= numCourses;
			std::cout << studentId << ": " << averageDays << std::endl;
		}
	}
}

//Prints all invalid email addresses
void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		if (classRosterArray[i] == nullptr) { continue; }
		else if (classRosterArray[i]->getEmail().find("@") == std::string::npos ||
			classRosterArray[i]->getEmail().find(".") == std::string::npos ||
			classRosterArray[i]->getEmail().find(" ") != std::string::npos)
		{
			std::cout << classRosterArray[i]->getEmail() << std::endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i <= lastIndex; i++)
	{
		if (classRosterArray[i] == nullptr) { continue; }
		else if (classRosterArray[i]->getDegree() == degreeProgram)
		{
			classRosterArray[i]->Print();
		}
	}
}
