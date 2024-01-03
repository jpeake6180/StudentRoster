#include "Student.h"

Student::Student()
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysArrayLen; i++) { this->numDaysToComplete[i] = 0; }
	this->degreeProgram;
}

Student::Student(std::string studentId, 
	std::string firstName, 
	std::string lastName, 
	std::string emailAddress, 
	int age, 
	int numDaysToComplete[], 
	DegreeProgram degreeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArrayLen; i++) { this->numDaysToComplete[i] = numDaysToComplete[i]; }
	this->degreeProgram = degreeProgram;

}

Student::~Student() {}

// Getters
std::string Student::getId() { return this->studentId; }
std::string Student::getfName() { return this->firstName; }
std::string Student::getlName() { return this->lastName; }
std::string Student::getEmail() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysToComplete() { return this->numDaysToComplete; }
DegreeProgram Student::getDegree() { return this->degreeProgram; }

// Setters
void Student::setId(std::string id) { this->studentId = id; }
void Student::setfName(std::string fName) { this->firstName = fName; }
void Student::setlName(std::string lName) { this->lastName = lName; }
void Student::setEmail(std::string email) { this->emailAddress = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[])
{
	for (int i = 0; i < daysArrayLen; i++) { this->numDaysToComplete[i] = days[i]; }
}
void Student::setDegree(DegreeProgram degree) { this->degreeProgram = degree; }

// Printer
void Student::Print()
{
	std::cout << this->getId() << '\t';
	std::cout << "First Name: " << this->getfName() << '\t';
	std::cout << "Last Name: " << this->getlName() << '\t';
	std::cout << "Age: " << this->getAge() << '\t';
	std::cout << "daysInCourse: { " << this->getDaysToComplete()[0] << ", " << this->getDaysToComplete()[1] << ", " << this->getDaysToComplete()[2] << " }" << '\t';
	std::cout << "Degree Program: " << degreeString[this->getDegree()] << std::endl;
}
