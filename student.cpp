#include <iostream>
#include "student.h"

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse[0] = 0;
	this->daysInCourse[1] = 0;
	this->daysInCourse[2] = 0;
	this->degreeProgram;
}

Student::~Student()
{
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
	this->degreeProgram = degreeProgram;
}

void Student::SetStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::SetLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::SetEmail(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3)
{
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

string Student::GetStudentID() const
{
	return this->studentID;
}

string Student::GetFirstName() const
{
	return this->firstName;
}

string Student::GetLastName() const
{
	return this->lastName;
}

string Student::GetEmail() const
{
	return this->emailAddress;
}

int Student::GetDaysInCourse(int coursePosition) const
{
	return this->daysInCourse[coursePosition];
}

int Student::GetDegreeProgram() const
{
	return this->degreeProgram;
}

void Student::Print() const
{
	cout << this->studentID << "\t";
	cout << "First name: " << this->firstName << "\t";
	cout << "Last name: " << this->lastName << "\t";
	cout << "Age: " << this->age << "\t\t";
	cout << "Days in course: {";
	cout << this->daysInCourse[0] << ", ";
	cout << this->daysInCourse[1] << ", ";
	cout << this->daysInCourse[2];
	cout << "}" << "\t";
	cout << "Degree Program: ";
	switch (this->degreeProgram)
	{
	case 0:
		cout << "SECURITY";
		break;
	case 1:
		cout << "NETWORK";
		break;
	case 2:
		cout << "SOFTWARE";
		break;
	default:
		cout << "UNKNOWN";
		break;
	}

	cout << endl;
}
